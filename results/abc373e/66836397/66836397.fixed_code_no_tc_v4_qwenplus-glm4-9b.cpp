#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    long long n, m, K;
    cin >> n >> m >> K;
    vector<long long> a(n);
    long long total_votes = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        total_votes += a[i];
    }

    vector<long long> sorted_a(a);
    sort(sorted_a.begin(), sorted_a.end());

    vector<long long> min_votes_needed(n, 0);

    for (int i = 0; i < n; ++i) {
        int candidates_being_beaten = n - i - 1;
        if (candidates_being_beaten < m) {
            min_votes_needed[i] = -1; // Cannot win as we need at least m candidates to beat.
            continue;
        }

        long long votes_needed = 0;
        // We need to ensure that even in the worst case scenario (all remaining votes go to the next top candidates),
        // our candidate can still beat m-1 candidates.
        long long k = min(m - 1, candidates_being_beaten);
        long long votes_to_beat = sorted_a[i + k]; // Votes of the k-th candidate in the sorted list.

        // We need (votes_needed + a[i]) + (K - total_votes - (votes_needed + a[i])) >= votes_to_beat
        // Simplifies to: votes_needed + a[i] >= votes_to_beat
        votes_needed = max(0LL, votes_to_beat - a[i]);

        // We need to ensure that votes_needed does not exceed the remaining K - total_votes
        if (votes_needed > K - total_votes) {
            min_votes_needed[i] = -1;
        } else {
            min_votes_needed[i] = votes_needed;
        }
    }

    for (int i = 0; i < n; ++i) {
        if (min_votes_needed[i] == -1) {
            cout << -1 << " ";
        } else {
            cout << min_votes_needed[i] << " ";
        }
    }
    cout << endl;

    return 0;
}