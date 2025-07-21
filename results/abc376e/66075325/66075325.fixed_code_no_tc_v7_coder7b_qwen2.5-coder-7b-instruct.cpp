#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

#define ll long long

const int N = 2e5 + 9, INF = 0x3f3f3f3f3f3f3f3f;
int n, m, t, ans, k;
ll s;
pair<ll, ll> a[N], b[N];

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);

    cin >> t;
    while (t--) {
        cin >> n >> k;
        for (int i = 1; i <= n; ++i) {
            cin >> a[i].first;
            a[i].second = i;
        }
        for (int i = 1; i <= n; ++i) {
            cin >> b[i].first;
            b[i].second = i;
        }
        
        // Sort both arrays based on the values of A and B
        sort(a + 1, a + n + 1);
        sort(b + 1, b + n + 1);

        // Initialize variables to track the current sum and maximum value
        ll current_sum = 0, max_value = 0;
        priority_queue<int, vector<int>, greater<int>> pq;

        // Iterate through the sorted array A
        for (int i = 0; i < n; ++i) {
            // Add the corresponding value from B to the sum
            current_sum += b[a[i].second].first;
            pq.push(b[a[i].second].first);

            // If the size of the priority queue exceeds k, remove the smallest element
            if (pq.size() > k) {
                current_sum -= pq.top();
                pq.pop();
            }

            // Update the maximum value encountered so far
            max_value = max(max_value, a[i].first);

            // Calculate the result if we have enough elements in the priority queue
            if (pq.size() == k) {
                ans = min(ans, max_value * current_sum);
            }
        }

        cout << ans << endl;
    }

    return 0;
}