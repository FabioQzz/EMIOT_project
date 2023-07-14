% Simulation script

% Generate time steps
t = 0:1:100000;
t = t';

% Generate data signals
current         = [t,ones(size(t))*(0.1)];      % [A]
init_cap        = [t,ones(size(t))*2];        % [Ah]
init_soc        = [t,ones(size(t))*1];        % [Ah]
storage_time    = [t,ones(size(t))*1];        % [months]
temperature     = [t,ones(size(t))*(23)];    % [°C]
cycle_n         = [t,ones(size(t))*1];        % [n]

% Control signals
v_min           = [t,ones(size(t))*2.5];
v_max           = [t,ones(size(t))*6];

% Launch Simulink simulation
modelName       = 'test_simulation';
siminBaseline   = Simulink.SimulationInput(modelName);
siminBaseline   = setModelParameter(siminBaseline,'StartTime','0','StopTime','80000');
baseline        = sim(siminBaseline);

%Log output
out_v_batt  = baseline.v_batt;
out_ccf     = baseline.ccf;

% Plot results
%plot(out_v_batt)
%hold on;
%plot(out_ccf)
%hold on;

% Change input parameters
current         = [t,ones(size(t))*0.5];        % [A]
%cycle_n         = [t,ones(size(t))*600];        % [n]
%temperature     = [t,ones(size(t))*45];       % [°C]
% Launch second simulation
baseline        = sim(siminBaseline);
%Log output
out_v_batt  = baseline.v_batt;
% Plot results
v_batt_data = getdatasamples(out_v_batt,:);
time_data = out_v_batt.time(:);
time_data = hours(time_data);
plot(v_batt_data,time_data)
hold on;

% Third simulation
current         = [t,ones(size(t))*1];        % [A]
%temperature     = [t,ones(size(t))*(-20)];       % [°C]
baseline        = sim(siminBaseline);
out_v_batt  = baseline.v_batt;
%plot(out_v_batt)
%hold on;

% Fourth simulation
%current         = [t,ones(size(t))*0.5];        % [A]
%temperature     = [t,ones(size(t))*0];       % [°C]
baseline        = sim(siminBaseline);
out_v_batt  = baseline.v_batt;
%plot(out_v_batt)
%hold on;
