#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
constexpr ll LINF = 1001001001001001001ll;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        vector<P> p(n);
        for(int i = 0; i < n; ++i) cin >> p[i].first;
        for(int i = 0; i < n; ++i) cin >> p[i].second;
        sort(p.begin(), p.end());
        
        priority_queue<ll, vector<ll>, greater<ll>> pq;
        ll sumB = 0;
        for(int i = 0; i < k; ++i){
            pq.push(p[i].second);
            sumB += p[i].second;
        }
        ll ans = p[k-1].first * sumB;
        
        for(int i = k; i < n; ++i){
            if(pq.top() < p[i].second){
                sumB += p[i].second - pq.top();
                pq.pop();
                pq.push(p[i].second);
            }
            ans = min(ans, p[i].first * sumB);
        }
        cout << ans << '\n';
    }
}