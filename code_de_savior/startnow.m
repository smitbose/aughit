function[]=startnow(arduino)
%Serial Communication with Arduino Setup
%arduino=serial('COM17','BaudRate',9600);
m = readVid();
%m=m*1000;
fprintf(arduino,'%f',m);