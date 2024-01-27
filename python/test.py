import numpy as np
import matplotlib.pyplot as plt
from scipy import signal

t = np.linspace(0, 2, 2 * 1000)

# Order in a, b, c, d
# units in hz, s
f = [30e3, 40e3, 25e3, 35e3]
offset = [0, 1.0, 0.5, 1.4]
period = 2.0
pulse_length = 4e-2

time_offset = [1, 0.5, 0.1]
heaviside = []
heaviside.append(np.heaviside(t, 0))
heaviside.append(np.heaviside(-t + pulse_length, 0))
sin = []
sin.append(np.sin(2 * np.pi * f[0] * t))

heaviside.append(np.heaviside(t - time_offset[0], 0))
heaviside.append(np.heaviside(-t + pulse_length + time_offset[0], 0))
sin.append(np.sin(2 * np.pi * f[0] * t + time_offset[0]))

heaviside.append(np.heaviside(t - time_offset[1], 0))
heaviside.append(np.heaviside(-t + pulse_length + time_offset[1], 0))
sin.append(np.sin(2 * np.pi * f[0] * t + time_offset[1]))

heaviside.append(np.heaviside(t - time_offset[2], 0))
heaviside.append(np.heaviside(-t + pulse_length + time_offset[2], 0))
sin.append(np.sin(2 * np.pi * f[0] * t + time_offset[2]))

hydrophones = [
    np.multiply(np.multiply(heaviside[0], heaviside[1]), sin[0]),
    np.multiply(np.multiply(heaviside[2], heaviside[3]), sin[1]),
    np.multiply(np.multiply(heaviside[4], heaviside[5]), sin[2]),
    np.multiply(np.multiply(heaviside[6], heaviside[7]), sin[3]),
]

plt.figure()
plt.plot(t, hydrophones[0], t, hydrophones[1], t, hydrophones[2], t, hydrophones[3])
plt.xlim(-0.1, 2)
plt.show()

plt.figure()
# compares two 1D arrays and returns an array, the greater the value, the higher correlation the signals have
output01 = signal.correlate(hydrophones[0], hydrophones[1], mode="full", method="fft")
output02 = signal.correlate(hydrophones[0], hydrophones[2], mode="full", method="fft")
output03 = signal.correlate(hydrophones[0], hydrophones[3], mode="full", method="fft")
plt.plot(output01)
plt.plot(output02)
plt.plot(output03)
plt.show()

# Finds the displacement between the two arrays, input arrays are 1d so the displacement is the number of indices to shift.
# If each of our data points are for example 1 ms apart then the result would be multiplied by 1ms to get the time difference

lags01 = signal.correlation_lags(len(hydrophones[0]), len(hydrophones[1]), mode="full")
lag01 = lags01[np.argmax(output01)]
lags02 = signal.correlation_lags(len(hydrophones[0]), len(hydrophones[2]), mode="full")
lag02 = lags02[np.argmax(output02)]
lags03 = signal.correlation_lags(len(hydrophones[0]), len(hydrophones[3]), mode="full")
lag03 = lags03[np.argmax(output03)]
print(lag01)
print(lag02)
print(lag03)


class Hydrophone:
    def __init__(self, x=0, y=0, z=0):
        self.x = x
        self.y = y
        self.z = z
        self.sample = []

    def get_coordinates(self):
        return np.array([[self.x, self.y, self.z]])

class HydrophoneArray:
    def __init__(self, origin_hydrophone, *hydrophones):
        self.origin = origin_hydrophone
        self.hydrophones = np.array(hydrophones)

    # measures how similar how one sound wave is two a second sound wave shifted by a facotr
    def autocorrelation(self, sample_a, sample_b, shift, start, interval_width):
        return np.sum(
            np.multiply(
                sample_a[start : start + interval_width],
                sample_b[start + shift : start + shift + interval_width],
            )
        )

    # calculates the time shift between two audio samples
    # currently disregards sample rate and speed of sound because vector will be
    # normalized in calculate_pinger_direction so constants dont matter
    def find_time_difference(self, sample_a, sample_b, start):
        interval_width = (
            1000  # TODO: set appropriate interval_width, check for out of bounds
        )
        min_shift = -100  # TODO: set an appropriate value, check for out of bounds
        max_shift = 100  # TODO: set an appropriate value, check for out of bounds

        shift_value = min_shift
        shift_autocorrelation = self.autocorrelation(
            sample_a, sample_b, min_shift, start, interval_width
        )
        for shift in range(min_shift + 1, max_shift):
            value = self.autocorrelation(
                sample_a, sample_b, shift, start, interval_width
            )
            if value > shift_autocorrelation:
                shift_value = shift
                shift_autocorrelation = value

        return shift_value

    # calculates a unit vector in the direction of the pinger
    def calculate_pinger_direction(self):
        # TODO: somehow detect when a ping begins so the start value is not hard
        # coded (currently just 200)
        displacements = np.array(
            [
                [
                    self.find_time_difference(
                        other_hydrophone.sample, self.origin.sample, 200
                    )
                ]
                for other_hydrophone in self.hydrophones
            ]
        )
        print(f"displacements calculated to be:\n{displacements}")

        hydrophone_matrix = np.concatenate(
            [hp.get_coordinates() for hp in self.hydrophones]
        )
        result = np.matmul(np.linalg.inv(hydrophone_matrix), displacements)
        return result / np.linalg.norm(result)  # normalize result to unit vector


# Testing the stuff
# TODO: pick more realistic test values + focus on units

# hydrophones located at origin and on the axes
hydrophone_origin = Hydrophone()  # origin hydrophone (coordinate 0, 0, 0)
x_coord = 5
y_coord = 4
z_coord = 3
hydrophone_a = Hydrophone(x_coord, 0, 0)
hydrophone_b = Hydrophone(0, y_coord, 0)
hydrophone_c = Hydrophone(0, 0, z_coord)

# difference in time between signals are received by each hydrophone relative to origin
shift1 = 40
shift2 = 30
shift3 = 20

# generating sine waves shifted by above shifts for each hydrophone
x = np.linspace(0, 10, 2000)
y0 = np.zeros(x.shape)
y1 = np.zeros(x.shape)
y2 = np.zeros(x.shape)
y3 = np.zeros(x.shape)

y0[250:1000] = np.sin((x[250:1000] - x[250]) * 10)
y1[250 - shift1 : 1000 - shift1] = np.sin((x[250:1000] - x[250]) * 10)
y2[250 - shift2 : 1000 - shift2] = np.sin((x[250:1000] - x[250]) * 10)
y3[250 - shift3 : 1000 - shift3] = np.sin((x[250:1000] - x[250]) * 10)

# adding some noise
noise = 0.05 * np.random.normal(size=y0.shape)
# noise += 0.1 * np.sin(x*2)
# noise += 0.1 * np.sin(x*2.5)
# noise += 0.1 * np.sin(x*1.5)
y0 += noise
y1 += noise
y2 += noise
y3 += noise

plt.plot(x, y0)
# plt.plot(x, y1)
# plt.plot(x, y2)
# plt.plot(x, y3)
plt.show()

hydrophone_origin.sample = y0
hydrophone_a.sample = y1
hydrophone_b.sample = y2
hydrophone_c.sample = y3

hydrophone_array = HydrophoneArray(
    hydrophone_origin, hydrophone_a, hydrophone_b, hydrophone_c
)

print(
    f"calculated value of unit vector of direction of pinger is:\n{hydrophone_array.calculate_pinger_direction()}"
)
array = np.array([[shift1 / x_coord], [shift2 / y_coord], [shift3 / z_coord]])
print(f"correct answer should be:\n{array/np.linalg.norm(array)}")
