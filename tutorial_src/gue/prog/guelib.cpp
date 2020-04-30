#include <iostream>

#include "guelib.h"

using namespace std;

namespace {

/*
 * IN:
 * N (^143)
 * X (^N)
 *
 * OUT:
 * magic line
 * OK/WRONG
 * queries
 * library comment
 */

int N, X;

const string magicLine = "GoodJobYouDiDEndTheGame!!";

// Upper and lower bounds of interval of possible answers.
int upperBound, lowerBound;

bool initDone = false, ansDone = false;
int queries = 0;

// Function used to print an output
// in a format accepted by the checker.
void output(bool correct, string comment) {
    cout << magicLine << "\n";
    cout << (correct ? "OK" : "WRONG") << "\n";
    cout << queries << "\n";
    cout << comment << "\n";
}

// If condition is failed, we print an error.
// Outputing error here guarantees "Wrong Answer" verdict,
// therefore we don't need to end the program afterwards.
void assertCondition(bool cond, string err_msg) {
    if (!cond)
        output(false, err_msg);
}

void check() {
    assertCondition(initDone && !ansDone, "Queries order is incorrect");
}

}  // namespace

int init() {

    assertCondition(!initDone, "Init done twice");

    cin >> N >> X;
    N = N ^ 143;
    if (X != -1)
        X = X ^ N;

    upperBound = N;
    lowerBound = 1;

    initDone = true;
    return N;
}

// We call the function isGreater
// as greater would collide with a different
// standard C++ function.
bool isGreater(int x) {
    queries++;
    check();
    
    assertCondition((x >= 1 && x <= N), "Incorrect function parameter");

    if (X != -1) {
        return X > x;
    }

    // Adaptive part

    if (x >= upperBound) {
        return false;
    } else if (x < lowerBound) {
        return true;
    } else if (upperBound - x > x - lowerBound + 1) {
        lowerBound = x + 1;
        return true;
    } else {
        upperBound = x;
        return false;
    }
}

void answer(int x) {
    check();
    ansDone = true;

    bool ok = false;
    if (X == x) {
        ok = true;
    } else if (X == -1 && upperBound == lowerBound && lowerBound == x) {
        ok = true;
    }

    string correct = (ok ? "right" : "wrong");

    output(ok, "You guessed the " + correct + " number!");
}
