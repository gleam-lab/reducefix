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
        long long ans = LLONG_MAX;
        
        for (int i = 0; i < N; ++i) {
            sum += pairs[i].second;
            maxHeap.push(pairs[i].second);
            
            if (maxHeap.size() > K) {
                sum -= maxHeap.top();
                maxHeap.pop();
            }
            
            if (maxHeap.size() == K) {
                ans = min(ans, pairs[i].first * sum);
            }
        }
        cout << ans << "\n";
    }
    return 0;
}