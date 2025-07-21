#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> x(n), a(n + 1);
    
    for (int i = 0; i < n; ++i) {
        cin >> x[i];
    }
    
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        cin >> sum;
        a[i + 1] = a[i] + sum;
    }
    
    int q;
    cin >> q;
    while (q--) {
        int l, r;
        cin >> l >> r;
        
        // Binary search to find the ranges where x values are within [l, r]
        int left = lower_bound(x.begin(), x.end(), l) - x.begin();
        int right = upper_bound(x.begin(), x.end(), r) - x.begin();
        
        // Adjust the indices to be within the bounds of the prefix sum array
        left = max(left, 0);
        right = min(right, n);
        
        // Calculate the sum of the range using the prefix sums
        cout << a[right] - a[left] << endl;
    }
    
    return 0;
}