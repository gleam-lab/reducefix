#include <bits/stdc++.h>
using namespace std;
#define int long long
#define PII pair<int, int>

int t;
int n, k;
vector<PII> arr;

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t;
    while (t--) {
        cin >> n >> k;

        arr.assign(n + 1, {0, 0});  // Assign default values
        for (int i = 1; i <= n; i++) {
            cin >> arr[i].first;  // A_i
            cin >> arr[i].second; // B_i
        }

        // Sort by A_i in descending order
        sort(arr.begin() + 1, arr.begin() + n + 1, greater<PII>());

        // Priority queue to track sum of B_i for the top (k-1) elements
        priority_queue<int> pq;
        int res = LLONG_MAX, sum = 0;

        // Calculate initial sum for the first (k-1) elements
        for (int i = 1; i <= k - 1; i++) {
            sum += arr[i].second;
            pq.push(arr[i].second);
        }

        // Compute minimum value for expression
        for (int i = k; i <= n; i++) {
            sum += arr[i].second;
            pq.push(arr[i].second);

            if (pq.size() > k - 1) {
                int big = pq.top();
                pq.pop();
                sum -= big;
            }

            res = min(res, arr[i].first * sum);
        }

        cout << res << '\n';
    }

    return 0;
}