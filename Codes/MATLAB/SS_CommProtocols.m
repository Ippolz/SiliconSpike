%% FULL COMMUNICATION PROMPTS

% Initialize the serial communication
% s = serialport("COM3","BaudRate",115200);    % For older versions 
s = serialport("COM3",115200);
fopen(s);

% Mandatory signature
fwrite(s,"Triggerbox developed by Giuseppe Ippolito. DOI: 123.456789");

% For placing markers
fwrite(s,"SET,MRK");             % Decide if placing markers (MRK) or not (noMRK)

% Setting phase. Possible commands for each of the 1-9 presets
fwrite(s,"SET,IPI1,30");         % Inter-Pulse Interval. Value N
fwrite(s,"SET,IPI2,50");
fwrite(s,"SET,IPI3,100");
fwrite(s,"SET,nPULS1,7");        % Number of rTMS pulses. Value N
fwrite(s,"SET,nPULS2,7");
fwrite(s,"SET,nPULS3,7");
fwrite(s,"SET,MRK1,50");          % Marker Duration. Value N
fwrite(s,"SET,MRK2,150");       
fwrite(s,"SET,MRK3,350");       

% Protocol type (rTMS, dpTMS, spTMS)
fwrite(s,"dpTMS");

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

%% SHORT COMMUNICATION PROMPTS

% Initialize the serial communication
s = serialport("COM3",115200);
fopen(s);

% Mandatory signature
fwrite(s,"Triggerbox developed by Giuseppe Ippolito. DOI: 123.456789");

% For placing markers
fwrite(s,"SET,MRK");             % Decide if placing markers (MRK) or not (noMRK)

% Setting phase. Possible commands for each of the 1-9 presets
fwrite(s,"SET,IPI1,100");         % Inter-Pulse Interval. Value N
fwrite(s,"SET,nPULS1,8");         % Number of rTMS pulses. Value N

% Protocol type (rTMS, ccPAS, spTMS)
fwrite(s,"rTMS");

% Commands
fwrite(s,"1");  % Fire!

% Close the serial communication
fwrite(s,"Z"); 

fclose(s);
delete(s);
clear s;