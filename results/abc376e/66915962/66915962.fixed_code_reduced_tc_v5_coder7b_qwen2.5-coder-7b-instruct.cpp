#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using VI = vector<int>;
using P = pair<int, int>;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    
    while(t--){
        int n, k;
        cin >> n >> k;
        
        vector<ll> a(n), b(n);
        for(int i = 0; i < n; ++i) cin >> a[i];
        for(int i = 0; i < n; ++i) cin >> b[i];
        
        // Sort both arrays based on A values in descending order
        vector<pair<ll, ll>> ab(n);
        for(int i = 0; i < n; ++i) ab[i] = {a[i], b[i]};
        sort(ab.rbegin(), ab.rend());
        
        // Create a multiset to store B values
        multiset<ll> bs;
        ll sumB = 0;
        for(int i = 0; i < k; ++i){
            bs.insert(ab[i].second);
            sumB += ab[i].second;
        }
        
        ll ans = LLONG_MAX;
        ans = min(ans, ab[k-1].first * sumB);
        
        for(int i = k; i < n; ++i){
            auto it = prev(bs.end());
            sumB -= *it;
            bs.erase(it);
            bs.insert(ab[i].second);
            sumB += ab[i].second;
            ans = min(ans, ab[i].first * sumB);
        }
        
        cout << ans << '\n';
    }
    
    return 0;
}