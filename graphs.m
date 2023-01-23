close all;
clear all;
clc;

%%
% Data reading from file
data_dft_abs = fopen('./dft_abs.txt', 'r');
data_dft_frq = fopen('./dft_freqs.txt', 'r');

sig_in_cpx = dlmread('./input_signal.txt', ' ', 0, 0);
dft_cpx = dlmread('./dft_out.txt', ' ', 0, 0);
inv_dft_cpx = dlmread('./inv_dft.txt', ' ', 0, 0);
dft_abs = fscanf(data_dft_abs, "%f\n");
dft_frq = fscanf(data_dft_frq, "%f\n");

fclose(data_dft_abs);
fclose(data_dft_frq);

sig_in_real = sig_in_cpx(:, 1);
sig_in_imag = sig_in_cpx(:, 2);
dft_real = dft_cpx(:, 1);
dft_imag = dft_cpx(:, 2);
inv_dft_real = inv_dft_cpx(:, 1);
inv_dft_imag = inv_dft_cpx(:, 2);
N = length(dft_abs);
n = [0: 1: N - 1];

lower_x_tick = min(dft_frq);
step_x_tick = dft_frq(2) - dft_frq(1);
upper_x_tick = max(dft_frq);

dft_fig = figure();
subplot(2, 1, 1);
stem(dft_frq, dft_abs / (N / 2), 'filled', 'linewidth', 2);
set(gca, 'xtick', [lower_x_tick: 2*step_x_tick: upper_x_tick]);
set(gca, 'FontSize', 8);
hold on;
title('DFT Magnitude', 'fontsize', 12);
grid on;
hold off;

subplot(2, 1, 2);
stem(dft_frq, dft_real, 'filled', 'linewidth', 2);
set(gca, 'xtick', [lower_x_tick: 2*step_x_tick: upper_x_tick]);
set(gca, 'FontSize', 8);
hold on;
stem(dft_frq, dft_imag, 'filled', 'linewidth', 2);
title('DFT in Complex Form', 'fontsize', 12);
legend({'Real part', 'Imaginary part'}, 'fontsize', 10);
grid on;
hold off;

inv_dft_fig = figure();
subplot(2, 1, 1);
stem(n, sig_in_real, 'filled', 'linewidth', 2);
hold on;
stem(n, sig_in_imag, 'filled', 'linewidth', 2);
title('Input Signal in Complex Form', 'fontsize', 12);
legend({'Real part', 'Imaginary part'}, 'fontsize', 10);
grid on;
hold off;

subplot(2, 1, 2);
stem(n, inv_dft_real, 'filled', 'linewidth', 2);
hold on;
stem(n, inv_dft_imag, 'filled', 'linewidth', 2);
title('Inverse DFT in Complex Form', 'fontsize', 12);
legend({'Real part', 'Imaginary part'}, 'fontsize', 10);
grid on;
hold off;

print_size = "-S1024,768";
print(dft_fig, "dft_plot.pdf", "-dpdflatexstandalone", print_size);
system("pdflatex dft_plot");

print(inv_dft_fig, "idft_plot.pdf", "-dpdflatexstandalone", print_size);
system("pdflatex idft_plot");
