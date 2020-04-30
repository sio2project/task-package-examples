#include <algorithm>
#include "guelib.h"

int random_value(int a, int b)
{
    return rand() % (b - a + 1) + a;
}

int main()
{
    srand(0);
    int n = init();
    int st = 1, en = n;
    while (st < en)
    {
        int mid = random_value(st, en);
        if (isGreater(mid))
            st = mid + 1;
        else
            en = mid;
    }
    answer(st);
}
