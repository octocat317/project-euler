#include <stdio.h>

int power10(int exponent)
{
    int result = 1;
    while (exponent--) {
        result *= 10;
    }

    return result;
}

int ceiling(double x)
{
    if (x - (int)x == 0) {
        return (int)x;
    } else {
        return (int)x + 1;
    }
}

int champernowneDigit(int position)
{
    /*
     * here, a 'block' is a sequence of numbers having the same number of digits
     * Block 1 = {1..9},
     * Block 2 = {10..99},
     * Block 3 = {100..999}, etc.
     */

    int containingNumber; /* the number that contains the required digit */
    int numberLength = 1; /* number of digits in containingNumber */

    int digitsBeforeBlock = 0;
    /* total number of digits in all the blocks before the containing-block */
    int digitsIncludingBlock = 9;
    /* total number of digits in all the blocks before and including the
     * containing-block */

    int nines = 0;
    /* largest all nines number (99..9) that is smaller than the
     * containingNumber */

    while (digitsIncludingBlock < position) {
        digitsBeforeBlock = digitsIncludingBlock;

        digitsIncludingBlock = digitsIncludingBlock +
                               9 * power10(numberLength) * (numberLength + 1);

        nines = nines * 10 + 9;
        ++numberLength;
    }

    int offsetInBlock = position - digitsBeforeBlock;
    /* digit offset from 'nines' to the given 'position' */
    int offsetWithinNumber = (offsetInBlock % numberLength);
    /* digit offset from the last complete number to the given 'position.'
     * offsetWithinNumber = 0 means the given 'position' is the last digit of
     * the containingNumber */

    containingNumber = nines + ceiling((double)offsetInBlock / numberLength);

    if (offsetWithinNumber == 0) {
        printf("d_{%d} -> %d[%d]\n", position, containingNumber / 10,
               containingNumber % 10);

        return containingNumber % 10;
    } else {
        int containingPart =
            containingNumber / power10(numberLength - offsetWithinNumber);
        int remainingPart =
            containingNumber % power10(numberLength - offsetWithinNumber);
        printf("d_{%d} -> %d[%d]%0*d\n", position, containingPart / 10,
               containingPart % 10, numberLength - offsetWithinNumber,
               remainingPart);

        return containingPart % 10;
    }
}

int main()
{
    int positions[7] = {1, 10, 100, 1000, 10000, 100000, 1000000};

    int product = 1;
    for (int i = 0; i < 7; ++i) {
        product *= champernowneDigit(positions[i]);
    }

    printf("\nthe product = %d\n", product);

    return 0;
}
