#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define int long long

void solve() {
    int N, K;
    cin >> N >> K;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    sort(A.begin(), A.end());

    int result = numeric_limits<int>::max();
    // Try removing i elements from the front and (K - i) from the back
    for (int i = 0; i <= K; ++i) {
        int left = i;
        int right = N - 1 - (K - i);
        if (right >= left) {
            result = min(result, A[right] - A[left]);
        }
    }

    cout << result << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}