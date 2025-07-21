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
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    ll total_given = accumulate(A.begin(), A.end(), 0LL);
    ll remaining = K - total_given;

    vector<int> idx(N);
    iota(idx.begin(), idx.end(), 0);

    // Sort candidates by current votes
    sort(idx.begin(), idx.end(), [&](int x, int y) { return A[x] < A[y]; });
    vector<ll> sorted_A(N);
    for (int i = 0; i < N; ++i) {
        sorted_A[i] = A[idx[i]];
    }

    vector<ll> prefix_sum(N + 1);
    for (int i = 1; i <= N; ++i) {
        prefix_sum[i] = prefix_sum[i - 1] + sorted_A[i - 1];
    }

    vector<ll> result(N, -1);

    for (int i = 0; i < N; ++i) {
        int pos = i;
        ll my_votes = sorted_A[pos];

        ll low = 0, high = remaining;
        ll answer = -1;

        while (low <= high) {
            ll mid = (low + high) / 2;
            ll target = my_votes + mid;

            // Find how many candidates have votes > target
            int left = lower_bound(sorted_A.begin(), sorted_A.end(), target + 1) - sorted_A.begin();

            // If at most M-1 other candidates have more votes, candidate i wins
            if (N - left <= M - 1) {
                answer = mid;
                high = mid - 1;
            } else {
                // Otherwise, calculate how many extra votes are needed to reduce the number of stronger candidates
                ll need = 0;
                int right_limit = min(N, left + M);
                for (int j = left; j < right_limit && j < N; ++j) {
                    need += (target + 1 - sorted_A[j]);
                }
                if (need <= remaining - mid) {
                    answer = mid;
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            }
        }

        if (answer != -1 && answer <= remaining) {
            result[idx[pos]] = max<ll>(0, answer);
        } else {
            result[idx[pos]] = -1;
        }
    }

    for (ll val : result) {
        cout << (val == -1 ? -1 : 0) << " ";
    }

    return 0;
}