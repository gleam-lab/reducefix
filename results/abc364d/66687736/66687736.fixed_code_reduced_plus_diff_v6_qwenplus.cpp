#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define vi vector<int>
#define vll vector<ll>

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, q;
    cin >> n >> q;
    
    vi a(n);
    rep(i, n) {
        cin >> a[i];
    }
    
    sort(a.begin(), a.end());
    
    rep(i, q) {
        ll b, k;
        cin >> b >> k;
        
        // Binary search on the distance
        ll left = -1, right = 2e9 + 10;
        while (right - left > 1) {
            ll mid = (left + right) / 2;
            
            // Count points in [b-mid, b+mid]
            ll left_bound = b - mid;
            ll right_bound = b + mid;
            
            auto it1 = lower_bound(a.begin(), a.end(), left_bound);
            auto it2 = upper_bound(a.begin(), a.end(), right_bound);
            ll count = it2 - it1;
            
            if (count >= k) {
                right = mid;
            } else {
                left = mid;
            }
        }
        
        cout << right << '\n';
    }
}