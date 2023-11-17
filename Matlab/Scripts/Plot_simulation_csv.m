clear all
close all

% Load input data from file
input_data = readtable('data/results_1.csv');
time_ms = input_data(:, 1);
current = input_data(:, 2);
v_batt = input_data(:, 3);
ccf = input_data(:, 4);
soc = input_data(:, 5);

%plot(time_ms.Clock_Time, current.Current)
%hold on;
plot(time_ms.Clock_Time, v_batt.V_battery)
hold on;
plot(time_ms.Clock_Time, soc.SoC)
hold on;
%plot(time_ms.Clock_Time, ccf.CCF)
%hold on;
%legend('Current', 'V Battery', "State of Charge", "State of Health (CCF)");
title('Simulation of C model')
legend('Battery Voltage', "State of Charge");