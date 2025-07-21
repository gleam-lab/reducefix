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
    sort(all(ord), [&](int i, int j) { return A[i] < A[j]; });
    vector<ll> sorted_A(N);
    for (int i = 0; i < N; ++i) {
        sorted_A[i] = A[ord[i]];
    }

    vector<ll> pref(N + 1);
    for (int i = 0; i < N; ++i) {
        pref[i + 1] = pref[i] + sorted_A[i];
    }

    vector<ll> ans(N, -1);
    for (int idx = 0; idx < N; ++idx) {
        ll current = sorted_A[idx];
        ll low = 0, high = remaining;
        ll best_X = -1;
        while (low <= high) {
            ll mid = (low + high) / 2;
            ll new_votes = current + mid;
            int pos = upper_bound(all(sorted_A), new_votes) - sorted_A.begin();
            int needed = N - pos;
            if (needed < M) {
                best_X = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        if (best_X != -1) {
            int pos = upper_bound(all(sorted_A), current + best_X) - sorted_A.begin();
            if (pos <= N - M) {
                best_X = -1;
            } else {
                ll sum_required = 0;
                int start = N - M;
                if (pos > start) {
                    sum_required = (current + best_X + 1) * (pos - start) - (pref[pos] - pref[start]);
                }
                if (sum_required <= remaining) {
                    ans[ord[idx]] = best_X;
                } else {
                    best_X = -1;
                }
            }
        }
        if (best_X == -1) {
            ans[ord[idx]] = -1;
        }
    }

    for (int i = 0; i < N; ++i) {
        if (ans[i] == -1) {
            int count = 0;
            for (int j = 0; j < N; ++j) {
                if (A[j] > A[i]) {
                    count++;
                }
            }
            if (count < M) {
                ans[i] = 0;
            } else {
                ans[i] = -1;
            }
        }
    }

    for (int i = 0; i < N; ++i) {
        cout << ans[i] << ' ';
    }
    cout << endl;

    return 0;
}