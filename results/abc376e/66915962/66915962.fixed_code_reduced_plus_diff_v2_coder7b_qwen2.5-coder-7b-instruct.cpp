#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

bool compare(const pii &a, const pii &b) {
    return a.second > b.second || (a.second == b.second && a.first < b.first);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        
        vector<pii> ab(n);
        for (int i = 0; i < n; ++i) {
            cin >> ab[i].first >> ab[i].second;
        }
        
        sort(ab.begin(), ab.end(), compare);
        
        priority_queue<int, vector<int>, greater<int>> pq;
        ll sum = 0, result = LLONG_MAX;
        
        for (const auto &p : ab) {
            if (pq.size() == k) {
                sum -= pq.top();
                pq.pop();
            }
            pq.push(p.second);
            sum += p.second;
            if (pq.size() == k) {
                result = min(result, static_cast<ll>(p.first) * sum);
            }
        }
        
        cout << result << "\n";
    }
    
    return 0;
}