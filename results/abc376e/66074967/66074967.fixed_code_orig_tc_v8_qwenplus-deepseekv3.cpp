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
        
        priority_queue<int> pq;
        int sum = 0;
        int ans = INF;
        
        for (int i = 0; i < N; ++i) {
            int current_A = pairs[i].first;
            int current_B = pairs[i].second;
            
            if (pq.size() < K - 1) {
                pq.push(current_B);
                sum += current_B;
            } else {
                if (pq.size() == K - 1) {
                    int current_sum = sum + current_B;
                    ans = min(ans, current_A * current_sum);
                }
                if (!pq.empty() && current_B < pq.top()) {
                    sum -= pq.top();
                    pq.pop();
                    pq.push(current_B);
                    sum += current_B;
                    if (pq.size() == K - 1) {
                        int current_sum = sum + current_B;
                        ans = min(ans, current_A * current_sum);
                    }
                }
            }
        }
        
        cout << ans << '\n';
    }
    
    return 0;
}