#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define vi vector<int>
#define vll vector<ll>

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int N, Q;
    cin >> N >> Q;
    
    vi a(N);
    rep(i, N) {
        cin >> a[i];
    }
    
    // Sort the A points for binary search later
    sort(a.begin(), a.end());
    
    rep(q_idx, Q) {
        int b, k;
        cin >> b >> k;
        
        // We'll use binary search on the answer (distance)
        ll left = -1, right = 200000000; // max possible distance is 2e8
        
        while (right - left > 1) {
            ll mid = (left + right) / 2;
            
            // Count how many points in A are within distance 'mid' from point b
            ll count = 0;
            ll low_bound = (ll)b - mid;
            ll high_bound = (ll)b + mid;
            
            // Use lower_bound and upper_bound to count points in [low_bound, high_bound]
            auto it1 = lower_bound(a.begin(), a.end(), low_bound);
            auto it2 = upper_bound(a.begin(), a.end(), high_bound);
            count = it2 - it1;
            
            if (count < k) {
                left = mid;
            } else {
                right = mid;
            }
        }
        
        cout << right << endl;
    }
}