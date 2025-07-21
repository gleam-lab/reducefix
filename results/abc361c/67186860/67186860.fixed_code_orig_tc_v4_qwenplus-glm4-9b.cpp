#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    // Create a copy of the array for sorting
    vector<int> b(a);
    sort(b.begin(), b.end());
    
    // If k is odd, we will remove one more element from the back
    if (k % 2 == 1) {
        b.pop_back();
    }
    
    // Now k is even, and we can calculate the answer
    int max_diff = INT_MIN;
    for (int i = 0; i <= n - k; i++) {
        int max_val = *max_element(b.begin() + i, b.begin() + i + k);
        int min_val = *min_element(b.begin() + i, b.begin() + i + k);
        max_diff = max(max_diff, max_val - min_val);
    }
    
    cout << max_diff << endl;
    return 0;
}