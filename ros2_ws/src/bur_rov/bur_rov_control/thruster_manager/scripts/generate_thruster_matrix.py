import yaml
import numpy as np
import enum
import os


class CoordinateSystems(enum.IntEnum):
    NED=0
    NWU=1
    ENU=2
def transform(matrix, coordinate_system_in=CoordinateSystems.ENU, coordinate_system_out=CoordinateSystems.ENU):
    if(coordinate_system_in==coordinate_system_out):
        return matrix
    
    T_ENU_to_NWU = np.array([[0, 1.0, 0],
                            [-1.0, 0, 0],
                            [0, 0, 1.0]])

    T_ENU_to_NED = np.array([[0, 1.0, 0],
                            [1.0, 0, 0],
                            [0, 0, -1.0]])

    T_NWU_to_ENU = np.linalg.inv(T_ENU_to_NWU)
    T_NED_to_ENU = np.linalg.inv(T_ENU_to_NED)
    T_NED_to_NWU = T_NED_to_ENU @ T_ENU_to_NWU
    T_NWU_to_NED = np.linalg.inv(T_NED_to_NWU)
    
    
    if(coordinate_system_in==CoordinateSystems.NED and coordinate_system_out==CoordinateSystems.ENU):
        matrix = (T_NED_to_ENU @ matrix.T).T
        return matrix
    if(coordinate_system_in==CoordinateSystems.NWU and coordinate_system_out==CoordinateSystems.ENU):
        matrix = (T_NWU_to_ENU @ matrix.T).T
        return matrix
    if(coordinate_system_in==CoordinateSystems.NED and coordinate_system_out==CoordinateSystems.NWU):
        matrix = (T_NED_to_NWU @ matrix.T).T
        return matrix
    if(coordinate_system_in==CoordinateSystems.ENU and coordinate_system_out==CoordinateSystems.NWU):
        matrix = (T_ENU_to_NWU @ matrix.T).T
        return matrix
    if(coordinate_system_in==CoordinateSystems.ENU and coordinate_system_out==CoordinateSystems.NED):
        matrix = (T_ENU_to_NED @ matrix.T).T
        return matrix
    if(coordinate_system_in==CoordinateSystems.NWU and coordinate_system_out==CoordinateSystems.NED):
        matrix = (T_NWU_to_NED @ matrix.T).T
        return matrix
# This calculates the mapping between force-torque to thruster allocations

# Can calculate using whatever coordinate system (NED, NWU, ENU), just be consistent
coordinate_system = CoordinateSystems.NED
filename = 'motor_force_config.yaml'
# Full path to the output file
output_path = os.path.join('src/bur_rov/bur_rov_control/thruster_manager/config', filename)
# Thruster locations (m) relative to CoM
# Location of center of mass from vehicle origin
CoM = np.array([0, 0, 0]) / 1000

# Units in mm
thruster_locations = np.array([
    [-368.79653, 256.83809, -38.1],
    [368.79653, 256.83809, -38.1],
    [-264.87636, 233.15, 35.71352],
    [264.87636, 233.15, 35.71352],
    [-264.87636, -233.15, 35.71352],
    [-368.79653, -256.83809, -38.1],
    [368.79653, -256.83809, -38.1],
    [264.87636, -233.15, 35.71352],
]) / 1000

# Prevents up/down thrusters from having nonzero surge/sway
thruster_locations[:, 2] = 0

deg = 45
s = np.sin(np.deg2rad(deg))
c = np.cos(np.deg2rad(deg))
thruster_orientations = np.array([
                                [-c, -s, 0],
                                [c, -s, 0],
                                [0, 0, 1],
                                [0, 0, -1],
                                [0, 0, -1],
                                [-c, s, 0],
                                [c, s, 0],
                                [0, 0, 1]
                                ])

CoM = transform(CoM, coordinate_system_in=coordinate_system, coordinate_system_out=CoordinateSystems.ENU)
thruster_locations = transform(thruster_locations, coordinate_system_in=coordinate_system, coordinate_system_out=CoordinateSystems.ENU)
thruster_orientations = transform(thruster_orientations, coordinate_system_in=coordinate_system, coordinate_system_out=CoordinateSystems.ENU)
print("thruster_locations\n", thruster_locations)
print("thruster orientations\n", thruster_orientations)

thruster_locations = thruster_locations - CoM
# Compute torques
Torque = np.cross(thruster_locations, thruster_orientations)
print("Torque\n", Torque)

# Stack to get Force-Torque conversion matrix
A = np.vstack((thruster_orientations.T, Torque.T))
Ainv = np.linalg.pinv(A)
Ainv = np.around(Ainv, 6)

print("A\n", A)
print("Ainv\n", Ainv)

# Convert numpy arrays to lists
Ainv = Ainv.tolist()

# Restructure the Ainv matrix into the desired format
motors_data = {}
print(len(Ainv))
for i in range(len(Ainv)):
    motor_data = {
        'surge': Ainv[i][0],
        'sway': Ainv[i][1],
        'heave': Ainv[i][2],
        'pitch': Ainv[i][3], # Note: not the usual order of roll-pitch-yaw
        'roll': Ainv[i][4],
        'yaw': Ainv[i][5]
    }
    motors_data[f'motor{i}'] = motor_data

yaml_data = {
    'thruster_manager': {
        'ros__parameters': {
            'max_force': 60.0,
            'max_torque': 40.0,
            'num_motors': len(Ainv),
            **motors_data
        }
    }
}

try:
    with open(output_path, 'w') as file:
        yaml.dump(yaml_data, file, default_flow_style=False)
    print("YAML file", filename, "has been generated.")
except Exception as e:
    print(f"Error generating YAML file: {e}")
