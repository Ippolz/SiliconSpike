% Calculates the length (ms) and distance of the square wave

clear 
clc

cd('D:\Projects\Silicon Spike\Data'); % Set the path

data = load("SSTest8 - MinMicr.mat");
data = data.data(:,3);

%% Wave length (TTL)
marker            = 5;
sampl2trigWL      = data == marker;
binarySignalWL    = sampl2trigWL;
countOnesWL       = 0;
lengthsOfOnesWL   = [];

for i = 1:length(binarySignalWL)
    if binarySignalWL(i) == 1
        countOnesWL = countOnesWL + 1;
    else
        if countOnesWL > 0
            lengthsOfOnesWL = [lengthsOfOnesWL, countOnesWL];
            countOnesWL = 0; 
        end
    end
end

lengthsOfOnesWL   = lengthsOfOnesWL./20;
lengthsOfOnesWL   = lengthsOfOnesWL';


%% Wave distance (IPI)
marker            = 5;
sampl2trigWD      = data ~= marker;
binarySignalWD    = sampl2trigWD;
countOnesWD       = 0;
lengthsOfOnesWD   = [];

for i = 1:length(binarySignalWD)
    if binarySignalWD(i) == 1
        countOnesWD = countOnesWD + 1;
    else
        if countOnesWD > 0
            lengthsOfOnesWD = [lengthsOfOnesWD, countOnesWD];
            countOnesWD = 0; 
        end
    end
end

lengthsOfOnesWD   = lengthsOfOnesWD./20;
lengthsOfOnesWD   = lengthsOfOnesWD';

trueWDdist        = lengthsOfOnesWD + lengthsOfOnesWL; 
