#include <bits/stdc++.h>
using namespace std;
const int maxN = 2e5 + 5;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
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
        
        priority_queue<int> maxHeap;
        long long sum = 0;
        
        for (int i = 0; i < K - 1; ++i) {
            maxHeap.push(pairs[i].second);
            sum += pairs[i].second;
        }
        
        long long ans = 1LL * pairs[K - 1].first * (sum + pairs[K - 1].second);
        
        for (int i = K; i < N; ++i) {
            if (!maxHeap.empty() && pairs[i - 1].second < maxHeap.top()) {
                sum -= maxHeap.top();
                maxHeap.pop();
                sum += pairs[i - 1].second;
                maxHeap.push(pairs[i - 1].second);
            }
            long long current = 1LL * pairs[i].first * (sum + pairs[i].second);
            if (current < ans) {
                ans = current;
            }
        }
        
        cout << ans << "\n";
    }
    return 0;
}