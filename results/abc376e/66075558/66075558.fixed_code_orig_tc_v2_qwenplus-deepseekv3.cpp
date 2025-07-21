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
        vector<pair<int, int>> pairs(N);
        for (int i = 0; i < N; i++) {
            cin >> pairs[i].first;
        }
        for (int i = 0; i < N; i++) {
            cin >> pairs[i].second;
        }

        sort(pairs.begin(), pairs.end());

        if (K == 1) {
            int min_val = INF;
            for (int i = 0; i < N; i++) {
                min_val = min(min_val, pairs[i].first * pairs[i].second);
            }
            cout << min_val << '\n';
            continue;
        }

        priority_queue<int> pq;
        int sum = 0;
        int res = INF;

        for (int i = 0; i < N; i++) {
            if (pq.size() < K - 1) {
                pq.push(pairs[i].second);
                sum += pairs[i].second;
            } else {
                res = min(res, pairs[i].first * (sum + pairs[i].second));
                if (!pq.empty() && pairs[i].second < pq.top()) {
                    sum -= pq.top();
                    pq.pop();
                    sum += pairs[i].second;
                    pq.push(pairs[i].second);
                }
            }
        }

        cout << res << '\n';
    }
    return 0;
}