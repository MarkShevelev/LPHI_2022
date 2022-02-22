#include <utility> // swap

using namespace std;

void ascending_bubble_sort(int data[], unsigned l_idx, unsigned r_idx) {
    bool sorted;
    do {
        sorted = true;
        for (unsigned current = l_idx, next = l_idx + 1; next != r_idx; ++current, ++next)
            if (data[next] < data[current]) {
                swap(data[next], data[current]);
                sorted = false;
            }
    } while (!sorted);
}