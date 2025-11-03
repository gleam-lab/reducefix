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
    
    // Sort the A points for binary search
    sort(a.begin(), a.end());
    
    rep(qi, Q) {
        ll b;
        int k;
        cin >> b >> k;
        k--; // Convert to 0-indexed
        
        // We'll find the k-th smallest distance from B to any A point
        // Instead of computing all distances, we can binary search on the answer (distance)
        
        ll left = -1;
        ll right = 200000000; // Max possible distance is 2e8
        
        while (right - left > 1) {
            ll mid = (left + right) / 2;
            
            // Count how many points in A are within distance 'mid' from B
            ll low_bound = b - mid;
            ll high_bound = b + mid;
            
            auto it1 = lower_bound(a.begin(), a.end(), low_bound);
            auto it2 = upper_bound(a.begin(), a.end(), high_bound);
            int count = it2 - it1;
            
            if (count <= k) {
                left = mid;
            } else {
                right = mid;
            }
        }
        
        cout << right << endl;
    }
}