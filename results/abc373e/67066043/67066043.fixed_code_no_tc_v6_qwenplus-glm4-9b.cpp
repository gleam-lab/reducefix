#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<pair<long long, int>> candidates(n);
    for (int i = 0; i < n; ++i) {
        candidates[i] = {a[i], i};
    }
    sort(candidates.begin(), candidates.end(), [](const pair<long long, int>& a, const pair<long long, int>& b) {
        return a.first > b.first;
    });

    vector<long long> votes_needed(n, -1);
    long long remaining_votes = k;

    for (int i = 0; i < n; ++i) {
        if (i + 1 < n && a[candidates[i].second] == a[candidates[i + 1].second]) {
            continue; // Skip duplicates
        }
        
        if (n - i - 1 < m) {
            votes_needed[candidates[i].second] = 0; // They can win with existing votes
            remaining_votes -= a[candidates[i].second];
        } else {
            long long required_votes = m * a[candidates[i].second] - (i * a[candidates[i].second] - (m - 1) * a[candidates[i].second]);
            // Adjust the required votes if the remaining candidates don't need as many to exceed m
            required_votes -= max((n - i - 1 - m) * a[candidates[i].second], 0LL);
            votes_needed[candidates[i].second] = max(required_votes - remaining_votes, 0LL);
        }
        remaining_votes -= votes_needed[candidates[i].second];
    }

    for (long long vote_needed : votes_needed) {
        cout << vote_needed << ' ';
    }
    cout << endl;

    return 0;
}