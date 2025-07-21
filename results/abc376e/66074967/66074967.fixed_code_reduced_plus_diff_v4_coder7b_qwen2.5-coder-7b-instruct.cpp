#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

#define int long long
#define INF 1000000009

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        
        vector<pair<int, int>> A(n), B(n);
        for (int i = 0; i < n; ++i) {
            cin >> A[i].first;
            A[i].second = i + 1;
        }
        for (int i = 0; i < n; ++i) {
            cin >> B[i].first;
            B[i].second = i + 1;
        }

        // Sort A and B based on their first element in descending order
        sort(A.rbegin(), A.rend());
        sort(B.rbegin(), B.rend());

        // Priority queue to keep track of the sum of B values
        priority_queue<int, vector<int>, greater<int>> pq;
        int sumB = 0;
        for (int i = 0; i < k; ++i) {
            pq.push(B[i].first);
            sumB += B[i].first;
        }

        int ans = INF;
        for (int i = 0; i < k; ++i) {
            ans = min(ans, (A[i].first * sumB));
            if (i + 1 < n) {
                sumB -= pq.top();
                pq.pop();
                pq.push(B[i + 1].first);
                sumB += B[i + 1].first;
            }
        }

        cout << ans << endl;
    }

    return 0;
}