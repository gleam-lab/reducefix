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
    
    vector<ll> a(N);
    rep(i, N) {
        cin >> a[i];
    }
    
    // Sort the A points for binary search later
    sort(a.begin(), a.end());
    
    rep(q_idx, Q) {
        ll b;
        int k;
        cin >> b >> k;
        k--; // Convert to 0-indexed
        
        // We'll collect distances from B to all A points
        // But we don't want to sort all N points for each query (too slow)
        
        // Instead, we can use binary search on the answer (distance)
        // For a given distance d, count how many points in A are within distance d from b
        // Then find the smallest d such that at least k+1 points are within distance d
        
        ll left = -1;
        ll right = 200000000; // Max possible distance is 2e8
        
        while (right - left > 1) {
            ll mid = (left + right) / 2;
            
            // Count points in [b-mid, b+mid]
            ll low = b - mid;
            ll high = b + mid;
            
            auto it1 = lower_bound(a.begin(), a.end(), low);
            auto it2 = upper_bound(a.begin(), a.end(), high);
            int cnt = it2 - it1;
            
            if (cnt <= k) {
                left = mid;
            } else {
                right = mid;
            }
        }
        
        cout << right << endl;
    }
}