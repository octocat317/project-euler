#include <iostream>

#define TWOHT 200000

int *primeFactorCountSieve()
{
    static int pfCount[TWOHT] = {0};
    for (int i = 0; i < TWOHT; ++i) {
        pfCount[i] = 0;
    }

    for (int p = 2; p < TWOHT; ++p) {
        if (pfCount[p] != 0) {
            continue;
        }
        for (int q = p; q < TWOHT; q += p) {
            ++pfCount[q];
        }
    }

    return pfCount;
}

int main()
{
    int *pfCount = primeFactorCountSieve();

    int first = -1;
    for (int i = 2; i < TWOHT - 3; ++i) {
        if (pfCount[i] == 4) {
            if (pfCount[i + 3] != 4) {
                i = i + 3;
                continue;
            } else if (pfCount[i + 1] == 4 && pfCount[i + 2] == 4) {
                first = i;
                break;
            }
        }
    }

    std::cout << "the first of the first four consecutive numbers to have ";
    std::cout << "four distinct prime factors each is ";
    std::cout << first << std::endl;

    return 0;
}
