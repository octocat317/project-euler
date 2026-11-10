#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

long long nCr(int n, int r)
{
    if (r < 0 || r > n) {
        return 0;
    } else if (r == 0 || n == r) {
        return 1;
    }

    if (r > n - r) {
        r = n - r;
    }

    long long comb = 1;
    for (int i = 1; i <= r; ++i) {
        comb = (comb * (n - i + 1)) / i;
    }

    return comb;
}

int main(void)
{
    /* the number of nCr values of 'n' that are
     * greater than 1,000,000 is stored in moreCounts[n] */
    int moreCounts[101];
    for (int i = 0; i < 23; ++i) {
        moreCounts[i] = -1;
    }

    int n = 23, r = 9;
    bool done = false;
    while (!done) {
        if (nCr(n, r) < 1000000) {
            moreCounts[n] = (n + 1) - (2 * (r + 1));
            if (n == 100) {
                done = true;
                continue;
            }
            n = n + 1;
        } else {
            r = r - 1;
        }
    }

    int result = 0;
    for (int i = 23; i <= 100; ++i) {
        result += moreCounts[i];
    }

    printf("there are %d nCr's greater than one-million\n", result);

    for (int i = 23; i <= 100; ++i) {
        printf("\nn = %d\t-> %d", i, moreCounts[i]);
    }
    printf("\n\n");

    return EXIT_SUCCESS;
}
