#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    ll k;
    cin >> n >> m >> k;
    
    vector<ll> a(n);
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
        k -= a[i];
    }

    // Sort the votes in ascending order
    sort(a.begin(), a.end());

    // Prefix sum array to store the total votes of the top m candidates
    vector<ll> pref(n + 1);
    for(int i = 0; i < n; ++i) {
        pref[i + 1] = pref[i] + a[i];
    }

    // Result vector to store the minimum number of additional votes needed for each candidate
    vector<ll> result(n, -1);

    for(int i = 0; i < n; ++i) {
        // Calculate the minimum additional votes needed for candidate i
        ll additional_votes = max(0LL, (a[n - m] - a[i]) + 1);
        
        // Check if the additional votes are within the remaining ballots
        if(additional_votes <= k) {
            result[i] = additional_votes;
        }
    }

    // Print the results
    for(ll val : result) {
        cout << val << " ";
    }

    return 0;
}