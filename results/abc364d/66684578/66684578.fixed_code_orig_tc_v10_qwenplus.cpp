#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define vi vector<int>
#define vl vector<ll>

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;
    
    vi a(n);
    rep(i, n) {
        cin >> a[i];
    }
    
    sort(a.begin(), a.end());
    
    rep(_, q) {
        int b, k;
        cin >> b >> k;
        
        // Binary search on the distance
        ll left = 0, right = 2e8;
        while (left < right) {
            ll mid = (left + right) / 2;
            
            // Count how many points are within distance 'mid' from b
            ll count = 0;
            
            // Find the range [b-mid, b+mid]
            auto it1 = lower_bound(a.begin(), a.end(), b - mid);
            auto it2 = upper_bound(a.begin(), a.end(), b + mid);
            count = it2 - it1;
            
            if (count >= k) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        
        cout << left << '\n';
    }
}