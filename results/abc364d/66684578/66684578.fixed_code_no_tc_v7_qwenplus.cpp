#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define vi vector<int>
#define vll vector<ll>

int main(){
    int N, Q;
    cin >> N >> Q;
    vi a(N);
    rep(i,N) cin >> a[i];
    
    // Sort the A points for efficient binary search later
    sort(a.begin(), a.end());
    
    rep(qi, Q) {
        int b, k;
        cin >> b >> k;
        k--; // Convert to 0-indexed
        
        // We'll use binary search on the answer (distance)
        ll left = -1, right = 200000000; // Max possible distance is 2e8
        
        while (right - left > 1) {
            ll mid = (left + right) / 2;
            
            // Count how many points in A are within distance 'mid' from point b
            ll count = 0;
            
            // Find the range [b-mid, b+mid] in sorted array a
            auto it1 = lower_bound(a.begin(), a.end(), b - mid);
            auto it2 = upper_bound(a.begin(), a.end(), b + mid);
            count = it2 - it1;
            
            if (count <= k) {
                left = mid;
            } else {
                right = mid;
            }
        }
        
        cout << right << endl;
    }
}