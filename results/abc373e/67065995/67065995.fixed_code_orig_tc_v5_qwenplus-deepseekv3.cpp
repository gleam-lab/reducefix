#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N, M;
    ll K;
    cin >> N >> M >> K;
    vector<ll> A(N);
    ll total = 0;
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
        total += A[i];
    }
    ll remaining = K - total;

    if (M == N) {
        // All candidates will be elected regardless of additional votes
        for (int i = 0; i < N; ++i) {
            cout << 0 << (i == N-1 ? '\n' : ' ');
        }
        return 0;
    }

    // Make a copy and sort the original votes
    vector<ll> sorted_A = A;
    sort(sorted_A.begin(), sorted_A.end());

    vector<ll> ans(N, -1);
    for (int i = 0; i < N; ++i) {
        // The threshold is sorted_A[N - M], since we need to be >= this value
        // to have <= M-1 candidates with more votes
        ll threshold = sorted_A[N - M];
        if (A[i] >= threshold) {
            ans[i] = 0;  // Already meets the condition
        } else {
            ll needed = threshold - A[i];
            if (needed <= remaining) {
                ans[i] = needed;
            } else {
                ans[i] = -1;  // Not possible
            }
        }
    }

    for (int i = 0; i < N; ++i) {
        cout << ans[i] << (i == N-1 ? '\n' : ' ');
    }
    return 0;
}