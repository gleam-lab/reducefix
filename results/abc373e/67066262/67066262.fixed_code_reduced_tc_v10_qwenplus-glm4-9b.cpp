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
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
        k -= a[i];
    }
    
    // Sort candidates by the number of votes they currently have
    sort(a.begin(), a.end(), greater<>());

    // Find the candidate with the least votes among the top M candidates
    ll min_votes = a[m - 1];

    // Calculate the minimum votes needed to guarantee victory for each candidate
    vector<ll> ans(n, 0);
    for(int i = 0; i < n; ++i) {
        // Calculate the votes needed to at least match the least votes among the top M candidates
        ll needed_votes = min_votes - a[i];

        // If the candidate is among the top M, they need additional votes to stay in the top M
        if (i < m - 1) {
            ans[i] = needed_votes;
        } else if (i == m - 1) {
            // If the candidate is the M-th candidate, they need to at least match all top M candidates
            ll votes_needed = a[i] + 1 - min_votes;
            if (votes_needed > k) {
                ans[i] = -1; // Not enough votes to guarantee victory
            } else {
                ans[i] = needed_votes;
            }
        } else {
            // If the candidate is not in the top M, they need additional votes to get into the top M
            ll votes_needed = needed_votes + (m - 1 - i) * min_votes - a[i];
            if (votes_needed > k) {
                ans[i] = -1; // Not enough votes to guarantee victory
            } else {
                ans[i] = needed_votes;
            }
        }
    }

    // Output the results
    for(const auto& vote : ans) {
        cout << vote << ' ';
    }
    cout << '\n';

    return 0;
}