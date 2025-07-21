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
    ll total = accumulate(all(A), 0LL);
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
        ll current = sorted_A[idx];
        ll low = 0, high = remaining, best = -1;
        while (low <= high) {
            ll mid = (low + high) / 2;
            ll new_votes = current + mid;
            auto it = upper_bound(all(sorted_A), new_votes);
            int cnt = sorted_A.end() - it;
            if (cnt < M) {
                best = mid;
                high = mid - 1;
            } else {
                ll target_vote = new_votes + 1;
                it = lower_bound(all(sorted_A), target_vote);
                int pos = it - sorted_A.begin();
                int required = N - M;
                if (pos <= required) {
                    ll sum_extra = prefix[required + 1] - prefix[pos];
                    ll needed = (required + 1 - pos) * target_vote - sum_extra;
                    if (needed <= remaining - mid) {
                        best = mid;
                        high = mid - 1;
                    } else {
                        low = mid + 1;
                    }
                } else {
                    low = mid + 1;
                }
            }
        }
        ans[ord[idx]] = best;
    }
    for (int i = 0; i < N; ++i) {
        cout << ans[i] << ' ';
    }
    cout << endl;
    return 0;
}