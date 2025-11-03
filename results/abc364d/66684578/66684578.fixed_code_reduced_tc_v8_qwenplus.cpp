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
    rep(i, N) cin >> a[i];
    
    sort(a.begin(), a.end());
    
    rep(qi, Q) {
        ll b;
        int k;
        cin >> b >> k;
        k--; // 0-indexed k-th smallest distance
        
        // We'll binary search on the distance d
        ll left = -1;
        ll right = 2e8 + 10; // maximum possible distance is ~2e8
        
        while (right - left > 1) {
            ll d = (left + right) / 2;
            
            // Count how many points in A are within distance d from B
            ll low = b - d;
            ll high = b + d;
            
            auto it1 = lower_bound(a.begin(), a.end(), low);
            auto it2 = upper_bound(a.begin(), a.end(), high);
            int cnt = it2 - it1;
            
            if (cnt <= k) {
                left = d;
            } else {
                right = d;
            }
        }
        
        cout << right << '\n';
    }
}