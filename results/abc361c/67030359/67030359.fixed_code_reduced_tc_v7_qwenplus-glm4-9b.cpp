#include <bits/stdc++.h>
using namespace std;

#define all(x) x.begin(), x.end()
#define rep(i, n) for (int i = 0; i < (n); ++i)

int main() {
    int n, k;
   cin >> n >> k;
    vector<int> A(n);
    rep(i, n) cin >> A[i];
    
    // Sort the vector
    sort(A.begin(), A.end());

    // The answer will be initialized to a large value
    int ans = 1e9;

    // We only need to consider removing exactly k elements from the sorted array
    // Let's calculate the minimum possible value of B by considering different scenarios

    // Case 1: Remove k smallest elements
    if (k <= n / 2) {
        int minVal = A[0];
        int maxVal = A[n - k - 1];
        ans = min(ans, maxVal - minVal);
    }

    // Case 2: Remove k largest elements
    if (k <= n / 2) {
        int minVal = A[k];
        int maxVal = A[n - 1];
        ans = min(ans, maxVal - minVal);
    }

    // Case 3: Remove k elements from both ends
    if (2 * k <= n) {
        int minVal = A[k];
        int maxVal = A[n - k];
        ans = min(ans, maxVal - minVal);
    }

    cout << ans << endl;
    return 0;
}