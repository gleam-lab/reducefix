#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n; // Number of patches
    vector<int> patches(n + 1); // Patch values
    for (int i = 0; i < n; ++i) {
        cin >> patches[i]; // Patch values
    }
    
    // Calculate the total number of patches and their values
    int total_patches = n + 1;
    for (int i = 1; i <= m; ++i) {
        int l, r; // Left and right bounds of the range to be filtered
        cin >> l >> r; // Range bounds for comparison
        // Find the indices of patches within the range to be filtered
        auto it = lower_bound(patches.begin() + 1, patches.end(), l); // First element of the range
        auto j = upper_bound(patches.begin() + 1, patches.end(), r); // Last element of the range
        // Calculate the sum of difference between adjacent patches in the range
        int diff_sum = j - it - 1; // Since we don't count the empty range, we subtract one less than the actual number of patches
        cout << diff_sum << endl; // Output the difference between adjacent patches
    }
    return 0;
}