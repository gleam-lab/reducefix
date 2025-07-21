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
    ll sum_A = accumulate(all(A), 0LL);
    ll remaining_votes = K - sum_A;
    
    vector<int> order(N);
    iota(all(order), 0);
    sort(all(order), [&](int i, int j) { return A[i] < A[j]; });
    vector<ll> sorted_A(N);
    for (int i = 0; i < N; ++i) {
        sorted_A[i] = A[order[i]];
    }
    vector<ll> prefix(N + 1, 0);
    for (int i = 0; i < N; ++i) {
        prefix[i + 1] = prefix[i] + sorted_A[i];
    }
    
    vector<ll> ans(N, -1);
    for (int idx = 0; idx < N; ++idx) {
        int i = order[idx];
        ll low = 0, high = remaining_votes;
        ll best_X = -1;
        while (low <= high) {
            ll mid = (low + high) / 2;
            ll new_votes = sorted_A[idx] + mid;
            int pos = upper_bound(all(sorted_A), new_votes) - sorted_A.begin();
            if (pos >= N - M + 1) {
                best_X = mid;
                high = mid - 1;
            } else {
                ll needed = 0;
                int start = N - M;
                if (start < idx) start = idx;
                needed = (new_votes + 1) * (N - start) - (prefix[N] - prefix[start]);
                if (needed <= remaining_votes - mid) {
                    best_X = mid;
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            }
        }
        ans[i] = best_X;
    }
    
    for (int i = 0; i < N; ++i) {
        if (ans[i] != -1 && ans[i] < 0) ans[i] = 0;
        cout << ans[i] << ' ';
    }
    cout << '\n';
    return 0;
}