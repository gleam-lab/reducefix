#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
constexpr ll LINF = 1LL << 60;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        vector<P> p(n);
        for(int i = 0; i < n; i++) cin >> p[i].first;
        for(int i = 0; i < n; i++) cin >> p[i].second;
        
        sort(p.begin(), p.end());
        
        priority_queue<ll, vector<ll>, greater<ll>> pq;
        ll sum = 0;
        vector<ll> max_a(n), sum_b(n);
        
        for(int i = 0; i < n; i++){
            pq.push(p[i].second);
            sum += p[i].second;
            if(pq.size() > k){
                sum -= pq.top();
                pq.pop();
            }
            if(pq.size() == k){
                max_a[i] = p[i].first;
                sum_b[i] = sum;
            }
        }
        
        ll ans = LINF;
        for(int i = k-1; i < n; i++){
            if(sum_b[i] > 0){
                ans = min(ans, max_a[i] * sum_b[i]);
            }
        }
        
        cout << ans << '\n';
    }
}