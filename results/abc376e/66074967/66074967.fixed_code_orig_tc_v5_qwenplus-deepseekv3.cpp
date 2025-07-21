#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
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
        
        priority_queue<int, vector<int>, greater<int>> min_heap;
        int sum = 0;
        vector<int> prefix_max_sum(N + 1, 0);
        
        for (int i = 0; i < N; ++i) {
            min_heap.push(pairs[i].second);
            sum += pairs[i].second;
            if (min_heap.size() > K) {
                sum -= min_heap.top();
                min_heap.pop();
            }
            prefix_max_sum[i + 1] = sum;
        }
        
        int res = INF;
        for (int i = K - 1; i < N; ++i) {
            int current_max_A = pairs[i].first;
            int current_sum_B = prefix_max_sum[i + 1] - (i >= K ? prefix_max_sum[i - K + 1] : 0);
            res = min(res, current_max_A * current_sum_B);
        }
        
        cout << res << '\n';
    }
    return 0;
}