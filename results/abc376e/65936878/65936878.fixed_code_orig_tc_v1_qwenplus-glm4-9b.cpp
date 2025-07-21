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
        vector<pair<int, int>> combined(N);
        for (int i = 0; i < N; ++i) {
            cin >> combined[i].first >> combined[i].second;
        }

        // Sort by A descending
        sort(combined.begin(), combined.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
            return a.first > b.first;
        });

        priority_queue<int, vector<int>, greater<int>> pq;
        long long sum_B = 0;
        long long min_product = LLONG_MAX;

        for (int i = 0; i < N; ++i) {
            pq.push(combined[i].second);
            sum_B += combined[i].second;

            if (pq.size() > K) {
                sum_B -= pq.top();
                pq.pop();
            }

            if (pq.size() == K) {
                min_product = min(min_product, static_cast<long long>(combined[i].first) * sum_B);
            }
        }

        cout << min_product << '\n';
    }

    return 0;
}