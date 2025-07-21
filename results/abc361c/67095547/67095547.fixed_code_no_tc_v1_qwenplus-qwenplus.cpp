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

    // We need to keep (n - K) elements in B
    int window_size = n - k;

    // We'll use a sliding window approach on the sorted array
    sort(A.begin(), A.end());

    // The idea is to find the minimum difference between max and min
    // over all windows of size window_size in the sorted array
    int result = A[window_size - 1] - A[0];
    for (int i = 1; i + window_size - 1 < n; ++i) {
        result = min(result, A[i + window_size - 1] - A[i]);
    }

    cout << result << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}