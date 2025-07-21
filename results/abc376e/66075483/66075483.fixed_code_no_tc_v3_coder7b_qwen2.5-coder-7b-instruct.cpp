#include<iostream>
#include<algorithm>
using namespace std;

#define ll long long

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        
        vector<pair<ll, ll>> a(n), b(n);
        for(int i = 0; i < n; ++i){
            cin >> a[i].first;
            a[i].second = i;
        }
        for(int i = 0; i < n; ++i){
            cin >> b[i].first;
            b[i].second = i;
        }
        
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        
        ll ans = LLONG_MAX;
        for(int i = 0; i <= n - k; ++i){
            ans = min(ans, (a[i+k-1].first * (ll)(b[i].first + b[i+1].first + ... + b[i+k-2].first)));
        }
        
        cout << ans << '\n';
    }
    
    return 0;
}