#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    FILE *fptr = fopen("numbers.txt", "r");

    int sum[52]; /* stores the sum digits in reverse */
    for (int i = 0; i < 52; ++i) {
        sum[i] = -1;
    }

    int carry = 0;
    int d;
    for (d = 0; d < 50; ++d) {
        fseek(fptr, 50 - d - 1, SEEK_SET);
        int digitSum = 0;
        for (int count = 0; count < 100; ++count) {
            int dig = fgetc(fptr) - '0';
            digitSum += dig;
            fseek(fptr, 50, SEEK_CUR);
        }
        digitSum += carry;
        sum[d] = digitSum % 10;
        carry = digitSum / 10;
    }

    if (carry > 0) {
        sum[d++] = carry % 10;
        carry = carry / 10;
    }
    if (carry > 0) {
        sum[d++] = carry;
    }

    printf("the first ten digits of the sum of "
           "the given one-hundred 50-digit numbers is ");

    int digCount = 0;
    for (int i = d - 1; i >= 0; --i) {
        printf("%d", sum[i]);
        ++digCount;
        if (digCount == 10) {
            break;
        }
    }
    printf("\n");

    return EXIT_SUCCESS;
}
