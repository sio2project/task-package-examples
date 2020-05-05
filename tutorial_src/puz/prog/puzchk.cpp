#include <cstring>
#include <fstream>
#include <iostream>

#include "oi.h"

constexpr unsigned MAX_LENGTH = 1e5;

const char* cantStr = "Can't do that";

void endf(const char* msg, int line, int position) {
    std::cout << "WRONG" << std::endl;
    std::cout << "Line " << line << ": " << msg << std::endl;
    exit(0);
}

void puzzleOutOfBoard() {
    std::cout << "OK" << std::endl;
    std::cout << "Puzzle went out of the board" << std::endl; 
    std::cout << "50" << std::endl;
    exit(0);
}

void puzzlesIntesect() {
    std::cout << "OK" << std::endl;
    std::cout << "Puzzles intersect" << std::endl; 
    std::cout << "50" << std::endl;
    exit(0);
}

int main(int argc, char** argv) {
    if (argc != 4) {
        std::cerr << "Run: " << argv[0] << " in out wzo" << std::endl;
        return 1;
    }

    int grid[MAX_LENGTH][3];
    memset(grid, 0, MAX_LENGTH * sizeof(int) * 3);

    // Read input data.
    int n;
    {
        std::ifstream input(argv[1]);
        input >> n;
    }

    // Read model output.
    int modelK;
    bool cantDoIt = false;
    {
        std::ifstream output(argv[3]);
        char first;
        output >> first;
        if (first == 'C') {
            cantDoIt = true;
        } else {
            output.putback(first);
            output >> modelK;
        }
    }


    {
        oi::Scanner scanner(argv[2], endf, oi::PL);
        if (cantDoIt) {
            int resultLen = strlen(cantStr);

            char result[resultLen + 1];
            memset(result, 0, resultLen + 1);

            int readLen = scanner.readLine(result, resultLen + 1);
            scanner.skipWhitespaces();

            if (resultLen == readLen) {
                scanner.readEof();
            }

            if (strcmp(cantStr, result) == 0) {
                std::cout << "OK" << std::endl;
            } else {
                std::cout << "WRONG" << std::endl;
                std::cout << cantStr << " expected!" << std::endl;
            }
        } else {
            int k = scanner.readInt();
            if (k != modelK) {
                std::cout << "WRONG" << std::endl;
                std::cout << "Wrong number of puzzles!" << std::endl;
                exit(0);
            }
            scanner.skipWhitespacesUntilEOLN();
            scanner.readEoln();

            for (int i = 0; i < k; ++i) {
                int x = scanner.readInt(0, n - 1);
                scanner.skipWhitespacesUntilEOLN();

                int y = scanner.readInt(0, 2);
                scanner.skipWhitespacesUntilEOLN();
                
                int z = scanner.readInt(0, 1);
                if (i < k - 1) {
                    scanner.skipWhitespacesUntilEOLN();
                    scanner.readEoln();
                } else {
                    scanner.skipWhitespaces();
                    scanner.readEof();
                }

                bool checkXY = (grid[x][y] == 0);

                if (z == 0) {
                    if (x == n - 1) {
                        puzzleOutOfBoard();
                    }
                    if (!checkXY || grid[x + 1][y] != 0) {
                        puzzlesIntesect();
                    }
                } else {
                    if (y == 2) {
                        puzzleOutOfBoard();
                    }
                    if (!checkXY || grid[x][y + 1] != 0) {
                        puzzlesIntesect();
                    }
                }

                // Mark current fields.
                grid[x][y] = 1;
                if (z == 0) {
                    grid[x + 1][y] = 1;
                } else {
                    grid[x][y + 1] = 1;
                }
            }

            std::cout << "OK" << std::endl;
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
