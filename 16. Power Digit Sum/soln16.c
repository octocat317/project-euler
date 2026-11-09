#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int digCount = floor(1000 * log10(2)) + 1;
    int arrSize = (int)ceil((double)digCount / 8);

    int power[arrSize];
    for (int i = 0; i < arrSize; ++i) {
        power[i] = 0;
    }
    power[0] = 1;

    int index = 0;
    for (int count = 1; count <= 1000; ++count) {
        for (int j = 0; j <= index; ++j) {
            power[j] *= 2;
        }

        for (int j = 0; j <= index; ++j) {
            if (power[j] > 99999999) {
                power[j + 1] += power[j] / 100000000;
                power[j] = power[j] % 100000000;
            }
            if (index + 1 < arrSize && j == index && power[index + 1] != 0) {
                ++index;
            }
        }
    }

    int digitSum = 0;
    for (int i = 0; i <= index; ++i) {
        int eightDigits = power[i];
        while (eightDigits > 0) {
            digitSum += eightDigits % 10;
            eightDigits = eightDigits / 10;
        }
    }

    printf("the sum of digits in the number 2^{1000} is %d\n", digitSum);

    return EXIT_SUCCESS;
}
