function helperPlotPaths(varargin)
% This function helperPlotPaths is only in support of
% ActiveSonarExample. It may be removed in a future release.

%   Copyright 2016 The MathWorks, Inc.

newplot;

if ischar(varargin{1})
  plotBellhop(varargin{1});
else
  [TxPos,RxPosAll,ChannelDepth,numPaths] = varargin{1:end};
  validateattributes(TxPos,{'double'},{'2d','nrows',3,'ncols',1});
  validateattributes(RxPosAll,{'double'},{'2d','nrows',3});
  nTargets = size(RxPosAll,2);
  
  % Plot source and target locations
  hold on;
  % Source
  l = plot(0,TxPos(3),'s','MarkerSize',10);
  set(l,'MarkerFaceColor',get(l,'Color'))
  % Targets
  for nTargets = 1:size(RxPosAll,2)
    r = rangeangle([TxPos(1:2); 0],[RxPosAll(1:2,nTargets);0]);
    l = plot(r,RxPosAll(3,nTargets),'o','MarkerSize',10);
    set(l,'MarkerFaceColor',get(l,'Color'))
  end
  
  cm = lines(nTargets+1);
 
  for iTarget = 1:nTargets
    [~,~,~,~,TxPosImage,~]=...
      phased.internal.imageMethod(ChannelDepth,TxPos,RxPosAll(:,iTarget),[0;0;0],numPaths);
    RxPos = RxPosAll(:,iTarget);
        
    % Convert to range
    zS = TxPosImage(3,:);
    zR = RxPos(3);
    r = rangeangle([TxPosImage(1:2,:);zeros(1,numPaths)],[RxPos(1:2);0]);
    r0 = r(1);
    r = r - r0;

    % Plot direct image paths
    line([r0 r(1)],[zR zS(1)],'Color',cm(iTarget+1,:))

    % Plot Channel interfaces
    linetop = [0 0; r0 0];
    linebot = [0 -ChannelDepth; r0 -ChannelDepth];
    line(linetop(:,1),linetop(:,2),'LineWidth',2);
    line(linebot(:,1),linebot(:,2),'LineWidth',2);

    % Plot direct paths
    slope = @(line) (line(2,2) - line(1,2))/(line(2,1) - line(1,1));
    intercept = @(line) line(1,2) - slope(line)*line(1,1);
    intersectx = @(line1,line2) (intercept(line2)-intercept(line1))/(slope(line1)-slope(line2)); 
    intersecty = @(line1,line2) slope(line1)*(intercept(line2)-intercept(line1))/(slope(line1)-slope(line2)) + intercept(line1);

    % Top first bounces
     for i = 1:ceil((numPaths-1)/2) %2:2+ceil((numPaths-1)/2)-1
        ind = i + 1;
        linei = [r0 zR; r(ind) zS(ind)];
          if mod(i,2)
            line0 = linetop;
           else
            line0 = linebot;
          end

          x0 = intersectx(linei,line0);
          y0 = intersecty(linei,line0);
          line([r0 x0],[zR y0],'Color',cm(iTarget+1,:))

          for j = 1:i-1
            linei = [x0 y0; r(ind-j) zS(ind-j)];
            if isequal(line0,linetop)
              line0 = linebot;
            else
              line0 = linetop;
            end
            line([x0 intersectx(linei,line0)],[y0 intersecty(linei,line0)],'Color',cm(iTarget+1,:));
            x0 = intersectx(linei,line0);
            y0 = intersecty(linei,line0);
          end
          line([r(1) x0],[zS(1) y0],'Color',cm(iTarget+1,:));
     end

     % Bottom first bounces
     for i = 1:floor((numPaths-1)/2) 
        ind = i + ceil((numPaths-1)/2) +1;
        linei = [r0 zR; r(ind) zS(ind)];
          if ~mod(i,2)
            line0 = linetop;
           else
            line0 = linebot;
          end

          x0 = intersectx(linei,line0);
          y0 = intersecty(linei,line0);
          line([r0 x0],[zR y0],'Color',cm(iTarget+1,:))

          for j = 1:i-1
            linei = [x0 y0; r(ind-j) zS(ind-j)];
            if isequal(line0,linetop)
              line0 = linebot;
            else
              line0 = linetop;
            end
            line([x0 intersectx(linei,line0)],[y0 intersecty(linei,line0)],'Color',cm(iTarget+1,:));
            x0 = intersectx(linei,line0);
            y0 = intersecty(linei,line0);
          end
          line([r(1) x0],[zS(1) y0],'Color',cm(iTarget+1,:));
     end
  end
  
  xlabel('Range (m)')
  ylabel('Z-position (m)')
  title('Underwater Paths')
  axis tight
  hold off
  legend('Source','Target1','Target2')
  
end


end

function plotBellhop(rayfile)

% Plot a BELLHOP .ray file
rayfile = [rayfile '.ray'];
fid = fopen(rayfile,'r');   

% Read header information
[~]         = fgetl(fid);
[~]         = fscanf( fid, '%f', 1 );
[~]         = fscanf( fid, '%f', 3 );
NAngles     = fscanf( fid, '%i', 2 );
[~]         = fscanf( fid, '%f', 1 );
[~]         = fscanf( fid, '%f', 1 );
[~]         = fgetl( fid );
[~]         = fgetl( fid );

% Plot sound speed profile
Munk = [0.0  1548.52;...
        200.0  1530.29; ...
        250.0  1526.69; ...
        400.0  1517.78; ...
        600.0  1509.49; ...
        800.0  1504.30; ...
       1000.0  1501.38; ...
       1200.0  1500.14; ...
       1400.0  1500.12; ...
       1600.0  1501.02; ...
       1800.0  1502.57; ...
       2000.0  1504.62; ...
       2200.0  1507.02; ...
       2400.0  1509.69; ...
       2600.0  1512.55; ...
       2800.0  1515.56; ...
       3000.0  1518.67; ...
       3200.0  1521.85; ...
       3400.0  1525.10; ...
       3600.0  1528.38; ...
       3800.0  1531.70; ...
       4000.0  1535.04; ...
       4200.0  1538.39; ...
       4400.0  1541.76; ...
       4600.0  1545.14; ...
       4800.0  1548.52; ...
       5000.0  1551.91];
hl = subplot(1,2,1);
plot(Munk(:,2),Munk(:,1),'LineWidth',2)
xlabel('Sound speed (m/s)')
ylabel('Depth (m)')
title('Munk Profile')
set(hl,'YDir','Reverse')   % plot with depth-axis positive down
axis('tight')

% Plot rays
hr = subplot(1,2,2);
p1p = get(hl,'position');
p1p(3) = p1p(3)/2;
set(hl,'position',p1p)
p1p = get(hl,'position');
p2p = get(hr,'position');
p2p(1) = p1p(1) + 1.2*p1p(3);
p2p(3) = 1.9*p2p(3);
set(hr,'position',p2p)
set(hr,'YTickLabels','')
hold on

for ibeam = 1:NAngles(1)
    [~] =  fscanf(fid,'%f',1);
    nsteps = fscanf(fid,'%i',1);
    if ~isempty(nsteps) 
        [~] = fscanf(fid,'%i',1);
        [~] = fscanf(fid,'%i',1);
        ray = fscanf(fid,'%f',[2 nsteps]);
        range = ray(1,:)/1000;
        depth = ray(2,:);
        if ibeam == 1
            %Plot the source and receiver location
            % Plot image locations and receiver location
            h = plot(range(1),depth(1),'s','MarkerSize',10);
            set(h,'MarkerFaceColor',get(h,'Color'))
            h = plot(range(end),depth(end),'o','MarkerSize',10);
            set(h,'MarkerFaceColor',get(h,'Color'))
        end
        if mod(ibeam,2)
          plot(range,depth);
        end
    end
end	% next beam

% Create labels and legend
set(gca,'YDir','Reverse')   % plot with depth-axis positive down
xlabel('Range (km)')
title('Bellhop Paths')
axis tight;
legend('Source','Receiver')
hold off

% Close the file.
fclose( fid );

end


