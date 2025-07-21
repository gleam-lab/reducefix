#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll n, m, k;
    cin >> n >> m >> k;
    vector<ll> a(n);
    for (ll i = 0; i < n; i++) {
        cin >> a[i];
        k -= a[i];
    }
    vector<pair<ll, ll>> indexed_a(n);
    for (ll i = 0; i < n; i++) {
        indexed_a[i] = {a[i], i};
    }
    // Sort by votes, then by index
    sort(indexed_a.begin(), indexed_a.end(), [](const pair<ll, ll>& a, const pair<ll, ll>& b) {
        return a.first > b.first || (a.first == b.first && a.second < b.second);
    });
    vector<ll> votes_needed(n, -1);
    for (ll i = 0; i < n; i++) {
        if (i < m) {
            // If already in top M, no votes needed
            votes_needed[indexed_a[i].second] = 0;
        } else {
            ll required_votes = indexed_a[m-1].first - indexed_a[i].first + 1;
            if (k >= required_votes) {
                votes_needed[indexed_a[i].second] = required_votes;
                k -= required_votes;
            } else {
                votes_needed[indexed_a[i].second] = -1;
            }
        }
    }
    for (ll i = 0; i < n; i++) {
        cout << votes_needed[i] << " ";
    }
    cout << endl;
    return 0;
}