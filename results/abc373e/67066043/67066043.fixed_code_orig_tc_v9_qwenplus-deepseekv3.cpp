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

    if (M == N) {
        for (int i = 0; i < N; ++i) {
            cout << 0 << ' ';
        }
        cout << '\n';
        return 0;
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
        pref[i + 1] = B[i] + pref[i];
    }

    vector<ll> ans(N, -1);
    for (int i = 0; i < N; ++i) {
        ll low = 0, high = remaining;
        ll best = -1;
        while (low <= high) {
            ll mid = (low + high) / 2;
            ll new_votes = B[i] + mid;
            int pos = upper_bound(all(B), new_votes) - B.begin();
            int needed = max(0, (N - M) - (N - pos));
            if (needed <= 0) {
                best = mid;
                high = mid - 1;
                continue;
            }
            ll sum = 0;
            int start = pos - needed;
            if (start < 0) {
                low = mid + 1;
                continue;
            }
            sum = needed * new_votes - (pref[pos] - pref[start]);
            if (sum <= remaining - mid) {
                best = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        ans[ord[i]] = best;
    }

    for (int i = 0; i < N; ++i) {
        cout << (ans[i] == -1 ? -1 : max(0LL, ans[i])) << ' ';
    }
    cout << '\n';
    return 0;
}