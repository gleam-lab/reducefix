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
    vector<ll> sortedA(N);
    for (int i = 0; i < N; ++i) {
        sortedA[i] = A[ord[i]];
    }

    vector<ll> prefix(N + 1);
    for (int i = 0; i < N; ++i) {
        prefix[i + 1] = prefix[i] + sortedA[i];
    }

    vector<ll> ans(N, -1);
    for (int i = 0; i < N; ++i) {
        ll current = sortedA[i];
        ll low = 0, high = remaining + current;
        ll res = -1;
        while (low <= high) {
            ll mid = (low + high) / 2;
            ll new_votes = current + mid;

            int pos = upper_bound(all(sortedA), new_votes) - sortedA.begin();
            int needed_pos = N - M;
            if (i >= needed_pos) {
                needed_pos = N - M;
            } else {
                needed_pos = N - M - 1;
            }

            if (pos <= needed_pos) {
                low = mid + 1;
                continue;
            }

            ll sum_extra = 0;
            if (needed_pos >= 0) {
                sum_extra = new_votes * (pos - needed_pos) - (prefix[pos] - prefix[needed_pos]);
            } else {
                sum_extra = new_votes * pos - prefix[pos];
            }

            if (sum_extra <= remaining) {
                res = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        ans[ord[i]] = res;
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