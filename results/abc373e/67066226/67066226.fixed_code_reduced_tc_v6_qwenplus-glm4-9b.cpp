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
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        k -= a[i];
    }
    
    // Sort candidates by number of votes received
    sort(a.begin(), a.end());
    
    // Calculate the minimum votes needed for each candidate to guarantee a win
    vector<ll> votes_needed(n, -1); // Initialize with -1 (indicating not enough votes)
    
    // Calculate the votes needed for each candidate to be in the top M
    for (int i = 0; i < n; i++) {
        if (i >= m) {
            ll votes_to_be_safe = 0; // Candidate needs to have more votes than all in the top M
            for (int j = m - 1; j >= i; j--) {
                votes_to_be_safe = max(votes_to_be_safe, a[j] + 1);
            }
            if (votes_needed[i] == -1 || (votes_needed[i] < votes_to_be_safe && votes_needed[i] >= 0)) {
                votes_needed[i] = votes_to_be_safe - a[i];
            }
        }
        
        // Check if they are already ahead of the Mth candidate
        if (i > m - 1 && (votes_needed[i] == -1 || votes_needed[i] > 0)) {
            votes_needed[i] = votes_needed[i] + a[m] - a[i];
            if (votes_needed[i] > k) {
                votes_needed[i] = -1;
            }
        }
    }
    
    // If there's enough votes left, check if we can still guarantee a win for any candidate
    if (k > 0) {
        for (int i = 0; i < n && k > 0; i++) {
            if (votes_needed[i] == -1) {
                ll additional_votes_needed = 0;
                int candidates_to_surpass = n - i - 1; // Remaining candidates
                if (candidates_to_surpass <= m - 1) {
                    additional_votes_needed = a[i] + 1 - a[n - candidates_to_surpass - 1];
                } else {
                    additional_votes_needed = (a[i] + 1 - a[n - m - 1]);
                }
                if (additional_votes_needed <= k) {
                    votes_needed[i] = additional_votes_needed;
                    k -= additional_votes_needed;
                }
            }
        }
    }
    
    // Output the results
    for (ll need : votes_needed) {
        cout << need << " ";
    }
    cout << endl;
}