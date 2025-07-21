#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll n, m, k;
    cin >> n >> m >> k;
    vector<ll> votes(n);
    ll total_votes = 0;
    for (ll &v : votes) {
        cin >> v;
        total_votes += v;
    }

    if (m == n) {
        // If the number of winners is equal to the number of candidates, all need at least one more vote
        vector<ll> result(n, 1);
        for (ll i = 0; i < n; ++i) {
            result[i] = votes[i] == 0 ? 1 : 0;
        }
        for (ll i = 0; i < n; ++i) {
            if (result[i] == 0) {
                k -= votes[i] == 0 ? 1 : 0;  // If candidate i has 0 votes, we need 1 more
                result[i] = 1;
                if (k < 0) break;
            }
        }
        for (ll &r : result) {
            cout << (r ? 1 : -1) << " ";
        }
        cout << endl;
        return 0;
    }

    vector<pair<ll, ll>> candidates;
    for (ll i = 0; i < n; ++i) {
        candidates.emplace_back(votes[i], i);
    }
    
    sort(candidates.begin(), candidates.end(), [](const pair<ll, ll> &a, const pair<ll, ll> &b) {
        if (a.first == b.first) {
            return a.second < b.second;
        }
        return a.first < b.first;
    });

    vector<ll> remaining_votes(k);
    iota(remaining_votes.begin(), remaining_votes.end(), 1);
    
    vector<ll> result(n, -1);
    ll required_votes = 0;

    for (ll i = 0; i < n; ++i) {
        required_votes = candidates[i].first + (n - m) + 1; // Minimum votes to guarantee victory
        if (required_votes <= k) {
            result[candidates[i].second] = required_votes - candidates[i].first;
        }
    }

    for (ll &r : result) {
        cout << r << " ";
    }
    cout << endl;

    return 0;
}