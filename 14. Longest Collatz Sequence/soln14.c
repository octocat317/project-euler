#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

#define FHT 500000
#define IDX(n) ((n) - FHT - 1)

int collatz_length(int num)
{
    /* this array holds the collatz lengths of numbers from 500,001 to 1M */
    static int lengths[FHT] = {0};

    if (lengths[IDX(num)] != 0) {
        return lengths[IDX(num)];
    }

    long long val = num;
    int count = 0;
    while (val != 1) {
        if (val & 1) {
            val = (3LL * val) + 1;
        } else {
            val = val / 2LL;
        }
        ++count;

        if (val > FHT && val <= (2 * FHT) && lengths[IDX(val)] != 0) {
            count += lengths[IDX(val)];
            break;
        }
    }

    lengths[IDX(num)] = count;
    return lengths[IDX(num)];
}

int main(void)
{
    /* NOTE:
     * only numbers from 500,001 to 1,000,000 are processed;
     * because, each number (x) between 1 and 500,000 has a double (2 * x)
     * under 1 million that takes one more collatz step
     */
    int count;

    int num, num_count = INT_MIN;
    for (int i = FHT + 1; i <= 2 * FHT; ++i) {
        count = collatz_length(i);
        if (count > num_count) {
            num = i;
            num_count = count;
        }
    }

    printf("the number under one million that ");
    printf("produces the longest collatz chain is %d and \n", num);
    printf("its length is %d (counting arrows)\n", num_count);

    return EXIT_SUCCESS;
}
