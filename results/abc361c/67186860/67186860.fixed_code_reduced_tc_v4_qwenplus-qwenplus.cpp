#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> A(n);
    for (int i = 0; i < n; ++i)
        cin >> A[i];

    int window_size = n - k;
    
    // Using multisets to maintain min and max in the sliding window
    multiset<int> min_set, max_set;
    
    // Initialize first window
    for (int i = 0; i < window_size; ++i) {
        min_set.push_back(A[i]);
        max_set.push_back(A[i]);
    }

    int res = INT_MAX;
    for (int i = 0; i <= n - window_size; ++i) {
        // Add new element into window
        if (i + window_size < n) {
            min_set.insert(A[i + window_size]);
            max_set.insert(A[i + window_size]);
        }
        
        // Remove element going out of window
        if (i > 0) {
            auto it_min = min_set.find(A[i - 1]);
            min_set.erase(it_min);
            
            auto it_max = max_set.find(A[i - 1]);
            max_set.erase(it_max);
        }

        // Update result
        res = min(res, *max_set.rbegin() - *min_set.begin());
    }

    cout << res << endl;
    return 0;
}