#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

typedef long long ll;

bool can_win(const vector<ll>& votes, ll candidate_votes, int min_winners, ll remaining_votes) {
    int winners = 0;
    ll votes_to_win = votes.size() - 1 - vote_to_win;
    priority_queue<ll, vector<ll>, greater<ll>> pq;
    for (ll vote : votes) {
        pq.push(vote);
    }
    while (winners < min_winners && !pq.empty()) {
        candidate_votes += pq.top();
        pq.pop();
        if (pq.empty()) break;
        pq.push(pq.top() - 1);
        pq.pop();
        winners++;
    }
    return candidate_votes >= votes_to_win;
}

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<ll> votes(n);
    for (int i = 0; i < n; ++i) {
        cin >> votes[i];
    }

    // First, sort the votes to help determine the threshold for winning
    sort(votes.begin(), votes.end());

    // Calculate the votes that are needed to win based on the top M votes
    ll votes_needed_to_win = votes[m - 1];

    // Only calculate if the votes to win are less than the remaining votes
    if (votes_needed_to_win <= k) {
        for (ll i = 0; i < n; ++i) {
            // Calculate the additional votes needed for current candidate
            if (votes[i] < votes_needed_to_win && votes_needed_to_win - votes[i] <= k - votes.size() + i) {
                // Check if the candidate can guarantee a win
                if (can_win(votes, votes[i] + votes_needed_to_win - votes[i], votes_needed_to_win, k - votes.size() + i)) {
                    cout << votes_needed_to_win - votes[i] << " ";
                } else {
                    cout << -1 << " ";
                }
            } else {
                cout << 0 << " ";
            }
        }
    } else {
        for (int i = 0; i < n; ++i) {
            cout << -1 << " ";
        }
    }

    return 0;
}