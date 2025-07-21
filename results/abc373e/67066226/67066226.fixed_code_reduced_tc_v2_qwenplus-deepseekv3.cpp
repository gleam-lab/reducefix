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
    if (remaining < 0) {
        remaining = 0;
    }

    vector<int> ord(N);
    iota(all(ord), 0);
    sort(all(ord), [&](int i, int j) { return A[i] < A[j]; });
    vector<ll> sortedA = A;
    sort(all(sortedA));

    vector<ll> prefix(N + 1);
    for (int i = 0; i < N; ++i) {
        prefix[i + 1] = sortedA[i] + prefix[i];
    }

    vector<ll> ans(N, -1);
    for (int idx = 0; idx < N; ++idx) {
        int i = ord[idx];
        ll low = 0;
        ll high = remaining;
        ll best = -1;
        while (low <= high) {
            ll mid = (low + high) / 2;
            ll new_votes = A[i] + mid;
            int pos = upper_bound(all(sortedA), new_votes) - sortedA.begin();
            int need_to_beat = N - M;
            if (pos > need_to_beat) {
                best = mid;
                high = mid - 1;
                continue;
            }
            ll required = 0;
            int start = need_to_beat;
            if (pos <= start) {
                required = (new_votes + 1) * (start - pos + 1) - (prefix[start + 1] - prefix[pos]);
            }
            if (required <= remaining - mid) {
                best = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        ans[i] = best;
    }

    for (int i = 0; i < N; ++i) {
        if (ans[i] == -1) {
            cout << -1 << ' ';
        } else {
            cout << ans[i] << ' ';
        }
    }
    cout << '\n';
    return 0;
}