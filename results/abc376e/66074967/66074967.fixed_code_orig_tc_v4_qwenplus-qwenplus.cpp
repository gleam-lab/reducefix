#include <bits/stdc++.h>
using namespace std;

#define int long long

const int INF = 1e18;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;

    while (T--) {
        int N, K;
        cin >> N >> K;

        vector<pair<int, int>> A(N), B(N);
        for (int i = 0; i < N; ++i) {
            cin >> A[i].first;
            A[i].second = i;
        }
        for (int i = 0; i < N; ++i) {
            cin >> B[i].first;
        }

        // Sort elements by A value in increasing order
        sort(A.begin(), A.end());

        // Create a mapping from original index to B value
        vector<int> b(N);
        for (int i = 0; i < N; ++i) {
            b[A[i].second] = B[i].first;
        }

        // We'll process elements in the order of increasing A values
        priority_queue<int> max_heap;
        int sum_b = 0;
        int result = INF;

        vector<int> sorted_b;

        for (int i = 0; i < N; ++i) {
            int current_a = A[i].first;
            int current_b = b[A[i].second];

            sum_b += current_b;
            max_heap.push(current_b);
            sorted_b.push_back(current_b);

            if (max_heap.size() > K) {
                int removed = max_heap.top();
                max_heap.pop();
                sum_b -= removed;
            }

            if (max_heap.size() == K) {
                result = min(result, max_heap.top() * current_a);
            }
        }

        cout << result << endl;
    }

    return 0;
}