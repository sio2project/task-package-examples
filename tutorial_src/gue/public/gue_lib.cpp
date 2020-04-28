#include <iostream>

#include "gue.h"

using namespace std;

int N, X;

int init() {
    cout << "Input n: ";
    cin >> N;
    cout << "Input secret number: ";
    cin >> X;
    
    return N;
}

bool isGreater(int x) {
    cout << "Query: " << x << "\n";
    return X > x;
}

void answer(int x) {
    if (x == X) {
        cout << "Program guessed correctly!\n";
    } else {
        cout << "Program answered " << x << ", while the correct answer is " << X << "\n";
    }
}
