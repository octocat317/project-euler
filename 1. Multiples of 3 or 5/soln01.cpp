#include <iostream>

int main()
{
    int sum3, sum5, sum15;

    sum3 = 3 * ((1000 / 3) * ((1000 / 3) + 1) / 2);
    sum5 = 5 * ((1000 / 5) * ((1000 / 5) + 1) / 2);
    sum15 = 15 * ((1000 / 15) * ((1000 / 15) + 1) / 2);

    int sum3or5 = sum3 + sum5 - sum15;

    std::cout << sum3or5 << '\n' << std::endl;

    // verification
    int sum = 0;
    for (int i = 1; i <= 1000; ++i) {
        if (i % 3 == 0 || i % 5 == 0) {
            sum += i;
        }
    }

    std::cout << (sum3or5 == sum) << std::endl;

    return 0;
}
