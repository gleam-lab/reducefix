#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int N, M;
    ll K;
    cin >> N >> M >> K;
    vector<ll> A(N);
    ll total = 0;
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
        total += A[i];
    }
    ll remaining = K - total;

    // Create list of (votes, index)
    vector<pair<ll, int>> candidates(N);
    for (int i = 0; i < N; ++i) {
        candidates[i] = {A[i], i};
    }

    // Sort by votes descending
    sort(candidates.rbegin(), candidates.rend());

    // Precompute prefix sums
    vector<ll> sorted_votes(N);
    for (int i = 0; i < N; ++i) {
        sorted_votes[i] = candidates[i].first;
    }

    vector<ll> prefix(N + 1, 0LL);
    for (int i = 0; i < N; ++i) {
        prefix[i + 1] = prefix[i] + sorted_votes[i];
    }

    vector<ll> res(N);

    for (int i = 0; i < N; ++i) {
        ll a_i = A[i];
        ll low = 0, high = remaining;
        bool possible = false;
        while (low <= high) {
            ll mid = (low + high) / 2;
            ll current_total = a_i + mid;

            // Binary search to find how many candidates have votes > current_total
            int left = 0, right = N;
            while (left < right) {
                int m = (left + right) / 2;
                if (sorted_votes[m] > current_total)
                    left = m + 1;
                else
                    right = m;
            }
            int strictly_greater = left;

            // We need to ensure at most M-1 candidates have more votes than i
            if (strictly_greater < M) {
                possible = true;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        if (!possible) {
            res[i] = -1;
        } else {
            res[i] = low;
        }
    }

    for (ll x : res) cout << x << " ";
    cout << endl;

    return 0;
}