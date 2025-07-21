#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define int long long

typedef long long ll;
typedef pair<int, int> pii;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> A(n);
    for (int i = 0; i < n; ++i) {
        cin >> A[i];
    }

    // Sort the array to easily find smallest and largest after removals
    sort(A.begin(), A.end());

    // We need to remove K elements such that the difference between max and min is minimized.
    // Since we can choose which K elements to remove, the optimal strategy is to try removing
    // elements from both ends in different combinations and compute the minimum difference.

    // Try all possible ways to remove i elements from the left and (K - i) from the right
    // where i ranges from 0 to K. Only need to ensure that at least one element remains.

    int result = numeric_limits<int>::max();
    for (int i = 0; i <= K; ++i) {
        int left = i;
        int right = n - 1 - (K - left);
        if (left <= right)
            result = min(result, A[right] - A[left]);
    }

    cout << result << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}