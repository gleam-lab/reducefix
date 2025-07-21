#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
constexpr ll LINF = 1e18;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<P> p(n);
        for (int i = 0; i < n; ++i) cin >> p[i].first;
        for (int i = 0; i < n; ++i) cin >> p[i].second;
        
        sort(p.begin(), p.end());
        
        priority_queue<ll> pq; // max-heap to keep track of the smallest (k-1) B_i's
        ll sum_b = 0;
        ll min_product = LINF;
        
        for (int i = 0; i < n; ++i) {
            ll a_i = p[i].first;
            ll b_i = p[i].second;
            
            if (pq.size() < k - 1) {
                pq.push(b_i);
                sum_b += b_i;
            } else {
                min_product = min(min_product, a_i * (sum_b + b_i));
                if (!pq.empty() && b_i < pq.top()) {
                    sum_b -= pq.top();
                    pq.pop();
                    pq.push(b_i);
                    sum_b += b_i;
                }
            }
        }
        
        cout << min_product << '\n';
    }
    return 0;
}