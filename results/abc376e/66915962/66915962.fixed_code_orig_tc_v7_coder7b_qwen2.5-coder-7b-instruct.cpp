#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using VI = vector<int>;
using P = pair<int, int>;
constexpr int INF = 1001001001;
constexpr ll LINF = 1001001001001001001ll;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        vector<ll> a(n), b(n);
        
        for(int i = 0; i < n; ++i){
            cin >> a[i];
        }
        
        for(int i = 0; i < n; ++i){
            cin >> b[i];
        }
        
        // Sort A and B in descending order
        sort(a.rbegin(), a.rend());
        sort(b.rbegin(), b.rend());
        
        ll ans = 0;
        for(int i = 0; i < k; ++i){
            ans += a[i] * b[i];
        }
        
        cout << ans << '\n';
    }
    
    return 0;
}