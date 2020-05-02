#include <iostream>

 int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    unsigned n;
    std::cin >> n;

    if (n % 2 != 0) {
        std::cout << "Can't do that\n";
        return 0;
    }

    std::cout << 3 * n / 2 << "\n";

    for (unsigned i = 0; i < n; i += 2) {
        std::cout << i << " " << i << " 0\n";
        std::cout << i << " " << i + 1 << " 1\n";
        std::cout << i + 1 << " " << i + 1 << " 1\n";
    }

    return 0;
 }
