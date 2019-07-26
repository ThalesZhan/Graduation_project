clear
clc
load("Test_Normal.txt")
load("Test_Chalky.txt")
load("Train_Normal.txt")
load("Train_Chalky.txt")

tn = length(Train_Normal);
ts = length(Train_Chalky)

y = linspace(0,ts-1,ts)';
x = linspace(0,tn-1,tn)';

plot(x, Train_Normal, '.')
hold on
plot(y, Train_Chalky,'.')