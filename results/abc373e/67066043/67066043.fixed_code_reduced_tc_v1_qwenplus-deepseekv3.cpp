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
    vector<ll> sorted_A(N);
    for (int i = 0; i < N; ++i) {
        sorted_A[i] = A[ord[i]];
    }
    vector<ll> prefix(N + 1);
    for (int i = 0; i < N; ++i) {
        prefix[i + 1] = prefix[i] + sorted_A[i];
    }
    vector<ll> ans(N, -1);
    for (int idx = 0; idx < N; ++idx) {
        int i = ord[idx];
        ll l = 0, r = remaining;
        ll best = -1;
        while (l <= r) {
            ll mid = (l + r) / 2;
            ll new_votes = A[i] + mid;
            int pos = upper_bound(all(sorted_A), new_votes) - sorted_A.begin();
            int needed = max(0, N - M - (pos - (sorted_A[idx] <= new_votes ? 1 : 0)));
            if (needed <= 0) {
                ll sum = 0;
                if (N - M > 0) {
                    sum = prefix[N] - prefix[N - M] - (new_votes + 1) * M;
                }
                if (sum + mid <= remaining) {
                    best = mid;
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }
            } else {
                ll sum = 0;
                if (N - M - needed > 0) {
                    sum += prefix[N - M - needed] - prefix[0];
                }
                sum += (N - needed - (sorted_A[idx] <= new_votes ? 1 : 0)) * new_votes - (prefix[N - needed] - prefix[pos]);
                sum += mid;
                if (sum <= remaining) {
                    best = mid;
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }
            }
        }
        ans[i] = best;
    }
    for (int i = 0; i < N; ++i) {
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}