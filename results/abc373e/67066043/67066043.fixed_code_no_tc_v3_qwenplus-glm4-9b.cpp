#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(), (x).end()

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    ll k;
    cin >> n >> m >> k;
    vector<ll> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        k -= a[i];
    }

    // If m is 1, we need to find the top candidate and ensure they have the most votes.
    // Otherwise, sort and determine the minimum votes needed to secure a place in the top m.
    vector<ll> sorted_a(a);
    sort(all(sorted_a));
    ll min_votes_needed = min_votes_needed = sorted_a[n - m];

    for(int i = 0; i < n; i++) {
        if(a[i] == min_votes_needed) {
            // If the candidate already has the minimum votes needed, they are guaranteed to be elected
            // with the current votes and the rest of the votes.
            cout << 0 << ' ';
        } else {
            // Calculate the number of votes the candidate needs to reach the minimum votes needed
            ll votes_needed = min_votes_needed - a[i];
            if(votes_needed > k) {
                // If the candidate cannot reach the minimum votes needed even with all remaining votes,
                // then they cannot be elected.
                cout << -1 << ' ';
            } else {
                // Otherwise, print the number of votes needed.
                cout << votes_needed << ' ';
                k -= votes_needed;
            }
        }
    }

    return 0;
}