#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<pair<int, int>> A(n);
        for (int i = 0; i < n; ++i) {
            cin >> A[i].first;
            A[i].second = i + 1;  // Using 1-based index for easier access
        }
        vector<int> B(n);
        for (int i = 0; i < n; ++i) {
            cin >> B[i];
        }

        sort(A.begin(), A.end());

        priority_queue<int, vector<int>, greater<int>> pq;
        long long sum = 0;
        long long ans = LLONG_MAX;

        for (int i = 0; i < n; ++i) {
            sum += B[i];
            pq.push(B[i]);
            if (pq.size() > k) {
                sum -= pq.top();
                pq.pop();
            }
            if (pq.size() == k) {
                ans = min(ans, (sum + B[i + 1]) * A[i].first);
            }
        }

        cout << ans << endl;
    }
    return 0;
}