#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define MILLION 1000000

bool *sieveOfEratosthenes()
{
    bool *isPrime = malloc(MILLION * sizeof(bool));

    for (int i = 0; i < MILLION; ++i) {
        isPrime[i] = true;
    }
    isPrime[0] = isPrime[1] = false;

    for (int p = 2; p * p < MILLION; ++p) {
        if (!isPrime[p]) {
            continue;
        }
        for (int q = p * p; q < MILLION; q += p) {
            isPrime[q] = false;
        }
    }

    return isPrime;
}

bool *circularCheck()
{
    bool *isPrime = sieveOfEratosthenes();
    bool *isCirularPrime = malloc(MILLION * sizeof(bool));

    for (int i = 0; i < MILLION; ++i) {
        isCirularPrime[i] = isPrime[i];
    }

    int num = 2;
    int circularPerms[7];

    for (int num = 2; num < MILLION; ++num) {
        if (!isCirularPrime[num]) {
            continue;
        }

        for (int t = num; t > 0; t /= 10) {
            if (t % 10 == 0) {
                isCirularPrime[num] = false;
                break;
            }
        }
        if (!isCirularPrime[num]) {
            continue;
        }

        if (num < 10) {
            continue;
        }

        for (int i = 0; i < 7; ++i) {
            circularPerms[i] = -1;
        }

        int temp = num;
        int digitCount = floor(log10(num)) + 1;
        int leadPlace = 1;

        for (int k = 1; k < digitCount; ++k) {
            leadPlace *= 10;
        }

        int i = 0;
        while (digitCount--) {
            circularPerms[i++] = temp;
            temp = ((temp % 10) * leadPlace) + (temp / 10);
            if (temp == circularPerms[i - 1]) {
                break;
            }
        }

        int allFalse = false;
        for (int j = 0; circularPerms[j] != -1; ++j) {
            if (!allFalse && !isPrime[circularPerms[j]]) {
                allFalse = true;
                j = 0; /* resetting j back to zero */
            }
            if (allFalse) {
                isCirularPrime[circularPerms[j]] = false;
            }
        }
    }

    free(isPrime);

    return isCirularPrime;
}

int main(void)
{
    bool *isCircularPrime = circularCheck();

    int count = 0;
    for (int i = 2; i < MILLION; ++i) {
        if (isCircularPrime[i]) {
            ++count;
        }
    }

    printf("there are %d circular primes under %d\n", count, MILLION);

    free(isCircularPrime);

    return EXIT_SUCCESS;
}
