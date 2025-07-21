#include <bits/stdc++.h>
#define int long long
using namespace std;

int solve() {
    int n, k;
    vector<int> A, B;
    cin >> n >> k;
    A.resize(n), B.resize(n);
    
    for (int i = 0; i < n; ++i) {
        cin >> A[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> B[i];
    }
    
    // Create pairs of (A[i], B[i]) and sort by B[i] descending, then A[i] descending
    vector<pair<int, int>> pairs(n);
    for (int i = 0; i < n; ++i) {
        pairs[i] = {A[i], B[i]};
    }
    sort(pairs.rbegin(), pairs.rend()); // Sort in descending order of B[i] and A[i]
    
    long long result = 1e18;
    long long sumB = 0; // This will store the sum of B[i] for the top K elements
    long long maxA = 0; // This will store the maximum A[i] for the top K elements
    
    for (int i = 0; i < n; ++i) {
        if (i < k) {
            sumB += pairs[i].second;
            maxA = pairs[i].first;
        } else {
            long long newSumB = sumB - pairs[i].second + pairs[i].second * 0.5; // Use the second lowest B[i] from the top K to get the best result
            result = min(result, maxA * newSumB);
        }
    }
    
    return result;
}

int32_t main() {
    int t;
    cin >> t;
    while (t--) {
        cout << solve() << '\n';
    }
    return 0;
}