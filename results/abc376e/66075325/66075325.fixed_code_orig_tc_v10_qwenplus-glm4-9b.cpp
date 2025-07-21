#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct pair_hash {
    template <class T1, class T2>
    std::size_t operator () (const std::pair<T1,T2> &pair) const {
        auto hash1 = std::hash<T1>{}(pair.first);
        auto hash2 = std::hash<T2>{}(pair.second);
        return hash1 ^ hash2;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> A(n), B(n);
        for (int i = 0; i < n; i++) {
            cin >> A[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> B[i];
        }

        // Pairing A and B and sorting by A
        vector<pair<int, int>> ab(n);
        for (int i = 0; i < n; i++) {
            ab[i] = {A[i], B[i]};
        }
        sort(ab.begin(), ab.end());

        // Priority queue to maintain the sum of B values for the last k elements
        priority_queue<int, vector<int>, greater<int>> pq;
        long long ans = LLONG_MAX;
        long long sum = 0;

        for (int i = 0; i < n; i++) {
            sum += ab[i].second;
            pq.push(ab[i].second);
            if (pq.size() > k) {
                sum -= pq.top();
                pq.pop();
            }
            if (pq.size() == k) {
                ans = min(ans, (long long) pq.top() * sum);
            }
        }

        cout << ans << endl;
    }
    return 0;
}