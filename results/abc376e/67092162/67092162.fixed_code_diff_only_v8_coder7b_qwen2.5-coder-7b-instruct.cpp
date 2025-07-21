#include <bits/stdc++.h>
using namespace std;
const int maxN = 2e5 + 5;
int t, n, k, a[maxN], b[maxN];
pair<int, int> p[maxN];

// Comparator function to sort pairs based on first element descending and second element ascending
bool cmp(pair<int, int> p1, pair<int, int> p2) {
    if (p1.first != p2.first) return p1.first > p2.first;
    return p1.second < p2.second;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t;
    while (t--) {
        cin >> n >> k;
        priority_queue<int> q;
        long long sum = 0, ans = LLONG_MAX;

        // Read input arrays
        for (int i = 1; i <= n; i++) cin >> a[i];
        for (int i = 1; i <= n; i++) cin >> b[i];

        // Pair elements of A and B and store them
        for (int i = 1; i <= n; i++) {
            p[i] = {a[i], b[i]};
        }

        // Sort pairs using custom comparator
        sort(p + 1, p + n + 1, cmp);

        // Initialize priority queue with first k elements' B values and calculate initial sum
        for (int i = 1; i <= k; i++) {
            sum += p[i].second;
            q.push(p[i].second);
        }

        // Calculate initial answer
        ans = min(ans, static_cast<long long>(p[k].first) * sum);

        // Iterate through remaining elements to find minimum possible value
        for (int i = k + 1; i <= n; i++) {
            if (p[i].second < q.top()) {
                sum -= q.top();
                q.pop();
                q.push(p[i].second);
                sum += p[i].second;
            }
            ans = min(ans, static_cast<long long>(p[i].first) * sum);
        }

        // Print result for current test case
        cout << ans << "\n";
    }
    return 0;
}