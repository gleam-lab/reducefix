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
    if (M == N) {
        for (int i = 0; i < N; ++i) {
            cout << 0 << " \n"[i == N-1];
        }
        return 0;
    }
    vector<int> ord(N);
    iota(ord.begin(), ord.end(), 0);
    sort(ord.begin(), ord.end(), [&](int i, int j) { return A[i] > A[j]; });
    vector<ll> sorted_A(N);
    for (int i = 0; i < N; ++i) {
        sorted_A[i] = A[ord[i]];
    }
    vector<ll> suffix_sum(N + 1);
    for (int i = N - 1; i >= 0; --i) {
        suffix_sum[i] = suffix_sum[i + 1] + sorted_A[i];
    }
    vector<ll> ans(N);
    for (int i = 0; i < N; ++i) {
        int rank = i + 1;
        if (rank <= M) {
            ans[ord[i]] = 0;
        } else {
            ll required = sorted_A[M - 1] - A[ord[i]] + 1;
            if (required <= K - total) {
                ans[ord[i]] = max(0LL, required);
            } else {
                ans[ord[i]] = -1;
            }
        }
    }
    for (int i = 0; i < N; ++i) {
        cout << ans[i] << " \n"[i == N-1];
    }
    return 0;
}