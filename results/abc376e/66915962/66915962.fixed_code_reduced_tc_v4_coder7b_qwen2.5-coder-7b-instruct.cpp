#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using VI = vector<int>;
using P = pair<int, int>;
constexpr int INF = 1001001001;
constexpr ll LINF = 1001001001001001001ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep2(i, k, n) for (ll i = k; i < (ll)(n); i++)
#define OUT(x) cout << #x << ":" << x << endl

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        vector<ll> a(n), b(n);
        vector<P> p(n);
        rep(i, n) cin >> p[i].first;
        rep(i, n) cin >> p[i].second;
        sort(p.begin(), p.end());
        
        multiset<ll> ms;
        ll sumB = 0;
        rep(i, k){
            ms.insert(p[i].second);
            sumB += p[i].second;
        }
        ll ans = a[k-1]*sumB;
        
        rep2(i, k, n){
            auto it = ms.rbegin();
            ll smax = *it;
            ms.erase(it);
            ms.insert(p[i].second);
            sumB += p[i].second - smax;
            ans = min(ans, a[i]*sumB);
        } 
        cout << ans << '\n';
    }
}