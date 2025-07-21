#include <bits/stdc++.h>
using namespace std;

#define int long long

struct cmp {
    bool operator()(pair<int, int>& a, pair<int, int>& b) {
        return a.second < b.second; // Max heap for B values
    }
};

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        int N, K;
        cin >> N >> K;

        vector<pair<int, int>> AB(N);
        for (int i = 0; i < N; ++i) {
            cin >> AB[i].first;
        }
        for (int i = 0; i < N; ++i) {
            cin >> AB[i].second;
        }

        // Sort by A
        sort(AB.begin(), AB.end());

        priority_queue<int> max_heap;
        int sum_b = 0;
        int result = numeric_limits<int>::max();

        for (int i = 0; i < N; ++i) {
            sum_b += AB[i].second;
            max_heap.push(AB[i].second);

            if (max_heap.size() > K) {
                sum_b -= max_heap.top();
                max_heap.pop();
            }

            if (max_heap.size() == K) {
                result = min(result, AB[i].first * sum_b);
            }
        }

        cout << result << "\n";
    }

    return 0;
}