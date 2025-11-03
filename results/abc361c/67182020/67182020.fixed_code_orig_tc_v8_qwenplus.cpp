#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K;
    cin >> N >> K;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    sort(A.begin(), A.end());

    // We are removing exactly K elements, so we keep (N - K) elements.
    // The optimal way is to remove some prefix and suffix such that total removed = K.
    // Try all possible ways: remove i from left, K-i from right, where i in [0, K]
    ll ans = 1e18;
    for (int i = 0; i <= K; ++i) {
        int left_removed = i;
        int right_removed = K - i;
        int left_index = left_removed;
        int right_index = N - 1 - right_removed;
        if (left_index <= right_index) {
            ans = min(ans, (ll)A[right_index] - A[left_index]);
        }
    }

    cout << ans << endl;

    return 0;
}