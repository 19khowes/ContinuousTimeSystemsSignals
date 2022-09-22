#include <iostream>
#include <fstream>

using namespace std;
void getCoefficients(int order, float *coefficients);
void getInitials(int order, float *initials);
float getDeltaT();
float getStartTime();
float getEndTime();
void initializeX(int order, float *x, float *initials);
void initializeA(int order, float **A, float *coeffiecients);

int main() {
    // ask user for the order of differential equation and store in order
    int order = 1;
    cout << "Enter the order of the differential equation: ";
    cin >> order;
    
    // get user input (coefficients, intials, delta t, start time, and end time)
    float coefficients[order];
    getCoefficients(order, coefficients);
    float initials[order];
    getInitials(order, initials);
    float dt = getDeltaT();
    float startTime = getStartTime();
    float endTime = getEndTime();

    // create x vector (start with intial conditions)
    float x[order];
    initializeX(order, x, initials);
    // create matrix A + I
    float **A;
    A = new float* [order];
    for (int i = 0; i < order; i++) {
        A[i] = new float[order];
    }
    initializeA(order, A, coefficients);

}


void initializeX(int order, float *x, float *initials) {
    for (int i = 0; i < order; i++) {
        x[i] = initials[i];
    }
}

void initializeA(int order, float **A, float *coeffiecients) {
    for (int i = 0; i < order; i++) {
        for (int j = 0; j < order; j++) {
            if (j == (i + 1)) {
                A[i][j] = 1;
            }
            // last row
            if (i == (order - 1)) {
                A[i][j] = -1 * coeffiecients[j];
            }
            // add identity matrix now
            if (i == j) {
                A[i][j] = A[i][j] + 1;
            }
        }
    }

    // print A matrix
    cout << "Matrix A + I:\n";
    for (int i = 0; i < order; i++) {
        for (int j = 0; j < order; j++) {
            cout << A[i][j] << " ";
        }
        cout << "\n";
    }
}


void getCoefficients(int order, float *coefficients) {
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

void getInitials(int order, float *initials) {
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