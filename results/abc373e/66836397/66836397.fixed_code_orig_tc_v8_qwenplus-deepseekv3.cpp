#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll N, M, K;
    cin >> N >> M >> K;
    vector<ll> A(N);
    for (ll &a : A) cin >> a;
    
    ll total_votes = accumulate(A.begin(), A.end(), 0LL);
    ll remaining_votes = K - total_votes;

    vector<ll> sorted_A = A;
    sort(sorted_A.begin(), sorted_A.end());

    vector<ll> prefix(N + 1, 0);
    for (int i = 0; i < N; ++i) {
        prefix[i + 1] = prefix[i] + sorted_A[i];
    }

    for (int i = 0; i < N; ++i) {
        ll current = A[i];
        ll left = 0, right = remaining_votes;
        ll answer = -1;

        while (left <= right) {
            ll mid = left + (right - left) / 2;
            ll new_votes = current + mid;
            
            // Find the position in the sorted array where new_votes would fit
            auto it = upper_bound(sorted_A.begin(), sorted_A.end(), new_votes);
            ll pos = it - sorted_A.begin();
            ll rank = N - pos; // number of candidates strictly greater than new_votes

            if (rank < M) {
                // The candidate is in the top M
                // Now check if it's possible to distribute the remaining votes (remaining_votes - mid)
                // such that the candidate remains in the top M
                // The worst case is to give as many votes as possible to candidates just below new_votes
                ll required = 0;
                if (rank < M - 1) {
                    // We need to ensure there are at least M - 1 - rank candidates with votes >= new_votes
                    // So, need to lift some candidates to new_votes
                    ll needed = (M - 1) - rank;
                    if (pos - needed >= 0) {
                        ll sum_lifted = prefix[pos] - prefix[pos - needed];
                        required = needed * new_votes - sum_lifted;
                    } else {
                        required = LLONG_MAX;
                    }
                }
                if (required <= remaining_votes - mid) {
                    answer = mid;
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            } else {
                left = mid + 1;
            }
        }

        cout << answer << " \n"[i == N - 1];
    }

    return 0;
}