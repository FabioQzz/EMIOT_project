clear all
close all

%%% Simulation script

% Load input data from file
input_data = readtable('input_data_2.txt');
input_control = readtable('input_control.txt');

% Generate tables
v_min           = table2timetable(table(input_control.Time, input_control.VMin));
v_max           = table2timetable(table(input_control.Time, input_control.VMax));

current         = table2timetable(table(input_data.Time, input_data.Current));
init_cap        = table2timetable(table(input_data.Time, input_data.InitCap));
init_soc        = table2timetable(table(input_data.Time, input_data.InitSoc));
storage_time    = table2timetable(table(input_data.Time, input_data.StorTime));
temperature     = table2timetable(table(input_data.Time, input_data.Temp));
init_cycle_n    = table2timetable(table(input_data.Time, input_data.InitCycleN));

% Launch Simulink simulation
%modelName       = 'test_simulation';
modelName       = 'test_simulation_DISCR';
siminBaseline   = Simulink.SimulationInput(modelName);
siminBaseline   = setModelParameter(siminBaseline,'StartTime','0','StopTime','800000');
baseline        = sim(siminBaseline);

%Log output
out_v_batt      = timeseries2timetable(baseline.v_batt);
out_ccf         = timeseries2timetable(baseline.ccf);
out_soc         = timeseries2timetable(baseline.soc);

% Plot results
plot(out_v_batt.Time, out_v_batt.Data)
hold on;
plot(out_soc.Time, out_soc.Data)
hold on;
title('Simulation of Matlab model')
legend('Battery Voltage', 'State of Charge');
%plot(out_ccf.Time, out_ccf.Data)
%hold on;

%%% Second simulation
% cycle_n         = table2timetable(table(input_data.Time, input_data.CycleN*10));
% baseline        = sim(siminBaseline);
% out_v_batt      = baseline.v_batt;
% out_ccf         = baseline.ccf;
% plot(out_ccf.Time, out_ccf.Data)
% hold on;

[c,hist,edges,rmm,idx] = rainflow(out_v_batt);

T = array2table(c,'VariableNames',{'Count','Range','Mean','Start','End'})

