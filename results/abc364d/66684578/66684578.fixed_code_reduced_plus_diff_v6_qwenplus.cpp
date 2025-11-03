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
    rep(i,N) cin >> a[i];
    
    // Sort the A points for binary search
    sort(a.begin(), a.end());
    
    rep(qi,Q){
        ll b;
        int k;
        cin >> b >> k;
        k--; // convert to 0-indexed
        
        // Binary search on the distance
        ll left = -1;
        ll right = 2e9 + 10;
        
        while(right - left > 1){
            ll mid = (left + right) / 2;
            
            // Count how many points in A are within distance 'mid' from b
            ll count = 0;
            ll left_bound = b - mid;
            ll right_bound = b + mid;
            
            // Find the first index >= left_bound
            auto it1 = lower_bound(a.begin(), a.end(), left_bound);
            // Find the first index > right_bound
            auto it2 = upper_bound(a.begin(), a.end(), right_bound);
            
            count = it2 - it1;
            
            if(count <= k){
                left = mid;
            } else {
                right = mid;
            }
        }
        
        cout << right << '\n';
    }
}