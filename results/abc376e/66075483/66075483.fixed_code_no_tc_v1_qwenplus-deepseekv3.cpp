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
        
        priority_queue<int, vector<int>, greater<int>> min_heap;
        int sum_B = 0;
        int answer = inf;
        
        for (int i = N - 1; i >= 0; --i) {
            int current_A = pairs[i].first;
            int current_B = pairs[i].second;
            
            if (min_heap.size() < K - 1) {
                min_heap.push(current_B);
                sum_B += current_B;
            } else {
                if (K > 1 && current_B > min_heap.top()) {
                    sum_B -= min_heap.top();
                    min_heap.pop();
                    min_heap.push(current_B);
                    sum_B += current_B;
                }
            }
            
            if (min_heap.size() == K - 1) {
                int total_sum = sum_B + current_B;
                answer = min(answer, current_A * total_sum);
            }
        }
        
        cout << answer << '\n';
    }
    
    return 0;
}