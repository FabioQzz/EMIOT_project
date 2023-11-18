## C Model 
In this document the reader will understand how the C code of the battery model is structured, what files compose it and how to adjust the parameters to start the desired system simulation.
The microtutorial is organized into these sections:
- [Battery Model Structure](#battery-model-structure)
- [Simulator Structure](#simulator-structure)
- [Start a simulation](#start-a-simulation)

## Battery Model Structure
The chosen battery model has been described and modeled entirely in C code according to the paper ([A Dynamic Lithium-ion battery model...](../Papers/A_dynamic_lithium-ion_battery_model_considering_the_effects_of_temperature_and_capacity_fading.pdf)).

The code is divided into different files, each of which represents the main equations that describe a specific block composing the model. All these files can be found in the "src" directory.
```
Complete_Model
├── src
│   ├── battery_model.c
│   ├── c_rate.c
│   ├── Eq_2_SOC_VOC.c
│   ├── Eq_4_CapacityCorrectionFactor.c
│   ├── Eq_8_12_RC_Components.c
│   ├── Eq_Zeq_circuit.c
│   ├── integration_N.c
│   ├── integration_SoC.c
├── battery.c
├── input.csv
├── results.csv
```

The main module of the model is represented by the **battery_model.c**  file. This represent the highest level block of the battery and it is composed of a function that takes as inputs all the most important parameters of the model such as: 
- clock period
- current
- initial capacity
- storage time
- temperature
- cycle number

These parameters are passed by value by the simulator of the model according to the user preferences.

Some useful variables have been declared locally to the function and their values initialized with the returning values of the corresponding functions.

Below a small summary table with the functions called and the variables assigned 
| Function | Returned Value |
| ----------- | ----------- |
| CapacityCorrectionFactor() | float ccf |
| CRate() | float c_rate | 
| integrationSoC() | float c_rate |
| SocToVoc() | float v_oc |
| integrationN() | static float cycle_n_var |
| RcComponents() | float R_transient_S, C_transient_S, R_transient_L, C_transient_L |
| ZeqCircuit() | float v_zeq |

It is worth highlighting that the *cycle_n_var* and *soc_var* variables have been declared as **static** so that their value is remembered and saved between different calls of the function itself, this is very important for the simulation process.

At the end the function returns to the simulator the following parameters (all passed by reference): 
- output voltage of the battery
- CCF (correction capacity factor)
- SOC (state of charge)

## Simulator Structure
The simulator has been implemented in the **battery.c** file. 

This file contains the *main()* that launches the actual simulation and two functions *input_generations()* and *output_check()* for the formatted input and output of parameters from/to *.csv* files.

In the main, after the openings of the input and output file and their correctness checks, the simulation parameters have been set and variables initialized.

The simulation parameters are:
| Simulation Parameter | Description |
| ----------- | ----------- |
| const double BASE_PERIOD_MS = 1 |  Minimum period |
| const double CHECK_PERIOD_MS = 5000 | Output checking period in ms | 
| const double MAX_SIM_TIME_MS = 43200000 | Maximum simulation time in ms |

The simulator was implemented through a *for loop* which at each iteration: 
- reads a trace from the *input.csv* file through *input_generations()* function
- calls the function representing the *battery_model()*  passing all the parameters to run the simulation 
- writes the results of the simulation through *output_check()* function


## Start a Simulation 
- The model inputs are passed via the file `/Complete_model/input.csv`
- Some timing simulation parameters can be set by the user to tune the simulation according to the specific needs, by modifying them in the `/Complete_model/battery.c`
- After compiling all the files composing the project the user can start the simulation by executing the `/Complete_model/battery.exe` file, which will write all the results in `/Complete_model/results.csv`.


