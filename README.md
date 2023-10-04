# EMIOT project
Project for the Energy Management for IoT Course @ Politecnico di Torino (A.Y. 2022-23)

## Description
Modeling of battery behavior during charging and discharging cycles. The model is developed using MATLAB/Simulink, then translated to simple C/C++ code to be simulated on PC, lastly it is ported to an MCU. The project is based on multiple [papers](Papers)

## Current State

### Part 1
- [ ] Realistic input data 
- [x] SoC to Voc block
- [x] Circuit parameters
- [x] Circuit model (Simscape)
- [x] k1, k2, k3 parameters modeling with temperature
- [x] Potential variation due to temperature
- [x] Dynamic cycle counting

### Part 2
- [ ] Model translation to C/C++ 
  - [ ] Circuit model (Zeq)
- [ ] SystemC Testbench
  - [ ] Input data generation from file
  - [ ] Parametric simulation clock
  - [ ] Saving siulation results to file (.csv)
- [ ] Simulation with SystemC

### Part 3

- [ ] Porting to MCU

## Results

### Discharge behavior at different temperatures

![](./Docs/img/DischargeTime_DifferentTemperatures_PAPER.png)
*Screenshot taken from the paper: [A Dynamic Lithium-ion Battery Model...](./Papers/A_dynamic_lithium-ion_battery_model_considering_the_effects_of_temperature_and_capacity_fading.pdf)*

![](./Docs/img/DischargeTime_DifferentTemperatures.png)
*Simulation results of our model. [Timeseries file](./Docs/files/DischargeDifferentTemperatures.mat)*


## Issues

Nothing at the moment




