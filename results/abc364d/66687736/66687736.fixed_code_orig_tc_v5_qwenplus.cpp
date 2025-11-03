#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define vi vector<int>
#define vl vector<ll>

int main(){
    int n, q;
    cin >> n >> q;
    vi a(n);
    rep(i,n) cin >> a[i];
    
    sort(a.begin(), a.end());
    
    while(q--){
        int b, k;
        cin >> b >> k;
        
        // Binary search on the distance
        ll left = 0, right = 200000000;
        while(left < right){
            ll mid = (left + right) / 2;
            
            // Count how many points in A are within distance 'mid' from B
            ll count = upper_bound(a.begin(), a.end(), b + mid) - lower_bound(a.begin(), a.end(), b - mid);
            
            if(count >= k){
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        
        cout << left << endl;
    }
}