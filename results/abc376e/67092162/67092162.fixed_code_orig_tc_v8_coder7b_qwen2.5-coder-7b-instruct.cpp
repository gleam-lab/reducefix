#include <bits/stdc++.h>
using namespace std;

const int maxN = 2e5 + 5;
int t, n, k, a[maxN], b[maxN];

// Comparator function for sorting pairs based on the first element in descending order and second in ascending order
bool cmp(const pair<int, int>& p1, const pair<int, int>& p2) {
    if (p1.first != p2.first) return p1.first > p2.first;
    return p1.second < p2.second;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> t;
    while (t--) {
        cin >> n >> k;
        vector<pair<int, int>> v(n);
        long long sum = 0, ans = LLONG_MAX;

        // Collecting pairs of (A_i, B_i) into vector v
        for (int i = 0; i < n; ++i) {
            cin >> a[i] >> b[i];
            v[i] = {a[i], b[i]};
        }

        // Sorting based on the custom comparator
        sort(v.begin(), v.end(), cmp);

        // Initializing priority queue to keep track of the smallest sums of B_i
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int i = 0; i < k; ++i) {
            sum += v[i].second;
            pq.push(v[i].second);
        }

        // Calculating the initial result
        ans = min(ans, static_cast<long long>(v[k - 1].first * sum));

        // Sliding window approach to find the minimum value of max(A_i) * sum(B_i)
        for (int i = k; i < n; ++i) {
            sum -= pq.top();
            pq.pop();
            sum += v[i].second;
            pq.push(v[i].second);
            ans = min(ans, static_cast<long long>(v[i].first * sum));
        }

        cout << ans << "\n";
    }

    return 0;
}