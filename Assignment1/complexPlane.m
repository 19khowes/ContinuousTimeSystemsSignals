x = [-0.1, -0.25, -0.25];
y = [0, -5, 5];

plot(x, y, '*')
grid on
xlim([-.5 .5])
ylim([-6 6])
xlabel('real part', 'FontSize', 20);
ylabel('imaginary part', 'FontSize', 20);
xline(0, 'LineWidth', 2);
yline(0, 'LineWidth', 2);