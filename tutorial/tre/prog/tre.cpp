#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    unsigned n;
    std::cin >> n;

    if (n == 0) {
        std::cout << "Too small to exist\n";
        return 0;
    }

    for (unsigned x = 0; x < 2; ++x) {
        for (unsigned i = 0; i < n + x; ++i) {
            for (unsigned j = 0; j < n - i; ++j) {
                std::cout << '.';
            }
            for (unsigned j = 0; j < 2 * (i + 1) - 1; ++j) {
                std::cout << '#';
            }
            for (unsigned j = 0; j < n - i; ++j) {
                std::cout << '.';
            }
            std::cout << '\n';
        }
    }

    for (unsigned i = 0; i < 2; ++i) {
        for (unsigned j = 0; j < n; ++j) {
            std::cout << '.';
        }
        std::cout << '#';
        for (unsigned j = 0; j < n; ++j) {
            std::cout << '.';
        }
        std::cout << '\n';
    }

    return 0;
}
