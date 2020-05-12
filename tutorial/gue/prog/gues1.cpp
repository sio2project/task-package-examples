#include "guelib.h"

int main() {
    int n = init();
    for (int i = 1; i <= n; i++) {
        if (!isGreater(i)) {
            answer(i);
            return 0;
        }
    }
}
