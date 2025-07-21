#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
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
    
    // Calculate the maximum number of votes needed to secure victory
    vector<ll> max_votes_needed(n, -1);
    for(int i = 0; i < n; ++i) {
        ll max_votes = a[i] + 1;
        for(int j = 0; j < n; ++j) {
            if(j != i && a[j] >= max_votes) {
                max_votes_needed[i] = -1;
                break;
            }
        }
        if(max_votes_needed[i] == -1) continue;
        
        ll required_votes = max_votes - a[i];
        if(required_votes <= k) {
            max_votes_needed[i] = required_votes;
        } else {
            max_votes_needed[i] = -1;
        }
    }
    
    // Output the results
    for(int i = 0; i < n; ++i) {
        cout << max_votes_needed[i] << " ";
    }
    cout << endl;
    
    return 0;
}