#include <iostream>

long long nCr(int n, int r)
{
    if (r < 0 || r > n) {
        return 0;
    } else if (r == 0 || r == n) {
        return 1;
    }

    if (r > n - r) {
        r = n - r;
    }

    long long comb = 1;
    for (int i = 1; i <= r; ++i) {
        comb = (comb * (n - i + 1)) / i;
    }

    return comb;
}

int main()
{
    std::cout << "enter number of rows and columns in the grid" << std::endl;

    int m, n;
    std::cout << "rows: " << std::flush;
    std::cin >> m;
    std::cout << "columns: " << std::flush;
    std::cin >> n;

    if (m < 0 || n < 0) {
        std::cerr << "\ninvalid input..." << std::endl;
        std::cerr << "rows and columns must be non-negative\n" << std::endl;
        return 1;
    }

    std::cout << "\nthere are " << nCr(m + n, m)
              << " routes to reach the bottom-right corner from "
              << "the top-left corner in a " << m << " X " << n << " grid"
              << std::endl;

    return 0;
}
