#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using VI = vector<int>;
using P = pair<ll, ll>;
constexpr ll INF = 1001001001001001001ll;

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
        vector<ll> a(n), b(n);
        for(int i = 0; i < n; ++i){
            a[i] = p[i].first;
            b[i] = p[i].second;
        }
        ll ans = INF;
        priority_queue<ll> pq;
        ll sum = 0;
        for(int i = 0; i < n; ++i){
            if(pq.size() < k - 1){
                pq.push(b[i]);
                sum += b[i];
            } else {
                ll current_max_a = a[i];
                ll current_sum = sum + b[i];
                ans = min(ans, current_max_a * current_sum);
                if(!pq.empty() && pq.top() > b[i]){
                    sum -= pq.top();
                    pq.pop();
                    pq.push(b[i]);
                    sum += b[i];
                }
            }
        }
        cout << ans << '\n';
    }
    return 0;
}