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
        
        priority_queue<int> max_heap;
        int sum = 0;
        vector<int> prefix_sum(N);
        
        for (int i = 0; i < N; ++i) {
            if (max_heap.size() < K - 1) {
                max_heap.push(pairs[i].second);
                sum += pairs[i].second;
            } else if (!max_heap.empty() && pairs[i].second < max_heap.top()) {
                sum -= max_heap.top();
                max_heap.pop();
                max_heap.push(pairs[i].second);
                sum += pairs[i].second;
            }
            prefix_sum[i] = sum;
        }
        
        int min_val = inf;
        for (int i = K - 1; i < N; ++i) {
            int current_sum = prefix_sum[i - 1] + pairs[i].second;
            min_val = min(min_val, pairs[i].first * current_sum);
        }
        
        cout << min_val << '\n';
    }
    return 0;
}