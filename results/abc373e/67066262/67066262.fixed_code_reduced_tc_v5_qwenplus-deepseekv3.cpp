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
    vector<ll> prefix(N + 1, 0);
    for (int i = 0; i < N; ++i) {
        prefix[i + 1] = prefix[i] + sorted_A[i];
    }
    vector<ll> ans(N, -1);
    ll remaining = K - accumulate(all(A), 0LL);
    for (int idx = 0; idx < N; ++idx) {
        int i = ord[idx];
        ll low = 0, high = remaining + A[i];
        ll best = -1;
        while (low <= high) {
            ll mid = (low + high) / 2;
            ll new_votes = A[i] + mid;
            int pos = upper_bound(all(sorted_A), new_votes) - sorted_A.begin();
            if (pos > N - M) {
                best = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        if (best != -1 && best <= remaining) {
            ans[i] = best;
        } else if (A[i] + remaining >= sorted_A[N - M]) {
            ans[i] = max(0LL, sorted_A[N - M] - A[i] + 1);
            if (ans[i] <= remaining && ans[i] >= 0) {
                // Check if it's already secured
                if (A[i] >= sorted_A[N - M]) {
                    ans[i] = 0;
                }
            } else {
                ans[i] = -1;
            }
        } else {
            ans[i] = -1;
        }
    }
    for (int i = 0; i < N; ++i) {
        if (ans[i] == -1) {
            // Check if already elected
            int cnt = 0;
            for (int j = 0; j < N; ++j) {
                if (A[j] > A[i]) {
                    cnt++;
                }
            }
            if (cnt < M) {
                ans[i] = 0;
            }
        }
    }
    for (int i = 0; i < N; ++i) {
        cout << ans[i] << ' ';
    }
    return 0;
}