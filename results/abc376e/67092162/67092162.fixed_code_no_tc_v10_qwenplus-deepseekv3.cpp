#include <bits/stdc++.h>
using namespace std;
const int maxN = 2e5 + 5;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
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
        
        priority_queue<int, vector<int>, greater<int>> minHeap;
        long long sum = 0;
        long long ans = LLONG_MAX;
        
        for (int i = N - 1; i >= 0; --i) {
            sum += pairs[i].second;
            minHeap.push(pairs[i].second);
            if (minHeap.size() > K) {
                sum -= minHeap.top();
                minHeap.pop();
            }
            if (minHeap.size() == K) {
                ans = min(ans, pairs[i].first * sum);
            }
        }
        
        cout << ans << '\n';
    }
    return 0;
}