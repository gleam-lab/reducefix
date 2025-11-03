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
    rep(i, N) cin >> a[i];
    
    // Sort the A points for efficient binary search
    sort(a.begin(), a.end());
    
    rep(q_idx, Q) {
        int b, k;
        cin >> b >> k;
        k--; // Convert to 0-indexed
        
        // We'll use binary search on the answer (distance)
        ll left = -1;
        ll right = 200000000; // Maximum possible distance is 2e8
        
        while (right - left > 1) {
            ll mid = (left + right) / 2;
            
            // Count how many points in A are within distance 'mid' from point b
            ll count = 0;
            
            // Find the range [b-mid, b+mid] in sorted array a
            auto it1 = lower_bound(a.begin(), a.end(), b - mid);
            auto it2 = upper_bound(a.begin(), a.end(), b + mid);
            count = distance(it1, it2);
            
            if (count <= k) {
                left = mid;
            } else {
                right = mid;
            }
        }
        
        // At this point, 'right' is the smallest distance such that 
        // more than k points are within or at that distance
        // But we need the k-th closest (0-indexed), so we need to check differently
        
        // Let's change our approach: find the k-th smallest distance directly
        // Our previous logic was flawed. Let's fix by searching for the minimum distance d
        // such that there are at least k+1 points with distance <= d
        
        ll low = -1;
        ll high = 200000000;
        
        while (high - low > 1) {
            ll mid = (low + high) / 2;
            
            // Count points within distance <= mid from b
            auto it1 = lower_bound(a.begin(), a.end(), b - mid);
            auto it2 = upper_bound(a.begin(), a.end(), b + mid);
            ll count = distance(it1, it2);
            
            if (count < k + 1) {
                low = mid;
            } else {
                high = mid;
            }
        }
        
        cout << high << '\n';
    }
}