#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> A(n), B(n - 1);
    
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }
    for (int i = 0; i < n - 1; i++) {
        cin >> B[i];
    }
    
    // We need to find the minimum box size `x` that can fit all toys.
    // First, find the largest toy size that needs to be accommodated.
    int largest_toy = *max_element(A.begin(), A.end());
    
    // Now, find the smallest box size `x` that can fit the largest toy.
    int min_box_size = largest_toy;
    
    // We only need to check the box sizes that are not larger than `largest_toy`.
    // Since the box sizes are not necessarily in increasing order and there are no duplicates,
    // we need to do a linear search to find the minimum box size `x`.
    for (int box_size : B) {
        if (box_size >= largest_toy) {
            min_box_size = min(min_box_size, box_size);
        }
    }
    
    // If the minimum box size found is still equal to `largest_toy`, it means we need a new box of size `largest_toy`.
    // Otherwise, we can use an existing box of size `min_box_size`.
    if (min_box_size == largest_toy) {
        cout << largest_toy << endl;
    } else {
        cout << min_box_size << endl;
    }
    
    return 0;
}