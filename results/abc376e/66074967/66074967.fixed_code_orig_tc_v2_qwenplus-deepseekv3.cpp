#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
#define int long long

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

        priority_queue<int> max_heap;
        int sum = 0;
        int ans = 1LL << 60;

        for (int i = 0; i < N; ++i) {
            sum += pairs[i].second;
            max_heap.push(pairs[i].second);

            if (max_heap.size() > K) {
                sum -= max_heap.top();
                max_heap.pop();
            }

            if (max_heap.size() == K) {
                ans = min(ans, sum * pairs[i].first);
            }
        }

        cout << ans << '\n';
    }

    return 0;
}