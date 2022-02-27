#include <utility> // swap
#include <iostream>

using namespace std;

unsigned partition_by_number(int data[], unsigned l_idx, unsigned r_idx, unsigned pivot);

void quick_sort(int data[], unsigned l_idx, unsigned r_idx) {
    if (!(l_idx < r_idx)) 
        return;
    auto split_idx = partition_by_number(data,l_idx,r_idx,data[l_idx + (r_idx - l_idx) / 2]);
    quick_sort(data, l_idx, split_idx);
    quick_sort(data, split_idx + 1, r_idx);
}

int main() {
    int arr[] = {11, 3, 4, 7, 14, 13, 1, 2, 6, 8, 9, 10, 5, 12};

    my_sort(arr, 0, 13);

    for (unsigned idx = 0; idx != 14; ++dix)
        cout << arr[idx] << " ";
    cout << endl;
}

unsigned partition_by_number(int data[], unsigned l_idx, unsigned r_idx, unsigned pivot) {
    while(true) {
        while (data[l_idx] < pivot) ++l_idx;
        while (pivot < data[r_idx]) --r_idx;

        if (r_idx <= l_idx)
            return r_idx;
        
        swap(data[l_idx++], data[r_idx--]);
    }
    return r_idx;
}
