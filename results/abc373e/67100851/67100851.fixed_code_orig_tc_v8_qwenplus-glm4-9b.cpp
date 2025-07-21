#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

typedef long long ll;

int main() {
    int N, M;
    ll K;
    cin >> N >> M >> K;

    vector<pair<ll, int>> votes(N);
    for (int i = 0; i < N; ++i) {
        cin >> votes[i].first;
        votes[i].second = i;
    }

    // Sort candidates based on the number of votes
    sort(votes.rbegin(), votes.rend());

    vector<ll> remaining_votes(N);
    for (int i = 0; i < M; ++i) {
        remaining_votes[i] = votes[i].first;
    }

    // Binary search for minimum votes needed
    for (int i = 0; i < N; ++i) {
        // Initialize binary search bounds
        ll low = 0, high = K - remaining_votes[i] + votes[i].first + 1;
        ll min_votes_needed = -1;

        while (low < high) {
            ll mid = (low + high + 1) / 2;
            ll needed = mid - remaining_votes[i];

            // Check if candidate can win with this number of votes
            bool can_win = true;
            for (int j = 0; j < N; ++j) {
                if (i != j) {
                    ll votes_for_other = min(needed, votes[j].first);
                    if (votes[j].first - votes_for_other < votes[i].first) {
                        can_win = false;
                        break;
                    }
                }
            }

            if (can_win) {
                min_votes_needed = needed;
                high = mid - 1;
            } else {
                low = mid;
            }
        }

        if (min_votes_needed == -1) {
            cout << -1 << " ";
        } else {
            cout << min_votes_needed << " ";
        }
    }

    cout << endl;
    return 0;
}