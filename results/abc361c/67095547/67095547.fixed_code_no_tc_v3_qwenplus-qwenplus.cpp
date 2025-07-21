#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define int long long

typedef long long ll;
typedef pair<int, int> pii;

void solve() {
    int n, K;
    cin >> n >> K;
    vector<int> A(n);
    for (int i = 0; i < n; ++i) cin >> A[i];

    // We will try all possible windows of size N-K in the array
    // and compute min and max in each window to minimize (max - min)
    // Sliding window using a multiset for efficient queries

    multiset<int> window;
    int res = LLONG_MAX;

    // Initialize first window
    for (int i = 0; i < n - K - 1; ++i) {
        window.insert(A[i]);
    }

    // Slide window from left=N-K to right=N
    for (int i = 0, j = n - K - 1; j < n; ++i, ++j) {
        window.insert(A[j]);
        int mn = *window.begin();
        int mx = *window.rbegin();
        res = min(res, mx - mn);
        window.erase(window.find(A[i]));
    }

    cout << res << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}