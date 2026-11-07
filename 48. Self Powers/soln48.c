#include <stdio.h>
#include <stdlib.h>

#define THOUSAND 1000

int main(void)
{
    int powerSum[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    /* each array element holds one digit */
    for (int i = 1; i <= THOUSAND; ++i) {
        int selfPower[10] = {1, 0, 0, 0, 0, 0, 0, 0, 0, 0};
        /* each array element holds one digit */

        for (int count = 1; count <= i; ++count) {
            /* identifier 'count' for a loop variable means
             * it is not used inside the loop body */
            for (int k = 0; k < 10; ++k) {
                selfPower[k] *= i;
            }

            for (int k = 0; k < 10; ++k) {
                if (k == 9) {
                    selfPower[k] = selfPower[k] % 10;
                    continue;
                }
                if (selfPower[k] > 9) {
                    selfPower[k + 1] += selfPower[k] / 10;
                    selfPower[k] = selfPower[k] % 10;
                }
            }
        }

        int carry = 0;
        for (int k = 0; k < 10; ++k) {
            powerSum[k] += selfPower[k] + carry;
            carry = powerSum[k] / 10;
            powerSum[k] = powerSum[k] % 10;
        }
    }

    printf("the last ten digits of the self-power series up to %d is ",
           THOUSAND);
    for (int i = 9; i >= 0; --i) {
        printf("%d", powerSum[i]);
    }
    printf("\n\n");

    return EXIT_SUCCESS;
}
