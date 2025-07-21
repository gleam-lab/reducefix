#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using VI = vector<int>;
using P = pair<int, int>;
constexpr int INF = 1001001001;
constexpr ll LINF = 1001001001001001001ll;

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n, k;
        cin >> n >> k;
        
        vector<ll> a(n), b(n);
        priority_queue<ll> pq_a;
        multiset<ll> pq_b;
        ll sum_b = 0;
        
        rep(i, n) {
            cin >> a[i];
            cin >> b[i];
            pq_a.push(a[i]);
            pq_b.insert(b[i]);
            sum_b += b[i];
        }
        
        ll ans = LINF;
        
        rep(i, k) {
            sum_b -= *pq_b.rbegin();
            pq_b.erase(prev(pq_b.end()));
            ans = min(ans, pq_a.top() * sum_b);
        }
        
        rep2(i, k, n) {
            sum_b += *pq_b.rbegin();
            pq_b.erase(prev(pq_b.end()));
            pq_b.insert(b[i]);
            pq_a.pop();
            pq_a.push(a[i]);
            ans = min(ans, pq_a.top() * sum_b);
        }
        
        cout << ans << '\n';
    }
    
    return 0;
}