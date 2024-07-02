%% FULL COMMUNICATION PROMPTS
%% Single pulse protocol (spTMS)

% Initialize the serial communication
% s = serialport("COM3","BaudRate",115200);    % For older versions (prior to 2019b)
s = serialport("COM3",115200);
fopen(s);
pause(2);

% Mandatory signature
fwrite(s,"Triggerbox developed by Giuseppe Ippolito. DOI: 123.456789");
pause(0.01);

% Declaring marker duration
fwrite(s,"SET,MRK1,3");
pause(0.01);
fwrite(s,"SET,MRK2,5");
pause(0.01);

% Protocol type (spTMS, dcTMS, rTMS)
fwrite(s,"spTMS");
pause(0.01);

% Commands
fwrite(s,"1");
fwrite(s,"2");
fwrite(s,"A");
fwrite(s,"B");

% Close the serial communication
fwrite(s,"Z");
fclose(s);
delete(s);
clear s;


%% Dual coil protocol (dcTMS)

% Initialize the serial communication
% s = serialport("COM3","BaudRate",115200);    % For older versions (prior to 2019b)
s = serialport("COM3",115200);
fopen(s);
pause(2);

% Mandatory signature
fwrite(s,"Triggerbox developed by Giuseppe Ippolito. DOI: 123.456789");
pause(0.01);

% Declaring the distance between the two TMS pulses
fwrite(s,"SET,IPI1,30");
pause(0.01);
fwrite(s,"SET,IPI2,50");
pause(0.01);
fwrite(s,"SET,IPI3,70");
pause(0.01);

% Declaring marker duration
fwrite(s,"SET,MRK1,3");
pause(0.01);
fwrite(s,"SET,MRK2,5");
pause(0.01);
fwrite(s,"SET,MRK3,7");
pause(0.01);

% Protocol type (spTMS, dcTMS, rTMS)
fwrite(s,"dcTMS");
pause(0.01);

% Commands
fwrite(s,"1");
fwrite(s,"2");
fwrite(s,"3");

fwrite(s,"A");
fwrite(s,"B");
fwrite(s,"C");

% Close the serial communication
fwrite(s,"Z");
fclose(s);
delete(s);
clear s;

%% Rhytmhic/repetitive coil protocol (rTMS)

% Initialize the serial communication
% s = serialport("COM3","BaudRate",115200);    % For older versions (prior to 2019b)
s = serialport("COM3",115200);
fopen(s);
pause(2);

% Mandatory signature
fwrite(s,"Triggerbox developed by Giuseppe Ippolito. DOI: 123.456789");
pause(0.01);

% Declaring the distance between each TMS pulse
fwrite(s,"SET,IPI1,80");
pause(0.01);
fwrite(s,"SET,IPI2,100");
pause(0.01);
fwrite(s,"SET,IPI3,120");
pause(0.01);

% Declaring the number of pulses within each train
fwrite(s,"SET,nPULS1,4");
pause(0.01);
fwrite(s,"SET,nPULS2,5");
pause(0.01);
fwrite(s,"SET,nPULS3,6");
pause(0.01);

% Declaring marker duration
fwrite(s,"SET,MRK1,3");
pause(0.01);
fwrite(s,"SET,MRK2,5");
pause(0.01);
fwrite(s,"SET,MRK3,7");
pause(0.01);

% Protocol type (spTMS, dcTMS, rTMS)
fwrite(s,"rTMS");
pause(0.01);

% Commands
fwrite(s,"1");
fwrite(s,"2");
fwrite(s,"3");

fwrite(s,"A");
fwrite(s,"B");
fwrite(s,"C");

% Close the serial communication
fwrite(s,"Z");
fclose(s);
delete(s);
clear s;
