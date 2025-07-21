#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
#define int long long

const int inf = 1e18;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T;
    cin >> T;
    while (T--) {
        int N, K;
        cin >> N >> K;
        vector<pair<int, int>> pairs(N);
        for (int i = 0; i < N; ++i) {
            cin >> pairs[i].first;
        }
        for (int i = 0; i < N; ++i) {
            cin >> pairs[i].second;
        }
        
        sort(pairs.begin(), pairs.end());
        
        priority_queue<int> pq;
        int sum = 0;
        vector<int> prefix(N);
        
        for (int i = 0; i < N; ++i) {
            if (pq.size() < K - 1) {
                pq.push(pairs[i].second);
                sum += pairs[i].second;
            } else if (!pq.empty() && pairs[i].second < pq.top()) {
                sum -= pq.top();
                pq.pop();
                pq.push(pairs[i].second);
                sum += pairs[i].second;
            }
            prefix[i] = sum;
        }
        
        int ans = inf;
        for (int i = K - 1; i < N; ++i) {
            int current = pairs[i].first * (prefix[i - 1] + pairs[i].second);
            if (current < ans) {
                ans = current;
            }
        }
        
        cout << ans << '\n';
    }
    return 0;
}