#include <fstream>
#include <iostream>
#include <limits>

typedef enum { HORIZONTAL, VERTICAL, DOWN_LEFT, DOWN_RIGHT } Direction;

int main()
{
    // std::ifstream grid("number-grid.txt");
    std::fstream gridFile("number-grid.txt", std::ios::in);
    if (!gridFile) {
        std::cerr << "error opening file\n";
        return 1;
    }

    int grid[20][20];
    for (int i = 0; i < 20; ++i) {
        for (int j = 0; j < 20; ++j) {
            gridFile >> grid[i][j];
        }
    }

    int product;
    int max_product = std::numeric_limits<int>::min();
    int num1, num2, num3, num4;
    Direction dir;

    /* horizontal - top-to-bottom then left-to-right */
    for (int j = 0; j <= 16; ++j) {
        for (int i = 0; i < 20; ++i) {
            int a = grid[i][j];
            int b = grid[i][j + 1];
            int c = grid[i][j + 2];
            int d = grid[i][j + 3];
            product = a * b * c * d;
            if (product > max_product) {
                max_product = product;
                num1 = a;
                num2 = b;
                num3 = c;
                num4 = d;
                dir = HORIZONTAL;
            }
        }
    }

    /* vertical - left-to-right then top-to-bottom */
    for (int i = 0; i <= 16; ++i) {
        for (int j = 0; j < 20; ++j) {
            int a = grid[i][j];
            int b = grid[i + 1][j];
            int c = grid[i + 2][j];
            int d = grid[i + 3][j];
            product = a * b * c * d;
            if (product > max_product) {
                max_product = product;
                num1 = a;
                num2 = b;
                num3 = c;
                num4 = d;
                dir = VERTICAL;
            }
        }
    }

    /* 45 degree diagonal - top-to-bottom then left-to-right */
    for (int j = 3; j < 20; ++j) {
        for (int i = 0; i <= 16; ++i) {
            int a = grid[i][j];
            int b = grid[i + 1][j - 1];
            int c = grid[i + 2][j - 2];
            int d = grid[i + 3][j - 3];
            product = a * b * c * d;
            if (product > max_product) {
                max_product = product;
                num1 = a;
                num2 = b;
                num3 = c;
                num4 = d;
                dir = DOWN_LEFT;
            }
        }
    }

    /* 135 degree diagonal - top-to-bottom then left-to-right */
    for (int j = 0; j <= 16; ++j) {
        for (int i = 0; i <= 16; ++i) {
            int a = grid[i][j];
            int b = grid[i + 1][j + 1];
            int c = grid[i + 2][j + 2];
            int d = grid[i + 3][j + 3];
            product = a * b * c * d;
            if (product > max_product) {
                max_product = product;
                num1 = a;
                num2 = b;
                num3 = c;
                num4 = d;
                dir = DOWN_RIGHT;
            }
        }
    }

    std::cout << "the greatest product of four adjacent numbers "
              << "in the grid is \n";
    std::cout << max_product << " = " << num1 << " X " << num2 << " X " << num3
              << " X " << num4;

    std::cout << "\n\nand the direction is ";
    if (dir == HORIZONTAL) {
        std::cout << "horizontal\n";
    } else if (dir == VERTICAL) {
        std::cout << "vertical\n";
    } else if (dir == DOWN_LEFT) {
        std::cout << "down-left diagonal\n";
    } else if (dir == DOWN_RIGHT) {
        std::cout << "down-right diagonal\n";
    }

    return 0;
}
