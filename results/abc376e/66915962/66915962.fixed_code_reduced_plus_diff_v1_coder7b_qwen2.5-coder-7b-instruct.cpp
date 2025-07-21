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
        vector<pair<ll, ll>> ab(n);
        
        rep(i, n){
            cin >> a[i];
            cin >> b[i];
            ab[i] = {a[i], b[i]};
        }
        
        sort(ab.begin(), ab.end(), [](const pair<ll, ll>& a, const pair<ll, ll>& b){return a.second < b.second;});
        
        priority_queue<ll, vector<ll>, greater<ll>> pq;
        ll sumB = 0;
        
        rep(i, k){
            pq.push(-ab[i].second);
            sumB += ab[i].second;
        }
        
        ll ans = LLONG_MAX;
        ans = min(ans, -pq.top() * sumB);
        
        rep2(i, k, n){
            ll mx = -pq.top();
            pq.pop();
            pq.push(-ab[i].second);
            sumB -= mx;
            sumB += ab[i].second;
            ans = min(ans, -pq.top() * sumB);
        }
        
        cout << ans << '\n';
    }
    return 0;
}