#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(), (x).end()

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
    vector<int> ord(N);
    iota(all(ord), 0);
    sort(all(ord), [&](int i, int j) { return A[i] < A[j]; });
    vector<ll> B(N);
    for (int i = 0; i < N; ++i) {
        B[i] = A[ord[i]];
    }
    vector<ll> prefix(N + 1);
    for (int i = 0; i < N; ++i) {
        prefix[i + 1] = prefix[i] + B[i];
    }
    vector<ll> ans(N, -1);
    for (int idx = 0; idx < N; ++idx) {
        ll low = 0, high = remaining;
        ll best_X = -1;
        while (low <= high) {
            ll mid = (low + high) / 2;
            ll new_vote = B[idx] + mid;
            int pos = upper_bound(all(B), new_vote) - B.begin();
            int needed = N - pos;
            if (needed < M) {
                best_X = mid;
                high = mid - 1;
            } else {
                ll required = 0;
                int start = pos;
                int end = N - (M - 1);
                if (start < end) {
                    required += (prefix[end] - prefix[start]) - new_vote * (end - start);
                }
                if (required <= remaining - mid) {
                    best_X = mid;
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            }
        }
        if (best_X != -1) {
            ans[ord[idx]] = best_X;
        } else {
            ans[ord[idx]] = -1;
        }
    }
    for (int i = 0; i < N; ++i) {
        cout << ans[i] << (i == N - 1 ? '\n' : ' ');
    }
    return 0;
}