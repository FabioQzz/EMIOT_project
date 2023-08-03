clear all
close all

%%% Simulation script

% Load input data from file
input_data = readtable('input_data_1.txt');
input_control = readtable('input_control.txt');

% Generate tables
v_min           = table2timetable(table(input_control.Time, input_control.VMin));
v_max           = table2timetable(table(input_control.Time, input_control.VMax));

current         = table2timetable(table(input_data.Time, input_data.Current));
init_cap        = table2timetable(table(input_data.Time, input_data.InitCap));
init_soc        = table2timetable(table(input_data.Time, input_data.InitSoc));
storage_time    = table2timetable(table(input_data.Time, input_data.StorTime));
temperature     = table2timetable(table(input_data.Time, input_data.Temp));
cycle_n         = table2timetable(table(input_data.Time, input_data.CycleN));

% Launch Simulink simulation
modelName       = 'test_simulation';
siminBaseline   = Simulink.SimulationInput(modelName);
siminBaseline   = setModelParameter(siminBaseline,'StartTime','0','StopTime','800000');
baseline        = sim(siminBaseline);

%Log output
out_v_batt  = baseline.v_batt;
out_ccf     = baseline.ccf;

% Plot results
plot(out_v_batt)
hold on;
%plot(out_ccf)
%hold on;

