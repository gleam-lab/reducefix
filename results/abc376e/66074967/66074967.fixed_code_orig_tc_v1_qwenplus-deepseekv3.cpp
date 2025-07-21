#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
#define int long long

const int INF = 1e18;

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
        vector<int> suffix_sum(N + 1, 0);
        
        for (int i = N - 1; i >= 0; --i) {
            pq.push(-pairs[i].second);
            sum += pairs[i].second;
            if (pq.size() > K) {
                sum += pq.top();
                pq.pop();
            }
            suffix_sum[i] = sum;
        }
        
        int res = INF;
        for (int i = 0; i <= N - K; ++i) {
            res = min(res, pairs[i + K - 1].first * suffix_sum[i]);
        }
        
        cout << res << '\n';
    }
    return 0;
}