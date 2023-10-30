## Results

### Discharge behavior at different temperatures

<img src="./img/DischargeTime_DifferentTemperatures_PAPER.png"  width="60%" height="30%">

*Screenshot taken from the paper: [A Dynamic Lithium-ion Battery Model...](./Papers/A_dynamic_lithium-ion_battery_model_considering_the_effects_of_temperature_and_capacity_fading.pdf)*

<img src="./img/DischargeTime_DifferentTemperatures.png"  width="60%" height="30%">

*Simulation results of our model. [Timeseries file](./Docs/files/DischargeDifferentTemperatures.mat)*

### Simulation in C

Example of the console output of a simulation run

```
**********
TIME:           0.000 s
Current:        0.000000 A
V Batt:         3.959059 V
CCF:            98.73 %
SoC:            75.00 %
**********
TIME:           600.000 s
Current:        1.000000 A
V Batt:         3.707443 V
CCF:            98.73 %
SoC:            58.03 %
**********
TIME:           1800.000 s
Current:        1.000000 A
V Batt:         3.608337 V
CCF:            98.72 %
SoC:            25.42 %
```