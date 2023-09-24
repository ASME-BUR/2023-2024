clc; clear all; close all;

propSpeed = 1520; %wave propogation speed in water, m/s
channelDepth = 200; %depth of channel, m
OperatingFrequency = 37.5e3; %signal frequency

%specify 10 paths within channel at propSpeed
isopaths = phased.IsoSpeedUnderwaterPaths('ChannelDepth',channelDepth,...
  'NumPathsSource','Property','NumPaths',10,'PropagationSpeed',propSpeed);

%create channel that propogates signals with operating frequency
channel = phased.MultipathChannel('OperatingFrequency',OperatingFrequency);

prf = 1; %time until pulse repeats in seconds
pulseWidth = 10e-3; %length of pulse in seconds
pulseBandwidth = 1/pulseWidth; %Pulse frequency
fs = 2*pulseBandwidth; %nyquist sampling frequency
wav = phased.RectangularWaveform('PRF',prf,'PulseWidth',pulseWidth,...
  'SampleRate',fs); %Create rectangular waveform with pulse width and frequency
channel.SampleRate = fs; %sampling rate, at nyquist frequency

%Create emitter object with voltage response
projector = phased.IsotropicProjector('VoltageResponse',120);

%Create emitter, with propagation speed and operating frequency
projRadiator = phased.Radiator('Sensor',projector,...
  'PropagationSpeed',propSpeed,'OperatingFrequency',OperatingFrequency);

%location of emitter
beaconPlat = phased.Platform('InitialPosition',[5000; 2000; -199],...
  'Velocity',[0; 0; 0]);

%Create hydrophone object with voltage sensitivity
hydrophone = phased.IsotropicHydrophone('VoltageSensitivity',-150);
numHydrophones = 2; %number of hydrophones
%create array of 5 hydrophones with spacing of half-wavelength of signal
array = phased.ULA('Element',hydrophone,...
  'NumElements',numHydrophones,'ElementSpacing',propSpeed/OperatingFrequency/2,...
  'ArrayAxis','y');
%create receiver set with specifying prop speed and frequency
arrayCollector = phased.Collector('Sensor',array,...
  'PropagationSpeed',propSpeed,'OperatingFrequency',OperatingFrequency);
%Location and velocity for array 
arrayPlat = phased.Platform('InitialPosition',[0; 0; -10],...
  'Velocity',[0; 1; 0]);
%Receiver amplifier, specify gain and noise
rx = phased.ReceiverPreamp(...
    'Gain',20,...
    'NoiseFigure',10,...
    'SampleRate',fs,...
    'SeedSource','Property',...
    'Seed',2007);

x = wav();%set variable to waveform
numTransmits = 10; %number of transmits
%store receiving data, for each of the 5 hydrophones for all transmissions
rxsig = zeros(size(x,1),numHydrophones,numTransmits);
for i = 1:numTransmits

  % Update array and acoustic beacon positions
  [pos_tx,vel_tx] = beaconPlat(1/prf); %argument is signal pulse frequency
  [pos_rx,vel_rx] = arrayPlat(1/prf);

  % Compute paths between the acoustic beacon and array
  [paths,dop,aloss,rcvang,srcang] = ...
      isopaths(pos_tx,pos_rx,vel_tx,vel_rx,1/prf);

  % Propagate the acoustic beacon waveform
  tsig = projRadiator(x,srcang);
  rsig = channel(tsig,paths,dop,aloss);
  
  % Collect the propagated signal
  rsig = arrayCollector(rsig,rcvang);
  
  % Store the received pulses
  rxsig(:,:,i) = abs(rx(rsig));
 
end
%plot the last received pulse 
t = (0:length(x)-1)'/fs;
figure(1)
plot(t,rxsig(:,end))
xlabel('Time (s)');
ylabel('Signal Amplitude (V)')

%create object for estimating distance, inputs sensors and prop speed and
%frequency
musicspatialspect = phased.MUSICEstimator('SensorArray',array,...
        'PropagationSpeed',propSpeed,'OperatingFrequency',...
        OperatingFrequency,'ScanAngles',-90:0.1:90,'DOAOutputPort',true,...
        'NumSignalsSource','Property','NumSignals',1);

numTransmits = 500;
angPassive = zeros(numTransmits,1); %angle measured from sensors
angAct = zeros(numTransmits,1); %actual angle

for i = 1:numTransmits

  % Update array and acoustic beacon positions
  [pos_tx,vel_tx] = beaconPlat(1/prf);
  [pos_rx,vel_rx] = arrayPlat(1/prf);

  % Compute paths between acoustic beacon and the array
  [paths,dop,aloss,rcvang,srcang] = ...
      isopaths(pos_tx,pos_rx,vel_tx,vel_rx,1/prf);
  angAct(i) = rcvang(1,1);
  
  % Propagate the acoustic beacon waveform
  tsig = projRadiator(x,srcang);
  rsig = channel(tsig,paths,dop,aloss);
  
  % Collect the propagated signal
  rsig = arrayCollector(rsig,rcvang);
  
  rxsig = rx(rsig);
 
  % Estimate the direction of arrival
  [~,angPassive(i)] = musicspatialspect(rxsig);
  
end

figure(2)
plot([angPassive angAct])
xlabel('Pulse Number')
ylabel('Arrival angle (degrees)')
legend('Estimated DOA','Actual DOA')

