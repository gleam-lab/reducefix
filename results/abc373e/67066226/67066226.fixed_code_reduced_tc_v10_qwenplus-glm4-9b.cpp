#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m, k;
    cin >> n >> m >> k;
    vector<ll> votes(n);
    ll total_votes_given = 0;

    for (int i = 0; i < n; ++i) {
        cin >> votes[i];
        total_votes_given += votes[i];
    }

    ll votes_needed_to_win = votes[n - 1] + m - 1; // votes of the current leader + m - 1
    vector<pair<ll, int>> candidates(n);
    for (int i = 0; i < n; ++i) {
        candidates[i] = {votes[i], i};
    }
    sort(candidates.begin(), candidates.end(), greater<pair<ll, int>>());

    vector<ll> votes_needed_to_win_each(n, votes_needed_to_win);
    vector<ll> answers(n, numeric_limits<ll>::max());

    for (int i = 0; i < n; ++i) {
        ll votes_needed = votes_needed_to_win_each[i] - votes[candidates[i].second];
        if (votes_needed <= 0) {
            answers[candidates[i].second] = 0;
            continue;
        }
        ll votes_remaining = k - total_votes_given;
        if (votes_needed <= votes_remaining) {
            answers[candidates[i].second] = votes_needed;
        } else {
            answers[candidates[i].second] = -1;
        }
    }

    for (ll answer : answers) {
        cout << answer << ' ';
    }
    cout << '\n';

    return 0;
}