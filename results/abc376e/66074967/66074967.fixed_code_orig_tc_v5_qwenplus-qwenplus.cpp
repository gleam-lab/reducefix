#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        int N, K;
        cin >> N >> K;

        vector<pair<int, int>> A(N);
        for (int i = 0; i < N; ++i) {
            cin >> A[i].first;
            A[i].second = i;
        }

        vector<int> B(N);
        for (int i = 0; i < N; ++i) {
            cin >> B[i];
        }

        // Sort by A[i]
        sort(A.begin(), A.end());

        long long sum_b = 0;
        priority_queue<int, vector<int>, greater<>> min_heap;
        long long result = 1e18;  // Large initial value

        for (int i = 0; i < N; ++i) {
            int a_val = A[i].first;
            int b_val = B[A[i].second];

            min_heap.push(b_val);
            sum_b += b_val;

            if (min_heap.size() > K) {
                sum_b -= min_heap.top();
                min_heap.pop();
            }

            if (min_heap.size() == K) {
                result = min(result, sum_b * a_val);
            }
        }

        cout << result << '\n';
    }

    return 0;
}