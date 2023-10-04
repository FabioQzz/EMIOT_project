clear all
close all

input_data = readtable('input_data.txt');
current = table2timetable(table(input_data.Time, input_data.Current));

charge = 

[c,rm,rmr,rmm] = rainflow(current)