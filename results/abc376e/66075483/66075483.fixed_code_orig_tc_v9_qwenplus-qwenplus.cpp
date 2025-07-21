#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

// Define a type alias for clarity
using ll = long long;
using PII = pair<ll, ll>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;

    while (T--) {
        int N, K;
        cin >> N >> K;

        vector<PII> AB(N);
        for (int i = 0; i < N; ++i) {
            cin >> AB[i].first; // A[i]
        }
        for (int i = 0; i < N; ++i) {
            cin >> AB[i].second; // B[i]
        }

        // Sort the pairs by A value
        sort(AB.begin(), AB.end());

        // Min-heap to keep track of K smallest B values
        priority_queue<ll, vector<ll>, greater<ll>> pq;
        ll sum_b = 0;
        ll result = 1e18; // Large enough initial value

        for (int i = 0; i < N; ++i) {
            sum_b += AB[i].second;
            pq.push(AB[i].second);

            // If we have more than K elements, remove the one with smallest B
            if (pq.size() > K) {
                sum_b -= pq.top();
                pq.pop();
            }

            // Once we have exactly K elements, update the answer
            if (pq.size() == K) {
                result = min(result, AB[i].first * sum_b);
            }
        }

        cout << result << endl;
    }

    return 0;
}