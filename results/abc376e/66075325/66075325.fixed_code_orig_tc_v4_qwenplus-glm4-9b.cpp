#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, K;
        cin >> N >> K;
        vector<pair<int, int>> AB(N);
        for (int i = 0; i < N; i++) {
            cin >> AB[i].first >> AB[i].second;
        }
        sort(AB.begin(), AB.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
            return a.first > b.first;
        });

        long long ans = LLONG_MAX;
        long long sumB = 0;
        priority_queue<int> pq;

        for (int i = 0; i < N; i++) {
            sumB += AB[i].second;
            pq.push(AB[i].second);
            if (pq.size() > K) {
                sumB -= pq.top();
                pq.pop();
            }
            if (i >= K - 1) {
                ans = min(ans, (long long)AB[i].first * sumB);
            }
        }

        cout << ans << endl;
    }
    return 0;
}