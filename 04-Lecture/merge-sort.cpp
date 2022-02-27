#include <iostream>

using namespace std;

void array_merge(
    int from[], int to[], 
    unsigned l_idx, unsigned split_idx, unsigned r_idx
) {
    unsigned left_run = l_idx, right_run = split_idx, to_run = l_idx;
    while(left_run != split_idx && right_run != r_idx)
        to[to_run++] = from[left_run] < from[right_run] ? from[left_run++] : from[right_run++];
    
    while(left_run != split_idx)
        to[to_run++] = from[left_run++];
    
    while(right_run != r_idx)
        to[to_run++] = from[right_run++];
}

void merge_sort(int to_sort[], int tmp[], unsigned l_idx, unsigned r_idx) {
    if (1 == r_idx - l_idx || 0 == r_idx - l_idx) return;
    auto split_idx = l_idx + (r_idx - l_idx) / 2;
    merge_sort(to_sort, tmp, l_idx, split_idx);
    merge_sort(to_sort, tmp, split_idx, r_idx);

    array_merge(to_sort, tmp, l_idx, split_idx, r_idx);
    for (unsigned idx = l_idx; idx != r_idx; ++idx)
        to_sort[idx] = tmp[idx];
}

int main() {
    int from[10] = {12,7,6,1,2,3,11,22,13,0};
    int to[10];

    merge_sort(from, to, 0, 10);

    for (auto x : to) 
        cout << x << " ";
    cout << endl;

    return 0;
}