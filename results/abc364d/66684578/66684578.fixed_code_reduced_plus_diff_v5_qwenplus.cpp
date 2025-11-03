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
    
    sort(a.begin(), a.end());
    
    rep(qi, Q){
        int b, k;
        cin >> b >> k;
        
        // Binary search on the distance
        ll left = -1, right = 200000000;
        while(right - left > 1){
            ll mid = (left + right) / 2;
            
            // Count how many points in A are within distance 'mid' from b
            ll count = 0;
            auto it1 = lower_bound(a.begin(), a.end(), b - mid);
            auto it2 = upper_bound(a.begin(), a.end(), b + mid);
            count = it2 - it1;
            
            if(count < k){
                left = mid;
            } else {
                right = mid;
            }
        }
        
        cout << right << endl;
    }
    
    return 0;
}