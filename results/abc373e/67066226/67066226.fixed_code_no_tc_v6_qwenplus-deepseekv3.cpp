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
    ll sum_A = 0;
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
        sum_A += A[i];
    }
    ll remaining = K - sum_A;
    vector<int> ord(N);
    iota(all(ord), 0);
    sort(all(ord), [&](int i, int j) { return A[i] > A[j]; });
    vector<ll> sorted_A(N);
    for (int i = 0; i < N; ++i) {
        sorted_A[i] = A[ord[i]];
    }
    vector<ll> prefix(N + 1, 0);
    for (int i = 0; i < N; ++i) {
        prefix[i + 1] = prefix[i] + sorted_A[i];
    }
    vector<ll> ans(N, -1);
    for (int idx = 0; idx < N; ++idx) {
        int i = ord[idx];
        ll l = 0, r = remaining;
        ll best_X = -1;
        while (l <= r) {
            ll mid = (l + r) / 2;
            ll new_vote = A[i] + mid;
            int pos = upper_bound(all(sorted_A), new_vote, greater<ll>()) - sorted_A.begin();
            if (pos < M) {
                ll required = 0;
                if (M - 1 >= pos) {
                    required = (M - 1 - pos) * new_vote - (prefix[M - 1] - prefix[pos]);
                }
                if (required <= remaining - mid) {
                    best_X = mid;
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }
            } else {
                l = mid + 1;
            }
        }
        if (best_X != -1) {
            ans[i] = best_X;
        } else if (idx < M) {
            ans[i] = 0;
        }
    }
    for (int i = 0; i < N; ++i) {
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}