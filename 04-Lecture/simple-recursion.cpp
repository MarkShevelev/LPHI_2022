#include <iostream>

using namespace std;

double integral_power(double base, unsigned exp) {
    if (1 == exp ) return base;
    return base * integral_power(base, exp - 1);
}

unsigned long long factorial(unsigned long long n) {
    if (1 == n) return 1;
    return n * factorial(n - 1);
}

unsigned gcd(unsigned a, unsigned b) {
    if (0 == b) return a;
    if (b > a) return gcd(b, a);
    return gcd(b, a % b);
}

int inductive_array_sum(int arr[], unsigned l_idx, unsigned r_idx) {
    if (1 == r_idx - l_idx) return arr[l_idx];
    return arr[l_idx] + inductive_array_sum(arr,l_idx + 1, r_idx);
}

double dichotomy_sqrt(double x, double a, double b, double tolerance) {
    auto center = (a + b) / 2.;
    if (b - a < tolerance) return center;
    if (center * center > x) return dichotomy_sqrt(x, a, center, tolerance);
    return dichotomy_sqrt(x, center, b, tolerance);
}

int max2(int a, int b) {
    return a > b ? a : b;
}

int max_arr(int arr[], unsigned l_idx, unsigned r_idx) {
    if (1 == r_idx - l_idx) return arr[l_idx];
    auto center_idx = l_idx + (r_idx - l_idx) / 2;
    int left_max = max_arr(l_idx, center_idx);
    int right_max = max_arr(center_idx, r_idx);
    return max2(left_max, right_max);
}

void print_count_rec(unsigned counter) {
    if (0 == counter)
        return;
    cout << "Hello recursion!" << '\n';
    print_count(counter - 1);
}

void print_count_loop(unsigned counter) {
    while (0 != counter) {
        cout << "Hello loop!" << '\n';
        ++counter;
    }
}

unsigned digit_sum_rec(unsigned remnant) {
    if (!remnant) return 0;
    return remant%10 + digit_sum_rec(remnant/10);
}

unsigned digit_sum_loop(unsigned a) {
    auto remnant = a;
    unsigned sum = 0;
    while(remnant) {
        auto digit = remnant%10;
        remnant /= 10;
    }
    return sum;
}
