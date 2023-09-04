function [ElementPosition,ElementNormal] = helperSphericalProjector(N,fc,prop_speed)
% This function helperSphericalProjector is only in support of
% ActiveSonarExample. It may be removed in a future release.

%   Copyright 2016 The MathWorks, Inc.

azang = repmat((0:N-1)*360/(N)-180,N,1);
elang = repmat((0:N-1)'*180/(N-1)-90,1,N);
r = fc/prop_speed*ones(size(azang));

x = r.*cosd(elang).*cosd(azang);
y = r.*cosd(elang).*sind(azang);
z = r.*sind(elang);

ElementPosition = [x(:)';y(:)';z(:)'];
ElementNormal = [azang(:)';elang(:)'];

% [EOF]
