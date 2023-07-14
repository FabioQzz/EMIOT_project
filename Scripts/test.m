coefficients = polyfit([25, 50], [1.5e-3, 1.7e-3], 1);
a = coefficients (1)
b = coefficients (2)

res = a*50+b