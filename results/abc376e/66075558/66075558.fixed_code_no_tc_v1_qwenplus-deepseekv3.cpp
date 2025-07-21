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
        int ans = inf;
        
        for (int i = 0; i < N; ++i) {
            int current_A = pairs[i].first;
            int current_B = pairs[i].second;
            
            if (max_heap.size() == K - 1) {
                ans = min(ans, current_A * (sum + current_B));
            }
            
            if (max_heap.size() < K - 1) {
                max_heap.push(current_B);
                sum += current_B;
            } else if (!max_heap.empty() && max_heap.top() > current_B) {
                sum -= max_heap.top();
                max_heap.pop();
                max_heap.push(current_B);
                sum += current_B;
            }
        }
        
        cout << ans << '\n';
    }
    return 0;
}