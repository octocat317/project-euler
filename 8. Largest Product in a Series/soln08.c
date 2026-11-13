#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define ERR_FILE_OPEN 1
#define ADJ_DIGS 13

int main(void)
{
    FILE *fptr = fopen("1000-digit-number.txt", "r");
    if (fptr == NULL) {
        fprintf(stderr, "error opening file...");
        exit(ERR_FILE_OPEN);
    }

    int digs[ADJ_DIGS];
    for (int i = 0; i < ADJ_DIGS; ++i) {
        digs[i] = fgetc(fptr) - '0';
    }

    long long product = 1;
    for (int i = 0; i < ADJ_DIGS; ++i) {
        product *= digs[i];
    }

    long long max_product = LLONG_MIN;
    int max_digs[ADJ_DIGS];
    int prev_dig = 1;
    int next_dig = 1;

    while (true) {
        if (prev_dig == 0) {
            product = 1;
            for (int i = 0; i < ADJ_DIGS; ++i) {
                product *= digs[i];
            }
        } else {
            product = (product * next_dig) / prev_dig;
        }

        if (product > max_product) {
            max_product = product;
            for (int i = 0; i < ADJ_DIGS; ++i) {
                max_digs[i] = digs[i];
            }
        }

        int next_char = fgetc(fptr);
        if (next_char == EOF) {
            break;
        }

        next_dig = next_char - '0';
        prev_dig = digs[0];

        for (int i = 1; i < ADJ_DIGS; ++i) {
            digs[i - 1] = digs[i];
        }
        digs[ADJ_DIGS - 1] = next_dig;
    }

    printf("the greatest product is %lld\n\n", max_product);
    printf("and the thirteen adjacent digits are \n");
    for (int i = 0; i < ADJ_DIGS; ++i) {
        printf("%d ", max_digs[i]);
    }
    printf("\n");

    fclose(fptr);
    fptr = NULL;

    return EXIT_SUCCESS;
}
