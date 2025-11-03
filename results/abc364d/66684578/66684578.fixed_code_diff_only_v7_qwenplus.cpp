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
    
    // Sort the A points for binary search
    sort(a.begin(), a.end());
    
    rep(qi, Q) {
        int b, k;
        cin >> b >> k;
        k--; // convert to 0-indexed
        
        // We'll find the smallest distance d such that there are at least k+1 points within distance d from b
        // But instead, we can directly find the k-th closest point by considering candidates
        
        // Binary search on the answer (distance)
        ll left = -1, right = 200000000; // max possible distance is 2e8
        
        while (right - left > 1) {
            ll mid = (left + right) / 2;
            
            // Count how many points in A are within distance 'mid' from b
            ll low_bound = b - mid;
            ll high_bound = b + mid;
            
            auto it1 = lower_bound(a.begin(), a.end(), low_bound);
            auto it2 = upper_bound(a.begin(), a.end(), high_bound);
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