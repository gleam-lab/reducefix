#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    ll K;
    cin >> N >> M >> K;
    
    vector<ll> A(N);
    ll total = 0;
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
        total += A[i];
    }
    ll rem = K - total;

    // Sort the array to help determine relative positions efficiently
    vector<ll> sorted_A = A;
    sort(sorted_A.begin(), sorted_A.end());

    // Prefix sum of sorted votes
    vector<ll> prefix(N + 1, 0);
    for (int i = 0; i < N; ++i)
        prefix[i + 1] = prefix[i] + sorted_A[i];

    vector<int> result(N);

    for (int i = 0; i < N; ++i) {
        ll orig = A[i];

        // Binary search for minimum X such that candidate i is elected
        ll left = 0, right = rem + 1;
        bool possible = false;

        while (left < right) {
            ll mid = (left + right) / 2;
            ll new_score = orig + mid;

            // Count how many candidates already have strictly more than new_score
            int cnt = N - (upper_bound(sorted_A.begin(), sorted_A.end(), new_score) - sorted_A.begin());

            if (cnt < M) {
                // Already enough
                possible = true;
                right = mid;
            } else {
                // Need to eliminate at least (cnt - (M - 1)) candidates with higher scores
                ll need_to_eliminate = cnt - (M - 1);
                ll l = 0, r = N;
                while (l < r) {
                    ll m = (l + r) / 2;
                    if (sorted_A[m] > new_score)
                        r = m;
                    else
                        l = m + 1;
                }

                // Start from index l, and try to reduce scores of top 'need_to_eliminate' candidates
                ll start_idx = N - need_to_eliminate;
                ll required = 0;

                for (ll j = start_idx; j < N; ++j) {
                    ll extra = max(0LL, sorted_A[j] - new_score + 1);
                    required += extra;
                }

                if (required <= rem - mid) {
                    possible = true;
                    right = mid;
                } else {
                    left = mid + 1;
                }
            }
        }

        if (possible && left <= rem)
            result[i] = left;
        else
            result[i] = -1;
    }

    for (int i = 0; i < N; ++i) {
        cout << result[i];
        if (i != N - 1)
            cout << " ";
    }
    cout << "\n";
}