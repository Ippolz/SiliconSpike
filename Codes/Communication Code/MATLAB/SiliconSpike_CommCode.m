%% FULL COMMUNICATION PROMPTS

% Here we provide an example of the Communication Code for a rTMS protocol,
% since it require to specify all of the stimulation parameters (both IPI
% and Number of Pulses). If you need to use a different protocol, simply
% adapt this code according to out guide: 
% https://ippoz.gitbook.io/silicon-spike-triggerbox/

% Original work: 
% Ippolito G. Quettier T. Borgomaneri S. Romei V. Silicon Spike: an Arduino-based 
% low-cost and open-access triggerbox to precisely control TMS devices, 
% DOI: 123.456789

% Initialize the serial communication
% s = serialport("COM3","BaudRate",115200);    % For older versions 
s = serialport("COM3",115200);
fopen(s);
pause(0.01);

% Mandatory signature
fwrite(s,"Triggerbox developed by Giuseppe Ippolito. DOI: 123.456789");
pause(0.01);

% For placing markers
fwrite(s,"SET,MRK");             % Decide if placing markers (MRK) or not (noMRK)
pause(0.01);

% Setting phase. Possible commands for each of the 1-9 presets
fwrite(s,"SET,IPI1,30");         % Inter-Pulse Interval. Value N
pause(0.01);
fwrite(s,"SET,IPI2,50");
pause(0.01);
fwrite(s,"SET,IPI3,100");
pause(0.01);
fwrite(s,"SET,nPULS1,7");        % Number of rTMS pulses. Value N
pause(0.01);
fwrite(s,"SET,nPULS2,7");
pause(0.01);
fwrite(s,"SET,nPULS3,7");
pause(0.01);
fwrite(s,"SET,MRK1,50");          % Marker Duration. Value N
pause(0.01);
fwrite(s,"SET,MRK2,150");       
pause(0.01);
fwrite(s,"SET,MRK3,350");       
pause(0.01);

% Protocol type (rTMS, dpTMS, spTMS)
fwrite(s,"rTMS");
pause(0.01);

% Commands
fwrite(s,"1");  % Fire!
fwrite(s,"2");
fwrite(s,"3");

fwrite(s,"A");  % Markers
fwrite(s,"B");
fwrite(s,"C");

% Close the serial communication
fwrite(s,"Z");  % Return to the settings phase

fclose(s);
delete(s);
clear s;
