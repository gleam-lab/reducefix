#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using P = pair<int, int>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;

    while (T--) {
        int N, K;
        cin >> N >> K;

        vector<P> AB(N);
        for (int i = 0; i < N; ++i) {
            cin >> AB[i].first; // A_i
        }
        for (int i = 0; i < N; ++i) {
            cin >> AB[i].second; // B_i
        }

        // Sort by A_i ascending
        sort(AB.begin(), AB.end());

        priority_queue<int, vector<int>, greater<>> min_heap;
        ll sum_b = 0;

        // Initialize the first K elements
        for (int i = 0; i < K; ++i) {
            sum_b += AB[i].second;
            min_heap.push(AB[i].second);
        }

        ll ans = 1LL * AB[K - 1].first * sum_b;

        // Try including better combinations
        for (int i = K; i < N; ++i) {
            if (AB[i].second > min_heap.top()) {
                sum_b -= min_heap.top();
                min_heap.pop();
                sum_b += AB[i].second;
                min_heap.push(AB[i].second);
            }
            ans = min(ans, 1LL * AB[i].first * sum_b);
        }

        cout << ans << '\n';
    }

    return 0;
}