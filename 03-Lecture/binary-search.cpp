#include <utility> // swap

bool bool_binary_search(int data[], unsigned size, int key) {
    unsigned l_idx = 0, r_idx = size;

    while (l_idx < r_idx) {
        auto pivot_idx = (l_idx + r_idx) / 2;
        if (key < data[pivot_idx])
            r_idx = pivot_idx;
        else if (data[pivot_idx] > key)
            l_idx = pivot_idx + 1;
        else 
            return true;
    }

    return false;
}

unsigned idx_binary_search(int data[], unsigned size, int key) {
    unsigned l_idx = 0, r_idx = size;
    
    while (l_idx < r_idx) {
        auto pivot_idx = (l_idx + r_idx) / 2;
        if (key < data[pivot_idx])
            r_idx = pivot_idx;
        else if (data[pivot_idx] > key)
            l_idx = pivot_idx + 1;
        else 
            return pivot_idx;
    }
    
    return size;    
}

unsigned idx_binary_search(int data[], unsigned l_idx, unsigned r_idx, int key) {
    unsigned const fail_idx = r_idx;
    
    while (l_idx < r_idx) {
        auto pivot_idx = (l_idx + r_idx) / 2;
        if (key < data[pivot_idx])
            r_idx = pivot_idx;
        else if (data[pivot_idx] > key)
            l_idx = pivot_idx + 1;
        else 
            return pivot_idx;
    }
    
    return fail_idx;    
}
