#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pint = pair<int,int>;
using pll = pair<ll, ll>;

#define rep(i, a, b) for(ll i = a; i < b; i++)
#define rrep(i, a, b) for(ll i = a; i >= b; i--)
#define all(a) a.begin(), a.end()

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T;
    cin >> T;
    while (T--) {
        int N, K;
        cin >> N >> K;
        vector<pll> AB(N);
        rep(i, 0, N) cin >> AB[i].first;
        rep(i, 0, N) cin >> AB[i].second;
        
        // Sort by A_i in ascending order
        sort(all(AB), [](const pll& x, const pll& y) {
            return x.first < y.first;
        });
        
        // Maintain a min-heap of size K-1 to track smallest B_i's
        priority_queue<ll, vector<ll>, greater<ll>> pq;
        ll sum_B = 0;
        
        // Initialize for the first K elements
        rep(i, 0, K-1) {
            pq.push(AB[i].second);
            sum_B += AB[i].second;
        }
        
        ll min_product = LLONG_MAX;
        rep(i, K-1, N) {
            // Current A_i is the max (since array is sorted)
            ll current_A = AB[i].first;
            // Add current B_i to sum
            ll current_sum = sum_B + AB[i].second;
            // Update min product
            min_product = min(min_product, current_A * current_sum);
            
            // Maintain heap size K-1 for next iteration
            if (!pq.empty() && AB[i].second > pq.top()) {
                sum_B -= pq.top();
                pq.pop();
                pq.push(AB[i].second);
                sum_B += AB[i].second;
            }
        }
        
        cout << min_product << '\n';
    }
    
    return 0;
}