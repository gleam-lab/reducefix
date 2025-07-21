#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(), (x).end()

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, M;
    ll K;
    cin >> N >> M >> K;
    vector<ll> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    vector<int> ord(N);
    iota(all(ord), 0);
    sort(all(ord), [&](int i, int j) { return A[i] < A[j]; });
    vector<ll> B(N);
    for (int i = 0; i < N; ++i) {
        B[i] = A[ord[i]];
    }
    vector<ll> pref(N + 1);
    for (int i = 0; i < N; ++i) {
        pref[i + 1] = pref[i] + B[i];
    }
    vector<ll> ans(N, -1);
    ll total_votes = accumulate(all(A), 0LL);
    ll remaining = K - total_votes;
    if (remaining < 0) {
        remaining = 0;
    }
    for (int idx = 0; idx < N; ++idx) {
        int i = ord[idx];
        ll low = 0, high = remaining;
        ll best_X = -1;
        while (low <= high) {
            ll mid = (low + high) / 2;
            ll new_Ai = B[idx] + mid;
            int pos = upper_bound(all(B), new_Ai) - B.begin();
            int required = max(0, N - M);
            if (pos > required) {
                ll sum = pref[pos] - pref[required];
                ll needed = new_Ai * (pos - required) - sum;
                if (needed <= remaining - mid) {
                    best_X = mid;
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            } else {
                best_X = mid;
                high = mid - 1;
            }
        }
        if (best_X != -1) {
            ans[i] = best_X;
        }
    }
    for (int i = 0; i < N; ++i) {
        cout << ans[i] << ' ';
    }
    cout << endl;
    return 0;
}