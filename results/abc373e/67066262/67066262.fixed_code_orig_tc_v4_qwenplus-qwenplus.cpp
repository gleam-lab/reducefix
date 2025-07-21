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

    vector<int> idx(N);
    iota(all(idx), 0);
    sort(all(idx), [&](int a, int b) { return A[a] < A[b]; });
    
    vector<ll> sorted_A = A;
    sort(all(sorted_A));

    vector<ll> prefix_sum(N + 1);
    for (int i = 0; i < N; ++i) {
        prefix_sum[i + 1] = prefix_sum[i] + sorted_A[i];
    }

    vector<ll> C(N);

    for (int i = 0; i < N; ++i) {
        int pos = i;
        ll current = A[pos];
        
        // Binary search for the minimal X such that candidate i is guaranteed to win
        auto is_possible = [&](ll X) {
            ll total_needed = 0;
            ll upper = current + X;
            int j = N - 1;
            for (; j >= 0 && A[j] >= upper; --j); // skip those already above

            // Need to cap top M-1 candidates at or below upper
            int count = 0;
            while (count < M && j >= 0) {
                if (A[idx[j]] >= upper) {
                    ++count;
                    --j;
                    continue;
                }
                ll diff = upper - A[idx[j]];
                total_needed += diff;
                ++count;
                --j;
            }
            return total_needed <= K;
        };

        ll low = 0, high = K + 1;
        while (low < high) {
            ll mid = (low + high) / 2;
            if (is_possible(mid)) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }

        if (is_possible(low)) {
            C[pos] = low;
        } else {
            C[pos] = -1;
        }
    }

    for (auto &c : C) cout << c << ' ';
}