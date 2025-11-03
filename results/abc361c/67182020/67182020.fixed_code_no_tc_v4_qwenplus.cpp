#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K;
    cin >> N >> K;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    sort(A.begin(), A.end());

    // We are removing exactly K elements, so we keep (N - K) elements.
    // The optimal strategy is to remove some prefix and suffix from the sorted array.
    // Try all possible ways: remove i elements from left and (K - i) from right.
    ll min_diff = 1e18;
    for (int i = 0; i <= K; ++i) {
        int left_remove = i;
        int right_remove = K - i;
        int remaining_left = left_remove;
        int remaining_right = N - 1 - right_remove;

        if (remaining_left <= remaining_right) {
            ll diff = A[remaining_right] - A[remaining_left];
            min_diff = min(min_diff, diff);
        }
    }

    cout << min_diff << endl;

    return 0;
}