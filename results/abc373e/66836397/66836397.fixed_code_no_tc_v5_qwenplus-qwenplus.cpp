#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define rep(i, x, limit) for (int i = (x); i < (limit); i++)

void solve() {
    ll N, M, K;
    cin >> N >> M >> K;
    vector<ll> A(N);
    ll total = 0;
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
        total += A[i];
    }
    ll rem = K - total;

    // Create sorted version of A
    vector<ll> sortedA = A;
    sort(sortedA.begin(), sortedA.end());
    
    // Prefix sum of sortedA
    vector<ll> prefix(N + 1, 0);
    for (int i = 0; i < N; ++i)
        prefix[i + 1] = prefix[i] + sortedA[i];

    // For each candidate, binary search on required additional votes
    vector<ll> result(N);
    rep(i, 0, N) {
        ll base = A[i];
        ll low = 0, high = rem;
        ll ans = -1;

        while (low <= high) {
            ll mid = (low + high) / 2;
            ll new_vote = base + mid;

            // Binary search to find first candidate with votes > new_vote
            ll l = 0, r = N;
            while (l < r) {
                ll m = (l + r) / 2;
                if (sortedA[m] > new_vote)
                    r = m;
                else
                    l = m + 1;
            }
            ll pos = l; // Number of candidates <= new_vote

            // Need to ensure at most M-1 candidates have more than new_vote
            ll need_better = M - 1;
            if (need_better >= N - pos) {
                // Already enough candidates worse than us
                ans = mid;
                high = mid - 1;
            } else {
                // Need to reduce top (N - pos - need_better) candidates to <= new_vote
                ll target = N - need_better;
                if (target <= 0 || target > N) {
                    low = mid + 1;
                    continue;
                }

                // Compute how many votes needed to bring top (N - target) candidates down
                ll extra_needed = 0;
                ll idx = N - (N - pos - need_better);
                if (idx > 0) {
                    ll sum = prefix[N] - prefix[idx];
                    extra_needed = (N - idx) * new_vote - sum;
                }

                if (extra_needed <= rem - mid) {
                    ans = mid;
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            }
        }

        result[i] = (ans != -1) ? ans : -1;
    }

    for (int i = 0; i < N; ++i)
        cout << result[i] << " ";
    cout << "\n";
}

int main() {
    solve();
    return 0;
}