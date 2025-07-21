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
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    vector<int> ord(N);
    iota(all(ord), 0);
    sort(all(ord), [&](int i, int j) { return A[i] < A[j]; });
    vector<ll> sorted_A = A;
    sort(all(sorted_A));
    vector<ll> prefix(N + 1);
    for (int i = 0; i < N; ++i) {
        prefix[i + 1] = prefix[i] + sorted_A[i];
    }
    vector<ll> ans(N, -1);
    for (int idx = 0; idx < N; ++idx) {
        ll current = sorted_A[idx];
        ll low = 0, high = K + sorted_A[idx];
        ll best_X = -1;
        while (low <= high) {
            ll mid = (low + high) / 2;
            ll new_votes = current + mid;
            ll position = upper_bound(all(sorted_A), new_votes) - sorted_A.begin() - 1;
            position = N - position - 1;
            if (position < M) {
                best_X = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        if (best_X != -1) {
            ll total_remaining = K - (prefix[N] - prefix[0]);
            if (best_X <= total_remaining) {
                ans[ord[idx]] = best_X;
            } else {
                ans[ord[idx]] = -1;
            }
        } else {
            ans[ord[idx]] = -1;
        }
    }
    for (ll x : ans) {
        cout << x << ' ';
    }
    cout << '\n';
    return 0;
}