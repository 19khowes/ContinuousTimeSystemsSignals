#include <iostream>
#include <fstream>

using namespace std;
void getCoefficients(int order, double *coefficients);
void getInitials(int order, double *initials);
float getDeltaT();
float getStartTime();
float getEndTime();
void initializeX(int order, double *x, double *initials);
void initializeA(int order, double dt, double **A, double *coeffiecients);
void matrixVecMult(int order, double **A, double *x, double *newx);

int main() {
    // open file to write output to
    ofstream outfile("output.txt");
    // ask user for the order of differential equation and store in order
    int order = 1;
    cout << "Enter the order of the differential equation: ";
    cin >> order;
    
    // get user input (coefficients, intials, delta t, start time, and end time)
    double coefficients[order];
    getCoefficients(order, coefficients);
    double initials[order];
    getInitials(order, initials);
    float dt = getDeltaT();
    float startTime = getStartTime();
    float endTime = getEndTime();

    // create x vector (start with intial conditions)
    double x[order];
    initializeX(order, x, initials);
    // create matrix I + A(dt)
    double **A;
    A = new double* [order];
    for (int i = 0; i < order; i++) {
        A[i] = new double[order];
    }
    initializeA(order, dt, A, coefficients);

    // set up time and counting variables
    float runTime = startTime - endTime;
    float numPoints = runTime / dt;
    double newx[order];
    for (float t = startTime; t <= endTime; t += dt) {
        matrixVecMult(order, A, x, newx);
        // write newx's x1 to file with time t
        cout << "next solution: " << newx[0] << "\n";
        outfile << t << " " << newx[0] << endl;
        // change x = newx for next iteration
        for (int i = 0; i < order; i++) {
            x[i] = newx[i];
        }
    }  

    // close output file 
    outfile.close();
}

void matrixVecMult(int order, double **A, double *x, double *newx) {
    double sum;
    for (int i = 0; i < order; i++) {
        sum = 0;
        for (int j = 0; j < order; j++) {
            sum += A[i][j] * x[j];
        }
        newx[i] = sum;
    }
}

void initializeX(int order, double *x, double *initials) {
    cout << "x vector: \n";
    for (int i = 0; i < order; i++) {
        x[i] = initials[i];
        cout << x[i] << "\n";
    }

}

void initializeA(int order, double dt, double **A, double *coeffiecients) {
    for (int i = 0; i < order; i++) {
        for (int j = 0; j < order; j++) {
            if (j == (i + 1)) {
                A[i][j] = 1;
            }
            // last row
            if (i == (order - 1)) {
                A[i][j] = -1 * coeffiecients[j];
            }
            // multiply by dt
            A[i][j] = A[i][j] * dt;
            // add identity matrix now
            if (i == j) {
                A[i][j] = A[i][j] + 1;
            }
        }
    }

    // print A matrix
    cout << "Matrix I + A(dt):\n";
    for (int i = 0; i < order; i++) {
        for (int j = 0; j < order; j++) {
            cout << A[i][j] << " ";
        }
        cout << "\n";
    }
}


void getCoefficients(int order, double *coefficients) {
    // ask user for constant coeffiecients
    cout << "Enter coefficients from a_" << order-1 << " down to a_0:\n";
    int index = 0;
    for (int i = order-1; i >= 0; i--, index++) {
        cout << "coefficient a_" << i << ": ";
        cin >> coefficients[i];
    }
    // print out coeffients
    cout << "coefficients array: ";
    for (int i = 0; i < order; i++) {
        cout << coefficients[i] << " ";
    }
}

void getInitials(int order, double *initials) {
    cout << "\n\nEnter initial conditions:\n";
    for (int i = 0; i < order; i++) {
        // ask for specific y'(t) inital condition
        cout << "Intial condition for y";
        for (int j = 0; j < i; j++) {
            cout << "'";
        }
        cout << "(t): ";
        cin >> initials[i];
    }

    // print out initial conditions
    cout << "initials array: ";
    for (int i = 0; i < order; i++) {
        cout << initials[i] << " ";
    }
}

float getDeltaT() {
    cout << "\n\nEnter delta t (dt): ";
    float t;
    cin >> t;
    return t;
}

float getStartTime() {
    cout << "\n\nEnter start time: ";
    float t;
    cin >> t;
    return t;
}

float getEndTime() {
    cout << "\n\nEnter end time: ";
    float t;
    cin >> t;
    return t;
}