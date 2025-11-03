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
            ll cnt = 0;
            auto it1 = lower_bound(a.begin(), a.end(), b - mid);
            auto it2 = upper_bound(a.begin(), a.end(), b + mid);
            cnt = it2 - it1;
            
            if(cnt >= k){
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        
        cout << left << endl;
    }
}