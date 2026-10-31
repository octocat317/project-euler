#include <stdbool.h>
#include <stdio.h>
#define MAX 42

int number = 0;

bool *sieveOfEratosthenes(int num)
{
    static bool isPrime[MAX + 1];

    for (int i = 2; i <= num; ++i) {
        isPrime[i] = true;
    }
    isPrime[0] = isPrime[1] = false;

    for (int p = 2; p * p <= num; ++p) {
        if (!isPrime[p]) {
            continue;
        }
        for (int q = p * p; q <= num; q += p) {
            isPrime[q] = false;
        }
    }

    return isPrime;
}

int generateNextPrime()
{
    static bool *isPrime = NULL;
    if (!isPrime) {
        isPrime = sieveOfEratosthenes(number);
    }

    for (static int next = 2; next <= number;) {
        if (isPrime[next]) {
            return next++;
        }
        ++next;
    }

    return -1;
}

// long long ipow(long long base, int exp)
// {
//     long long result = 1;
//     while (exp > 0) {
//         if (exp & 1) {
//             result *= base;
//         }
//         base *= base;
//         exp = exp >> 1;
//     }
//
//     return result;
// }

int main()
{
    printf("enter the positive integer: ");
    scanf("%d", &number);

    if (number <= 0 || number > MAX) {
        printf("invalid input\n");
        printf("only a positive integer no greater than %d is valid\n", MAX);
        return 0;
    }

    long long omniMultiple = 1;
    int prime = generateNextPrime();
    while (prime != -1) {
        // int longInt = floor(log2(number) / log2(prime));
        // floating-point precision may cause inaccuracies for larger numbers

        long long primePower = prime;
        while (primePower * prime <= number) {
            primePower *= prime;
        }

        // long long primePower = ipow(prime, logint);
        omniMultiple *= primePower;

        prime = generateNextPrime();
    }

    printf("smallest multiple of all positive integers up to %d is ", number);
    printf("%lld\n", omniMultiple);

    return 0;
}
