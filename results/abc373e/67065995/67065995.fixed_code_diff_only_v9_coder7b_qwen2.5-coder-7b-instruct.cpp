#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(), (x).end()

int main() {
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

    // Sort the votes in ascending order
    vector<ll> sorted_a(a);
    sort(sorted_a.begin(), sorted_a.end());

    // Calculate the prefix sum of sorted votes
    vector<ll> pref(n + 1);
    for(int i = 0; i < n; i++) {
        pref[i + 1] = sorted_a[i] + pref[i];
    }

    // Initialize the answer array with -1
    vector<ll> ans(n, -1);

    // For each candidate, determine the minimum number of additional votes needed
    for(int i = 0; i < n; i++) {
        // Calculate the maximum number of votes the ith candidate can get
        ll max_votes = a[i];
        
        // Determine the rank of the ith candidate in terms of total votes
        int rank = upper_bound(sorted_a.begin(), sorted_a.end(), a[i]) - sorted_a.begin();
        
        // If the rank is greater than or equal to N-M, no additional votes are needed
        if(rank >= n - m) {
            ans[i] = 0;
            continue;
        }
        
        // Binary search to find the minimum number of additional votes needed
        ll left = 0, right = k + 1;
        while(left < right) {
            ll mid = (left + right) / 2;
            ll total_votes = a[i] + mid;
            
            // Calculate the number of votes the Mth candidate will have
            ll mth_candidate_votes = sorted_a[n - m] + mid;
            
            // Calculate the number of votes other candidates will have at most
            ll other_candidates_votes = pref[n] - pref[rank] - mid * (n - rank);
            
            // Check if the current candidate can win
            if(total_votes > mth_candidate_votes || other_candidates_votes < mth_candidate_votes) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        
        // Assign the result to the answer array
        if(left != k + 1) {
            ans[i] = left;
        }
    }

    // Output the results
    for(auto i : ans) cout << i << ' ';
    
    return 0;
}