#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

long long minCost(int n, int k, vector<int>& a, vector<int>& b) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    for(int i = 0; i < n; ++i) pq.push({a[i], b[i]});
    
    long long sum = 0, res = 0;
    for(int i = 0; i < k; ++i) {
        auto [x, y] = pq.top(); pq.pop();
        sum += y;
        res = max(res, (long long)x * sum);
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n), b(n);
        for(int i = 0; i < n; ++i) cin >> a[i];
        for(int i = 0; i < n; ++i) cin >> b[i];
        
        cout << minCost(n, k, a, b) << '\n';
    }

    return 0;
}