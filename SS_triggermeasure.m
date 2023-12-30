% Calculates the length (ms) of the square
% wave from a Biopac signal at 10KHz

data = load("PROVA.mat");
data = data.data(:,3);

trigger      = 5;
sampl2trig   = data == trigger;
xxx          = diff(double(sampl2trig));
idx          = find(xxx == 1);
idx2         = find(xxx == -1);
condi        = (idx2 - idx)./10000;
sd           = std(condi);
avg          = mean(condi);


mat_cond = [condi; ""; avg; sd];
mat_cond = str2double(mat_cond);

fname=strcat("XXXXX3"); % Nome del file
xlswrite(fname,mat_cond);


%%

% Initialize the serial communication
s = serialport("COM3",115200);
fopen(s);
pause(2);

% Mandatory signature
fwrite(s,"Triggerbox developed by Giuseppe Ippolito. DOI: 123.456789");
pause(0.1);

% fwrite(s,"SET,noMRK");           % Eventually, if you don't want markers
pause(0.1);                      % Otherwise comment

% Setting phase. Possible commands for each of the 1-9 presets
fwrite(s,"SET,IPI1,50");         % Inter-Pulse Interval. Value N
pause(0.1);
fwrite(s,"SET,IPI2,150");
pause(0.1);
fwrite(s,"SET,IPI3,500");
pause(0.1);
fwrite(s,"SET,nPULS1,13");       % Number of rTMS pulses. Value N
pause(0.1);
fwrite(s,"SET,nPULS2,10");
pause(0.1);
fwrite(s,"SET,nPULS3,7");
pause(0.1);
fwrite(s,"SET,MRK1,50");         % Marker Duration. Value N
pause(0.1);
fwrite(s,"SET,MRK2,150");       
pause(0.1);
fwrite(s,"SET,MRK3,500");       
pause(0.1);


% Protocol type (rTMS, ccPAS, spTMS)
fwrite(s,"rTMS");
pause(0.1);

% Commands
fwrite(s,"1");  % Fire!
fwrite(s,"2");
fwrite(s,"3");

fwrite(s,"A");  % Markers
fwrite(s,"B");
fwrite(s,"C");

fwrite(s,"Z");  % Return to the settings phase


% Close the serial communication
fclose(s);
delete(s);
clear s;

%%

% Initialize the serial communication
s = serialport("COM3",115200);
fopen(s);
pause(2);

% Mandatory signature
fwrite(s,"Triggerbox developed by Giuseppe Ippolito. DOI: 123.456789");
pause(0.1);

% Setting phase. Possible commands for each of the 1-9 presets
fwrite(s,"SET,IPI1,100");         % Inter-Pulse Interval. Value N
pause(0.1);
fwrite(s,"SET,nPULS1,8");       % Number of rTMS pulses. Value N
pause(0.1);

% Protocol type (rTMS, ccPAS, spTMS)
fwrite(s,"rTMS");
pause(0.1);


% Commands
fwrite(s,"1");  % Fire!

% Close the serial communication
fclose(s);
delete(s);
clear s;




