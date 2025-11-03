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
    rep(i,N) cin >> a[i];
    
    sort(a.begin(), a.end());
    
    rep(qi, Q) {
        ll b;
        int k;
        cin >> b >> k;
        k--; // 0-indexed k-th smallest distance
        
        // Binary search on the answer (distance)
        ll low = 0, high = 2e9;
        ll ans = high;
        
        while (low <= high) {
            ll mid = (low + high) / 2;
            
            // Count how many points in A are within distance `mid` from B
            ll left_bound = b - mid;
            ll right_bound = b + mid;
            
            auto it1 = lower_bound(a.begin(), a.end(), left_bound);
            auto it2 = upper_bound(a.begin(), a.end(), right_bound);
            ll count = it2 - it1;
            
            if (count >= k+1) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        
        cout << ans << '\n';
    }
}