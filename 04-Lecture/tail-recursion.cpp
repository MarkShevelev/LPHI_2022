unsigned long long naive_fibonacci_rec(unsigned long long N) {
    if (1 == N) return 1;
    if (2 == N) return 1;
    return naive_fibonacci_rec(N - 1) + naive_fibonacci_rec(N - 2);
}

unsigned long long fibonacci_loop(unsigned long long N) {
    auto prev = 1ull, curr = 1ull; // first and second
    while (1 != N) {
        auto tmp = curr;
        curr += prev;
        prev = tmp;
        --N
    }
    return prev;
}

unsigned long long fibonacci_tail_rec(
    unsigned long long prev, // 1 at call
    unsigned long long curr, // 1 at call
    unsigned long long N) {
    if (1 == N) return prev;
    return fibonacci_tail_rec(curr, curr + prev, N - 1);
}

unsigned long long fibonacci_tail_rec_adapter(unsigned long long N) {
    return fibonacci_tail_rec(1ull, 1ull, N);
}

double tail_rec_integral_power(double res, double base, double exp) {
    if (1 == exp) return base;
    return tail_rec_integral_power(res * base, base, exp - 1);
}

unsigned long long tail_rec_factorial(unsigned long long res, unsigned long long n) {
    if (1 == n) return 1;
    return tail_rec_factorial(res * n, n - 1);
}