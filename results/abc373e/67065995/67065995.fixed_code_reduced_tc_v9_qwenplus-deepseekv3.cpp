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
    sort(all(ord), [&](int i, int j) { return A[i] > A[j]; });
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
        int original_pos = ord[idx];
        
        ll low = 0;
        ll high = remaining;
        ll min_X = -1;
        while (low <= high) {
            ll mid = (low + high) / 2;
            ll new_votes = current + mid;

            int left = 0;
            int right = N;
            while (left < right) {
                int mid_pos = (left + right) / 2;
                if (sorted_A[mid_pos] > new_votes) {
                    left = mid_pos + 1;
                } else {
                    right = mid_pos;
                }
            }
            int rank = left;
            if (rank < M) {
                min_X = mid;
                high = mid - 1;
            } else {
                ll needed = 0;
                if (M > 0) {
                    needed = (new_votes + 1) * (rank - M + 1) - (prefix[rank + 1] - prefix[M]);
                }
                if (needed <= remaining - mid) {
                    min_X = mid;
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            }
        }
        ans[original_pos] = (min_X != -1) ? min_X : -1;
    }
    
    for (int i = 0; i < N; ++i) {
        cout << ans[i] << ' ';
    }
    cout << '\n';
    return 0;
}