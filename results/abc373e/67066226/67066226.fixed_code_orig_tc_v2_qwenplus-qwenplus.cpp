#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N, M;
    ll K;
    cin >> N >> M >> K;

    vector<ll> A(N);
    ll total_assigned = 0;
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
        total_assigned += A[i];
    }
    ll remaining = K - total_assigned;

    vector<int> idx(N);
    iota(idx.begin(), idx.end(), 0);
    sort(idx.begin(), idx.end(), [&](int x, int y) { return A[x] < A[y]; });

    vector<ll> sorted_A = A;
    sort(sorted_A.begin(), sorted_A.end());

    vector<ll> prefix(N + 1);
    for (int i = 0; i < N; ++i)
        prefix[i + 1] = prefix[i] + sorted_A[i];

    vector<ll> result(N, -1);

    for (int pos = 0; pos < N; ++pos) {
        ll low = 0, high = remaining;
        bool possible = false;
        ll answer = -1;

        while (low <= high) {
            ll mid = (low + high) / 2;
            ll target = sorted_A[pos] + mid;

            // Find how many candidates have more than target votes
            ll right = N - (upper_bound(sorted_A.begin(), sorted_A.end(), target) - sorted_A.begin());
            ll need = 0;

            // If more than M-1 candidates have higher votes, we must limit that
            if (right > M - 1) {
                // Only adjust the top M candidates who have more than target
                ll left = N - (lower_bound(sorted_A.begin(), sorted_A.end(), target + 1) - sorted_A.begin());
                ll adjust_start = N - left;
                ll adjust_end = N - right;

                need = (prefix[adjust_end] - prefix[adjust_start]) - (adjust_end - adjust_start) * (target + 1);
                need += mid;

                if (need <= remaining) {
                    answer = mid;
                    high = mid - 1;
                    possible = true;
                } else {
                    low = mid + 1;
                }
            } else {
                // Already good
                answer = 0;
                possible = true;
                high = mid - 1;
            }
        }

        if (possible)
            result[idx[pos]] = answer;
        else
            result[idx[pos]] = -1;
    }

    for (auto val : result)
        cout << max(0LL, val) << " ";
    cout << "\n";

    return 0;
}