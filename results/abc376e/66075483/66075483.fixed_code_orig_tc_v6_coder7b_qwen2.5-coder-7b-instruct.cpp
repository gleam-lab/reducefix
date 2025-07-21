#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

#define int long long

const int N = 2e5 + 9, inf = 0x3f3f3f3f3f3f3f3f;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;

        vector<pair<int, int>> a(n), b(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i].first;
            a[i].second = i;
        }
        for (int i = 0; i < n; ++i) {
            cin >> b[i].first;
            b[i].second = i;
        }

        // Sort both arrays based on their first element
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());

        // Priority queue to store the sums of B elements
        priority_queue<int, vector<int>, greater<int>> pq;
        int sum = 0;
        for (int i = 0; i < k; ++i) {
            sum += b[i].first;
            pq.push(b[i].first);
        }

        // Initialize the result with the initial sum
        int ans = sum * a[k - 1].first;

        // Iterate through the remaining elements
        for (int i = k; i < n; ++i) {
            // Remove the smallest element from the current sum and add the next largest one
            sum += b[i].first - pq.top();
            pq.pop();
            pq.push(b[i].first);

            // Update the result with the new product
            ans = min(ans, sum * a[i].first);
        }

        cout << ans << '\n';
    }

    return 0;
}