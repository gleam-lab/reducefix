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
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        vector<ll> a(n), b(n);
        
        rep(i, n) cin >> a[i];
        rep(i, n) cin >> b[i];
        
        vector<ll> sum(n-k+1);
        partial_sum(b.begin(), b.end(), sum.begin()+1);
        sum.push_back(accumulate(b.begin(), b.end(), 0LL));
        
        priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
        
        for(int i = 0; i <= n-k; ++i){
            if(i == 0){
                pq.push({sum[i+k]-sum[i], i});
            } else {
                pq.push({sum[i+k]-sum[i] + pq.top().first, pq.top().second});
                pq.pop();
            }
        }
        
        ll ans = LLONG_MAX;
        while(!pq.empty()){
            auto [s, idx] = pq.top(); pq.pop();
            ans = min(ans, a[idx+k-1] * s);
        }
        
        cout << ans << '\n';
    }
    return 0;
}