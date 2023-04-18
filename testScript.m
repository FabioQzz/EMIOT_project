current = [1,1,1,2,2,2,3,3,3];
s=tf('s');

Z=10+25+(1/10+(s*1))^-1

[num,den] = tfdata(Z)