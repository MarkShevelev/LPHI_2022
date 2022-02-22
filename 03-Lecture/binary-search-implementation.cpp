#include <iostream>

unsigned binary_search(int data[], unsigned l_idx, unsigned r_idx, int key);

using namespace std;

int main() {
    unsigned const size = 10;
    int omega_0, omega[size], k_0, k[size];
    unsigned res_lha_idx, res_rha_idx;
    bool found = false;

    //load
    {
        cin >> omega_0 >> k_0;
        for (unsigned idx = 0; idx != size; ++idx)
            cin >> omega[idx] >> k[idx];
    }

    //search
    {
        for (unsigned lha_idx = 0; lha_idx != size && !found; ++lha_idx) {
            auto rha_idx = binary_search(omega, 0, size, omega[lha_idx]);
            if (size != res_idx && k[lha_idx] + k[rha_idx] == k_0) {
                res_lha_idx = lha_idx;
                res_rha_idx = rha_idx;
                found = true;
            }
        }
    }

    //result
    {
        if (found)
            cout 
                << "There is a least one pair of waves: "
                << "(" << omega[res_lha_idx] << "," << k[res_lha_idx] << ")"
                << " and "
                << "(" << omega[res_rha_idx] << "," << k[res_rha_idx] << ")";
        else 
            cout << "There is no suitable pair of waves.";

        cout << endl;
    }
    return 0;   
}

unsigned binary_search(int data[], unsigned l_idx, unsigned r_idx, int key) {
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
