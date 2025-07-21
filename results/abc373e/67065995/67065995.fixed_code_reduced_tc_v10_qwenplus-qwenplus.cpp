#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(), (x).end()

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    ll K;
    cin >> N >> M >> K;
    vector<ll> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
        K -= A[i];
    }

    // Create sorted version of A
    vector<pair<ll, int>> SA(N);
    for (int i = 0; i < N; ++i) {
        SA[i] = {A[i], i};
    }
    sort(all(SA));

    // Prepare prefix sums of sorted votes
    vector<ll> prefix(N + 1);
    for (int i = 0; i < N; ++i) {
        prefix[i + 1] = prefix[i] + SA[i].first;
    }

    vector<ll> res(N, -1);

    // For each candidate, binary search on minimum X
    for (int idx = 0; idx < N; ++idx) {
        ll a_i = SA[idx].first;
        int pos = idx; // current position in sorted list

        ll low = 0, high = K;
        ll answer = -1;

        while (low <= high) {
            ll mid = (low + high) / 2;
            ll new_vote = a_i + mid;

            // We need to ensure that at least (N - M) candidates have less than or equal to new_vote votes
            // Find how many candidates can have more than new_vote
            int max_stronger = M - 1;

            // Binary search the number of candidates with higher votes than new_vote
            int l = 0, r = N;
            while (l < r) {
                int m = (l + r) / 2;
                if (SA[m].first > new_vote) r = m;
                else l = m + 1;
            }
            int stronger = N - l;

            // If current candidate is among those counted above, we should not count them
            if (pos >= l) stronger--;

            if (stronger <= max_stronger) {
                // This X works, try smaller
                answer = mid;
                high = mid - 1;
            } else {
                // Need more votes
                low = mid + 1;
            }
        }

        res[SA[idx].second] = (answer == -1 ? -1 : answer);
    }

    for (int i = 0; i < N; ++i) {
        cout << res[i] << " ";
    }
    cout << "\n";
}