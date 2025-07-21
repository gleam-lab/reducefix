#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T;
    cin >> T;
    while (T--) {
        int N, K;
        cin >> N >> K;
        vector<pair<ll, ll>> pairs(N);
        for (int i = 0; i < N; i++) {
            cin >> pairs[i].first;
        }
        for (int i = 0; i < N; i++) {
            cin >> pairs[i].second;
        }
        
        sort(pairs.begin(), pairs.end());
        
        priority_queue<ll, vector<ll>, greater<ll>> pq;
        ll sum = 0;
        
        for (int i = N - 1; i >= N - K; i--) {
            pq.push(pairs[i].second);
            sum += pairs[i].second;
        }
        
        ll res = pairs[N - K].first * sum;
        
        for (int i = N - K - 1; i >= 0; i--) {
            if (pairs[i].second > pq.top()) {
                sum -= pq.top();
                pq.pop();
                sum += pairs[i].second;
                pq.push(pairs[i].second);
                res = min(res, pairs[i].first * sum);
            }
        }
        
        cout << res << '\n';
    }
    
    return 0;
}