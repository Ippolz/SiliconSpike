%% TEST 1 - Low Load rTMS
clear 
clc

s = serialport("COM6",115200);
fopen(s);
pause(2);

fwrite(s,"Triggerbox developed by Giuseppe Ippolito. DOI: 123.456789");
pause(0.01);

fwrite(s,"SET,IPI1,100");
pause(0.01);
fwrite(s,"SET,nPULS1,7");
pause(0.01);

fwrite(s,"rTMS");
pause(0.01);

for i = 1:100
    fwrite(s,"1");
    WaitSecs(5);
end

% Close the serial communication
fwrite(s,"Z");  % Return to the settings phase

fclose(s);
delete(s);
clear s;


%% TEST 2 - High Load rTMS + Markers
clear 
clc

s = serialport("COM6",115200);
fopen(s);
pause(2);

fwrite(s,"Triggerbox developed by Giuseppe Ippolito. DOI: 123.456789");
pause(0.01);

fwrite(s,"SET,IPI1,70");
pause(0.01);
fwrite(s,"SET,IPI2,90");
pause(0.01);
fwrite(s,"SET,IPI3,120");
pause(0.01);
fwrite(s,"SET,IPI4,150");
pause(0.01);

fwrite(s,"SET,nPULS1,7");
pause(0.01);
fwrite(s,"SET,nPULS2,7");
pause(0.01);
fwrite(s,"SET,nPULS3,7");
pause(0.01);
fwrite(s,"SET,nPULS4,7");
pause(0.01);

fwrite(s,"SET,MRK1,7");
pause(0.01);
fwrite(s,"SET,MRK2,9");
pause(0.01);
fwrite(s,"SET,MRK3,12");
pause(0.01);
fwrite(s,"SET,MRK4,15");
pause(0.01);

fwrite(s,"rTMS");
pause(0.01);

mrk = ["A" "B" "C" "D"];
stim = ["1" "2" "3" "4"];
rnd_mrk = repmat(mrk,1,100)';
rnd_mrk = shuffle(rnd_mrk);
rnd_stim = repmat(stim,1,100)';
rnd_stim = shuffle(rnd_stim);
n_trial = [1:1:length(rnd_stim)]';
mat_tot = zeros(length(n_trial),3);

for i = 1:length(rnd_stim)
    fwrite(s,rnd_mrk(i));
    WaitSecs(1);
    fwrite(s,rnd_stim(i));
    WaitSecs(2);
    mat_tot(i,1) = n_trial(i);
    mat_tot(i,2) = str2mat(rnd_mrk(i))-64;
    mat_tot(i,3) = rnd_stim(i);
end

% Close the serial communication
fwrite(s,"Z");  % Return to the settings phase

fclose(s);
delete(s);
clear s;


%% TEST 3 - Low Load dcTMS

s = serialport("COM6",115200);
fopen(s);
pause(2);

fwrite(s,"Triggerbox developed by Giuseppe Ippolito. DOI: 123.456789");
pause(0.01);

fwrite(s,"SET,IPI1,150");
pause(0.01);

fwrite(s,"dcTMS");
pause(0.01);

for i = 1:100
    fwrite(s,"1");
    WaitSecs(3);
end

% Close the serial communication
fwrite(s,"Z");  % Return to the settings phase

fclose(s);
delete(s);
clear s;



%% TEST 4 - High Load slow-dcTMS + Markers
clear 
clc 

s = serialport("COM6",115200);
fopen(s);
pause(2);

fwrite(s,"Triggerbox developed by Giuseppe Ippolito. DOI: 123.456789");
pause(0.01);

fwrite(s,"SET,IPI1,150");
pause(0.01);
fwrite(s,"SET,IPI2,500");
pause(0.01);
fwrite(s,"SET,IPI3,700");
pause(0.01);
fwrite(s,"SET,IPI4,1000");
pause(0.01);

fwrite(s,"SET,MRK1,7");
pause(0.01);
fwrite(s,"SET,MRK2,10");
pause(0.01);
fwrite(s,"SET,MRK3,15");
pause(0.01);
fwrite(s,"SET,MRK4,20");
pause(0.01);

fwrite(s,"dcTMS");
pause(0.01);

mrk = ["A" "B" "C" "D"];
stim = ["1" "2" "3" "4"];
rnd_mrk = repmat(mrk,1,100)';
rnd_mrk = shuffle(rnd_mrk);
rnd_stim = repmat(stim,1,100)';
rnd_stim = shuffle(rnd_stim);
n_trial = [1:1:length(rnd_stim)]';
mat_tot = zeros(3,length(n_trial));

for i = 1:length(rnd_stim)
    fwrite(s,rnd_mrk(i));
    WaitSecs(1);
    fwrite(s,rnd_stim(i));
    WaitSecs(4);
    mat_tot(i,1) = n_trial(i);
    mat_tot(i,2) = str2mat(rnd_mrk(i))-64;
    mat_tot(i,3) = rnd_stim(i);
end

% Close the serial communication
fwrite(s,"Z");  % Return to the settings phase

fclose(s);
delete(s);
clear s;


%% TEST 5 - High Load fast-dcTMS + Markers
clear 
clc

s = serialport("COM6",115200);
fopen(s);
pause(2);

fwrite(s,"Triggerbox developed by Giuseppe Ippolito. DOI: 123.456789");
pause(0.01);

fwrite(s,"SET,IPI1,7");
pause(0.01);
fwrite(s,"SET,IPI2,10");
pause(0.01);
fwrite(s,"SET,IPI3,15");
pause(0.01);
fwrite(s,"SET,IPI4,20");
pause(0.01);

fwrite(s,"SET,MRK1,7");
pause(0.01);
fwrite(s,"SET,MRK2,10");
pause(0.01);
fwrite(s,"SET,MRK3,15");
pause(0.01);
fwrite(s,"SET,MRK4,20");
pause(0.01);

fwrite(s,"dcTMS");
pause(0.01);

mrk = ["A" "B" "C" "D"];
stim = ["1" "2" "3" "4"];
rnd_mrk = repmat(mrk,1,100)';
rnd_mrk = shuffle(rnd_mrk);
rnd_stim = repmat(stim,1,100)';
rnd_stim = shuffle(rnd_stim);
n_trial = [1:1:length(rnd_stim)]';
mat_tot = zeros(3,length(n_trial));

for i = 1:length(rnd_stim)
    fwrite(s,rnd_mrk(i));
    WaitSecs(0.5);
    fwrite(s,rnd_stim(i));
    WaitSecs(3);
    mat_tot(i,1) = n_trial(i);
    mat_tot(i,2) = str2mat(rnd_mrk(i))-64;
    mat_tot(i,3) = rnd_stim(i);
end

% Close the serial communication
fwrite(s,"Z");  % Return to the settings phase

fclose(s);
delete(s);
clear s;


%% TEST 6 - Intermittent Theta Burst TMS
clear 
clc

s = serialport("COM6",115200);
fopen(s);
pause(2);

fwrite(s,"Triggerbox developed by Giuseppe Ippolito. DOI: 123.456789");
pause(0.01);

fwrite(s,"SET,IPI1,10");
pause(0.01);
fwrite(s,"SET,nPULS1,3");
pause(0.01);

fwrite(s,"rTMS");
pause(0.01);

for a = 1:20
    for i = 1:10
        fwrite(s,"1");
        WaitSecs(0.2);
    end
    WaitSecs(10);
end

% Close the serial communication
fwrite(s,"Z");  % Return to the settings phase

fclose(s);
delete(s);
clear s;


%% TEST 7 - Continous Theta Burst TMS
clear 
clc

s = serialport("COM6",115200);
fopen(s);
pause(2);

fwrite(s,"Triggerbox developed by Giuseppe Ippolito. DOI: 123.456789");
pause(0.01);

fwrite(s,"SET,IPI1,10");
pause(0.01);
fwrite(s,"SET,nPULS1,3");
pause(0.01);

fwrite(s,"rTMS");
pause(0.01);

for i = 1:100
    fwrite(s,"1");
    WaitSecs(0.2);
end

% Close the serial communication
fwrite(s,"Z");  % Return to the settings phase

fclose(s);
delete(s);
clear s;


%% TEST 8 - Latencies
clear 
clc

s = serialport("COM6",115200);
fopen(s);
pause(2);

fwrite(s,"Triggerbox developed by Giuseppe Ippolito. DOI: 123.456789");
pause(0.01);

fwrite(s,"SET,IPI1,10");
pause(0.01);
fwrite(s,"SET,IPI2,100");
pause(0.01);
fwrite(s,"SET,IPI3,200");
pause(0.01);
fwrite(s,"SET,IPI4,300");
pause(0.01);
fwrite(s,"SET,IPI5,400");
pause(0.01);
fwrite(s,"SET,IPI6,500");
pause(0.01);
fwrite(s,"SET,IPI7,600");
pause(0.01);
fwrite(s,"SET,IPI8,700");
pause(0.01);
fwrite(s,"SET,IPI9,800");
pause(0.01);

fwrite(s,"dcTMS");
pause(0.01);

stim = ["1" "2" "3" "4" "5" "6" "7" "8" "9"];
rnd_stim = repmat(stim,1,20)';
rnd_stim = shuffle(rnd_stim);
n_trial = [1:1:length(rnd_stim)]';

for i = 1:length(rnd_stim)
    fwrite(s,rnd_stim(i));
    WaitSecs(2);
end

% Close the serial communication
fwrite(s,"Z");  % Return to the settings phase

fclose(s);
delete(s);
clear s;
