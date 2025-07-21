#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

// Custom comparator for min-heap
struct cmp {
    bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
        return a.second > b.second;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        int N, K;
        cin >> N >> K;

        vector<pair<int, int>> AB(N);
        for (int i = 0; i < N; ++i) {
            cin >> AB[i].first; // A[i]
        }
        for (int i = 0; i < N; ++i) {
            cin >> AB[i].second; // B[i]
        }

        // Sort by A values
        sort(AB.begin(), AB.end());

        // Min-heap to store B values
        priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
        long long sum_b = 0;
        long long res = 1e18; // Initialize to a large number

        for (int i = 0; i < N; ++i) {
            pq.push(AB[i]);
            sum_b += AB[i].second;

            // Maintain only K elements in the heap
            while (pq.size() > K) {
                sum_b -= pq.top().second;
                pq.pop();
            }

            // If we have K elements, calculate the result
            if (pq.size() == K) {
                res = min(res, AB[i].first * sum_b);
            }
        }

        cout << res << "\n";
    }

    return 0;
}