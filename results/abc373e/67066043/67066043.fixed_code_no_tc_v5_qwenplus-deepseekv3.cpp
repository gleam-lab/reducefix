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
    vector<ll> sorted_A = A;
    sort(all(sorted_A));

    vector<ll> prefix(N + 1);
    for (int i = 0; i < N; ++i) {
        prefix[i + 1] = prefix[i] + sorted_A[i];
    }

    vector<ll> ans(N, -1);
    for (int i = 0; i < N; ++i) {
        ll low = 0, high = remaining;
        ll best_X = -1;
        while (low <= high) {
            ll mid = (low + high) / 2;
            ll new_vote = sorted_A[i] + mid;
            
            // Find the first index where sorted_A[j] > new_vote
            auto it = upper_bound(all(sorted_A), new_vote);
            int cnt = sorted_A.end() - it;
            
            if (cnt < M) {
                best_X = mid;
                high = mid - 1;
            } else {
                int idx = it - sorted_A.begin();
                int needed = cnt - (M - 1);
                ll total_needed = 0;
                for (int j = idx; j < idx + needed; ++j) {
                    if (j >= N) break;
                    total_needed += (new_vote + 1 - sorted_A[j]);
                }
                if (total_needed <= remaining - mid) {
                    best_X = mid;
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            }
        }
        ans[ord[i]] = best_X != -1 ? best_X : -1;
    }

    for (int i = 0; i < N; ++i) {
        cout << ans[i] << ' ';
    }
    cout << '\n';
    return 0;
}