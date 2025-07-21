#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define int long long
const int N = 200005;

int t, n, k;
int a[N], b[N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> t;
    while (t--) {
        cin >> n >> k;
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
        }
        for (int i = 1; i <= n; ++i) {
            cin >> b[i];
        }

        // Create pairs of (A[i], B[i]) and sort by A[i]
        vector<pair<int, int>> cb(N);
        for (int i = 0; i < n; ++i) {
            cb[i] = {a[i], b[i]};
        }
        sort(cb.begin(), cb.end());

        // Use a priority queue to maintain the largest k B[i] values for each A[i]
        priority_queue<int> pq;
        long long sum = 0, max_B_sum = 0;
        for (int i = 0; i < n; ++i) {
            pq.push(cb[i].second);
            if (pq.size() > k) {
                sum -= pq.top();
                pq.pop();
            }
            if (pq.size() == k) {
                sum += cb[i].second;
                max_B_sum = max(max_B_sum, sum);
            }
        }

        // Output the result for the current test case
        cout << max_B_sum * cb[k - 1].first << '\n';
    }
    
    return 0;
}