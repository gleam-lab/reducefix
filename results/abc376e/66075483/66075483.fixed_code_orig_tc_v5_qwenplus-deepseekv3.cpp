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
        vector<pair<int, int>> elements(N);
        for (int i = 0; i < N; i++) {
            cin >> elements[i].first;
        }
        for (int i = 0; i < N; i++) {
            cin >> elements[i].second;
        }
        
        sort(elements.begin(), elements.end());
        
        priority_queue<int, vector<int>, greater<int>> min_heap;
        int sum = 0;
        int answer = INF;
        
        for (int i = N - 1; i >= 0; i--) {
            min_heap.push(elements[i].second);
            sum += elements[i].second;
            
            if (min_heap.size() > K) {
                sum -= min_heap.top();
                min_heap.pop();
            }
            
            if (min_heap.size() == K) {
                answer = min(answer, sum * elements[i].first);
            }
        }
        
        cout << answer << '\n';
    }
    return 0;
}