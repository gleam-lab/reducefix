#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

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
        
        vector<pair<int, int>> items(N);
        for (int i = 0; i < N; ++i) {
            cin >> items[i].first;
        }
        for (int i = 0; i < N; ++i) {
            cin >> items[i].second;
        }

        // Sort by A_i ascending
        sort(items.begin(), items.end());

        // Minimize (max_A_S) * (sum_B_S), where |S| = K

        // We'll maintain a max-heap of size K to keep the smallest K B's in top K elements
        priority_queue<int> pq;

        ll sum_b = 0;
        ll result = numeric_limits<ll>::max();

        // First, try the first K elements
        for (int i = 0; i < K; ++i) {
            sum_b += items[i].second;
            pq.push(items[i].second);
        }

        result = (ll)items[K - 1].first * sum_b;

        // Then consider each next element as candidate for new maximum
        for (int i = K; i < N; ++i) {
            if (pq.empty() || items[i].second < pq.top()) {
                // Replace larger B with smaller one to reduce sum_b
                if (!pq.empty()) {
                    sum_b -= pq.top();
                    pq.pop();
                }
                sum_b += items[i].second;
                pq.push(items[i].second);
                
                result = min(result, (ll)items[i].first * sum_b);
            }
        }

        cout << result << "\n";
    }

    return 0;
}