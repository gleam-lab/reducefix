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
        vector<pair<int, int>> elements(N);
        for (int i = 0; i < N; ++i) {
            cin >> elements[i].first;
        }
        for (int i = 0; i < N; ++i) {
            cin >> elements[i].second;
        }
        
        sort(elements.begin(), elements.end());
        
        priority_queue<int, vector<int>, greater<int>> min_heap;
        int sum_B = 0;
        int answer = inf;
        
        for (int i = N - 1; i >= 0; --i) {
            int current_A = elements[i].first;
            int current_B = elements[i].second;
            
            sum_B += current_B;
            min_heap.push(current_B);
            
            if (min_heap.size() > K) {
                sum_B -= min_heap.top();
                min_heap.pop();
            }
            
            if (min_heap.size() == K) {
                answer = min(answer, current_A * sum_B);
            }
        }
        
        cout << answer << '\n';
    }
    return 0;
}