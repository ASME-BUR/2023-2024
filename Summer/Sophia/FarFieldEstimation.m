clc; clear all; close all;

beacon = [0.25, 1]; %Position of the beacon

hyd1 = [0,0]; %Position of the first hydrophone
distBetHyd = 0.5; %Hydrophones 0.5 m apart
hyd2 = [0,distBetHyd]; 
AUVPos = (hyd1 + hyd2)/2; %average hydrophone position & exact position of AUV

angExact = atand((beacon(2)-AUVPos(2))/(beacon(1)-AUVPos(1))); %calculate angle from beacon to AUV

distHyd1 = norm(beacon-hyd1); %Distance to first hydrophone
distHyd2 = norm(beacon-hyd2); %Distance to second hydrophone

estAngle = asind((distHyd1 - distHyd2)/distBetHyd); %estimated far-field angle
disp(angExact)
disp(estAngle)


