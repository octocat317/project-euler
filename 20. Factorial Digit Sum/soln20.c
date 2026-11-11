#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    double log10Sum = 0;
    for (int i = 1; i <= 100; ++i) {
        log10Sum += log10(i);
    }
    int digCount = floor(log10Sum) + 1;
    int arrSize = (int)ceil((double)digCount / 4);

    int fact[arrSize];
    for (int i = 0; i < arrSize; ++i) {
        fact[i] = 0;
    }
    fact[0] = 1;

    int index = 0;
    for (int i = 1; i <= 100; ++i) {
        for (int j = 0; j <= index; ++j) {
            fact[j] *= i;
        }

        for (int j = 0; j <= index; ++j) {
            if (fact[j] > 9999) {
                fact[j + 1] += fact[j] / 10000;
                fact[j] = fact[j] % 10000;
            }
            if (index + 1 < arrSize && j == index && fact[index + 1] != 0) {
                ++index;
            }
        }
    }

    int digitSum = 0;
    for (int i = 0; i <= index; ++i) {
        int fourDigits = fact[i];
        while (fourDigits > 0) {
            digitSum += fourDigits % 10;
            fourDigits = fourDigits / 10;
        }
    }

    printf("the sum of digits in the number factorial(100) is %d\n", digitSum);

    return EXIT_SUCCESS;
}
