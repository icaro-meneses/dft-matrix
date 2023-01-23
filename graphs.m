close all;
clear all;
clc;

%%
% Data reading from file
data_dft_abs = fopen('./dft_abs.txt', 'r');
data_dft_frq = fopen('./dft_freqs.txt', 'r');

dft_cpx = dlmread('./dft_out.txt', ' ', 0, 0);
dft_abs = fscanf(data_dft_abs, "%f\n");
dft_frq = fscanf(data_dft_frq, "%f\n");

fclose(data_dft_abs);
fclose(data_dft_frq);

dft_real = dft_cpx(:, 1);
dft_imag = dft_cpx(:, 2);
N = length(dft_abs);

dft_fig = figure();
subplot(2, 1, 1);
stem(dft_frq, dft_abs / (N / 2), 'filled', 'linewidth', 2);
hold on;
title('DFT Magnitude', 'fontsize', 12);
grid on;

subplot(2, 1, 2);
stem(dft_frq, dft_real, 'filled', 'linewidth', 2);
hold on;
stem(dft_frq, dft_imag, 'filled', 'linewidth', 2);
title('DFT in Complex Form', 'fontsize', 12);
legend({'Real part', 'Imaginary part'}, 'fontsize', 10);
grid on;
hold off;

print(dft_fig, "dft_plot.pdf", "-dpdflatexstandalone", "-S800,600");
system("pdflatex dft_plot");
