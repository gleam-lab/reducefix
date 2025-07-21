#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> b(n - 1);
    
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n - 1; ++i) {
        cin >> b[i];
    }
    
    // Sort the sizes of toys and boxes
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    
    // Start with the second smallest box size to check compatibility
    int candidate_size = b[0];
    for (int i = 0; i < n; ++i) {
        if (a[i] > candidate_size) {
            // If a toy is larger than the current candidate box size,
            // we need to increment the box size.
            candidate_size++;
        }
    }
    
    // The candidate size is the minimum box size that can accommodate all toys.
    cout << candidate_size << endl;
    return 0;
}