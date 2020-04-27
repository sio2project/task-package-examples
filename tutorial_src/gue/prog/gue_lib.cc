#include <iostream>

#include "gue.h"

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

// uper and lower bounds of interval of possible answers
int upperBound, lowerBound;

bool initDone = false, ansDone = false;
int queries = 0;

void output(bool correct, string comment) {
    cout << magicLine << "\n";
    cout << (correct ? "OK" : "WRONG") << "\n";
    cout << queries << "\n";
    cout << comment << "\n";
}

void assertCondition(bool cond, string err_msg) {
    // można zauważyć, że kontrukcja sprawdzaczki pozwala wypisać wiele razy
    // ona złapie tylko pierwszy błąd
    if (!cond)
        output(false, err_msg);
}

void check() {
    assertCondition(initDone && !ansDone, "Querries order is incorrect");
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

// we call the function isGreater
// as greater would collide with a different
// standard C++ function
bool isGreater(int x) {
    queries++;
    check();

    if (X != -1) {
        return X > x;
    }

    // adaptive part

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
