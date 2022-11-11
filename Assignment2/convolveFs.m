f1 = [0,1,2,3,2,1];
f2 = [-2,-2,-2,-2,-2,-2,-2];
f3 = [1,-1,1,-1];
f4 = [0,0,0,-3,-3];

disp('f1*f1: ')
c = conv(f1, f1);
disp(c)

disp('f1*f2: ')
c = conv(f1, f2);
disp(c)

disp('f1*f3: ')
c = conv(f1, f3);
disp(c)

disp('f2*f3: ')
c = conv(f2, f3);
disp(c)

disp('f1*f4: ')
c = conv(f1, f4);
disp(c)