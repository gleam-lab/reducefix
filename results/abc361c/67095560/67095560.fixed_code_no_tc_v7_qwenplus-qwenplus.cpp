#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define int long long

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> A(n);
    for (int i = 0; i < n; ++i) {
        cin >> A[i];
    }

    // We will use a sliding window approach to remove K elements
    // So we need to keep (n - K) consecutive elements in order
    int window_size = n - K;
    int min_diff = numeric_limits<int>::max();

    for (int i = 0; i + window_size <= n; ++i) {
        int current_min = A[i];
        int current_max = A[i + window_size - 1];
        min_diff = min(min_diff, current_max - current_min);
    }

    cout << min_diff << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}