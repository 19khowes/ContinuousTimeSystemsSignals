x = 0:6;
f1 = [0,1,2,3,2,1,0];
f2 = [-2,-2,-2,-2,-2,-2,-2];
f3 = [1,-1,1,-1, 0, 0, 0];
f4 = [0,0,0,-3,-3, 0, 0];
plot(x, f1, '-ob', x, f2, '-or', x, f3, '-o', x, f4, '-o')

legend('f1', 'f2', 'f3', 'f4')
xlabel('n');
ylabel('fx');
title('plot of functions f1, f2, f3, and f4')