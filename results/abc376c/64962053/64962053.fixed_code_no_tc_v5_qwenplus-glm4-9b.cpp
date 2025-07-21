#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> va(n);
    vector<int> vb(n - 1);
    
    for (int i = 0; i < n; ++i) {
        cin >> va[i];
    }
    for (int i = 0; i < n - 1; ++i) {
        cin >> vb[i];
    }
    
    // Sort toy sizes and box sizes
    sort(va.begin(), va.end());
    sort(vb.begin(), vb.end());
    
    // The smallest box size we can use must be at least the size of the largest toy
    // and it should also be able to fit into the smallest box size that is larger
    // than any toy's size.
    int min_box_size = va.back();
    int max_box_size = INT_MIN;
    
    for (int i = 0; i < n - 1; ++i) {
        // We need to find the smallest box size that is larger than the largest toy
        // and also smaller than the current box size.
        if (va.back() <= vb[i]) {
            max_box_size = max(max_box_size, vb[i]);
        }
    }
    
    // The minimum box size we need to purchase must be the smallest possible value
    // that satisfies both conditions: it must be at least the size of the largest toy,
    // and it must be smaller than any box size that can fit the largest toy.
    if (min_box_size <= max_box_size) {
        cout << min_box_size << endl;
    } else {
        cout << -1 << endl;
    }
    
    return 0;
}