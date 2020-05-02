#include <bits/stdc++.h>

#include "oi.h"

constexpr unsigned MAX_LENGTH = 1e5;

int grid[MAX_LENGTH][3];

void endf(const char* msg, int line, int position) {
    std::cout << "WRONG" << std::endl;
    std::cout << "Line " << line << ": " << msg << std::endl;
    exit(0);
}

int main(int argc, char** argv) {
    if (argc != 4) {
        std::cerr << "Run: " << argv[0] << " in out wzo" << std::endl;
        return 1;
    }

    int n;
    {
        std::ifstream input(argv[1]);
        input >> n;
    }


    {
        oi::Scanner scanner(argv[2], endf, oi::PL);
        if (n % 2 != 0) {
            const char* result = "Can't do that";
            int result_len = strlen(result) + 1;

            char* str = (char*)malloc(result_len * sizeof(char));
            assert(str != NULL);

            scanner.readLine(str, result_len);
            scanner.skipWhitespaces();
            scanner.readEof();

            if (strcmp(result, str) == 0) {
                std::cout << "OK" << std::endl;
            } else {
                std::cout << "WRONG" << std::endl;
            }
        } else {
            int k = scanner.readInt();
            if (k == (3 * n / 2)) {
                std::cout << "OK" << std::endl;
            } else {
                std::cout << "WRONG" << std::endl;
                std::cout << "Wrong number of puzzles!" << std::endl;
                return 0;
            }
            scanner.skipWhitespacesUntilEOLN();
            scanner.readEoln();

            for (int i = 0; i < k; ++i) {
                int x = scanner.readInt(0, n - 1);
                scanner.readSpace();

                int y = scanner.readInt(0, 1);
                scanner.readSpace();
                
                int z = scanner.readInt(0, 1);
                scanner.skipWhitespacesUntilEOLN();
                scanner.readEoln();

                int check = (z == 0 ? grid[x + 1][y] : grid[x][y + 1]);
                
                if (grid[x][y] != 0 || check != 0) {
                    std::cout << "Puzzles intercept" << std::endl;
                    std::cout << "50" << std::endl;
                    return 0;
                }

                grid[x][y] = 1;
                if (z == 0) {
                    grid[x + 1][y] = 1;
                } else {
                    grid[x][y + 1] = 1;
                }
            }

            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < 3; ++j) {
                    if (grid[i][j] == 0) {
                        std::cout << "Field is not covered" << std::endl;
                        std::cout << "50" << std::endl;
                        return 0;
                    }
                }
            }
        }
    }


    return 0;
}
