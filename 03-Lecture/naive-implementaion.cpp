#include <iostream>

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
        for (unsigned lha_idx = 0; lha_idx != size && !found; ++lha_idx)
            for (unsigned rha_idx = lha_idx + 1; rha_idx != size && !found; ++rha_idx) 
                if (omega[lha_idx] + omega[rha_idx] == omega_0 && k[lha_idx] + k[rha_idx] == k_0) {
                    res_lha_idx = lha_idx;
                    res_rha_idx = rha_idx;
                    found = true;
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