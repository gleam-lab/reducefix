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
        int i = ord[idx];
        ll remaining = K - accumulate(all(A), 0LL);
        ll low = 0, high = remaining + A[i];
        ll best = -1;
        while (low <= high) {
            ll mid = (low + high) / 2;
            ll new_Ai = A[i] + mid;
            int pos = upper_bound(all(sorted_A), new_Ai) - sorted_A.begin();
            if (pos >= N - M + 1) {
                best = mid;
                high = mid - 1;
            } else {
                ll required = sorted_A[pos] * (N - M + 1 - pos) - (prefix[N - M + 1] - prefix[pos]);
                if (mid + required <= remaining) {
                    best = mid;
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            }
        }
        if (best != -1) {
            ans[i] = best;
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
            }
        }
    }
    for (int i = 0; i < N; ++i) {
        cout << ans[i] << ' ';
    }
    cout << endl;
    return 0;
}