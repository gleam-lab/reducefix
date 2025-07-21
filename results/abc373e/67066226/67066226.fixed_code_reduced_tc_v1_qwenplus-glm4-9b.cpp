#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(), (x).end()

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    vector<ll> a(n);
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    // Calculate the number of votes each candidate needs to be guaranteed victory
    vector<ll> needed(n);
    for(int i = 0; i < n; ++i) {
        needed[i] = m - 1 + (i >= m ? 1 : 0) - a[i];
    }

    // Find the minimum number of additional votes needed for all candidates
    sort(needed.begin(), needed.end(), greater<ll>());
    ll votes_needed = needed[0] > 0 ? needed[0] : 0;
    for(int i = 1; i < n; ++i) {
        votes_needed = max(votes_needed, needed[i]);
    }

    // If the total votes needed are more than the remaining votes, it's impossible
    if(votes_needed > k) {
        for(int i = 0; i < n; ++i) {
            cout << -1 << ' ';
        }
    } else {
        // Calculate the number of additional votes for each candidate
        for(int i = 0; i < n; ++i) {
            if(needed[i] <= votes_needed) {
                cout << 0 << ' ';
            } else {
                cout << needed[i] - votes_needed << ' ';
            }
        }
    }
    return 0;
}