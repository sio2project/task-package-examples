#include "guelib.h"

int main() {
    int n = init();
    int st = 1, en = n, mid = (st + en) / 2;
    while (st < en) {
        if (isGreater(mid))
            st = mid + 1;
        else
            en = mid;
        mid = (st + en) / 2;
    }
    answer(mid);
}
