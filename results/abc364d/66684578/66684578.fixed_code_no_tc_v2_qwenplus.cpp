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
    
    // Sort the A points for binary search and distance computation
    sort(a.begin(), a.end());
    
    rep(q_idx, Q) {
        int b, k;
        cin >> b >> k;
        k--; // Convert to 0-indexed
        
        // We'll find the smallest radius r such that there are at least k+1 points within distance r
        // But instead of binary searching on distance, we can use two pointers or binary search on positions
        
        // Binary search on the answer (distance)
        ll left = -1, right = 200000000; // max possible distance is 2e8
        while (right - left > 1) {
            ll mid = (left + right) / 2;
            
            // Count how many points in A are within distance `mid` from point b
            ll low = b - mid;
            ll high = b + mid;
            
            auto it1 = lower_bound(a.begin(), a.end(), low);
            auto it2 = upper_bound(a.begin(), a.end(), high);
            int count = it2 - it1;
            
            if (count >= k+1) {
                right = mid;
            } else {
                left = mid;
            }
        }
        
        cout << right << endl;
    }
}