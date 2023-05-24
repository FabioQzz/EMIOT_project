% Source: "Dynamic Lithium-Ion Battery Model for System Simulation"
% ΔE(T) : Temperature correction of the potential (V)
% This script finds the best fitting line for the given data

x = [-20, -10, 0, 23, 45];
y = [-0.46, -0.32, -0.13, 0, 0.24];

coeff = polyfit(x, y, 1)

x1 = linspace(-20, 50);
y1 = polyval(coeff,x1);

figure
plot(x,y,'o')
hold on
plot(x1,y1)
hold off