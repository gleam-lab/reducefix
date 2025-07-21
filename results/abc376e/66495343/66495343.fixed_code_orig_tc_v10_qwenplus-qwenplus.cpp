#include <bits/stdc++.h>
using namespace std;

#define int long long
#define PII pair<int, int>
#define fi first
#define se second

const int INF = 1e18;

int T;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> T;

    while (T--) {
        int N, K;
        cin >> N >> K;

        vector<PII> pairs(N);
        for (int i = 0; i < N; ++i) {
            cin >> pairs[i].fi;
        }
        for (int i = 0; i < N; ++i) {
            cin >> pairs[i].se;
        }

        // Sort by A_i in ascending order
        sort(pairs.begin(), pairs.end());

        priority_queue<int> min_heap; // use a min-heap to store B_i values
        int sum_b = 0;
        int result = INF;

        for (int i = 0; i < N; ++i) {
            int a = pairs[i].fi;
            int b = pairs[i].se;

            if (min_heap.size() < K) {
                sum_b += b;
                min_heap.push(-b); // Use max-heap as min-heap by negating values
            } else {
                // Maintain only the smallest K B values
                if (!min_heap.empty() && b < -min_heap.top()) {
                    sum_b += b + min_heap.top();
                    min_heap.pop();
                    min_heap.push(-b);
                }
            }

            if (min_heap.size() == K) {
                result = min(result, a * sum_b);
            }
        }

        cout << result << '\n';
    }

    return 0;
}