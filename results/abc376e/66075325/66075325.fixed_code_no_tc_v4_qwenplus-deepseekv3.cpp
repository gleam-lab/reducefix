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
        vector<pair<int, int>> AB(N);
        for (int i = 0; i < N; ++i) {
            cin >> AB[i].first;
        }
        for (int i = 0; i < N; ++i) {
            cin >> AB[i].second;
        }
        
        sort(AB.begin(), AB.end());
        
        priority_queue<int, vector<int>, greater<int>> min_heap;
        int sum_B = 0;
        int ans = inf;
        
        for (int i = 0; i < N; ++i) {
            int current_A = AB[i].first;
            int current_B = AB[i].second;
            
            if (min_heap.size() < K - 1) {
                min_heap.push(current_B);
                sum_B += current_B;
            } else {
                if (!min_heap.empty() && current_B > min_heap.top()) {
                    sum_B -= min_heap.top();
                    min_heap.pop();
                    min_heap.push(current_B);
                    sum_B += current_B;
                }
            }
            
            if (min_heap.size() == K - 1) {
                ans = min(ans, current_A * (sum_B + current_B));
            }
        }
        
        cout << ans << '\n';
    }
    
    return 0;
}