#include <bits/stdc++.h>
using namespace std;

const int maxN = 2e5 + 5;
int t, n, k, a[maxN], b[maxN];

// Comparator function to sort pairs based on the first element in descending order
bool cmp(const pair<int, int>& p1, const pair<int, int>& p2) {
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
        vector<pair<int, int>> p(n);
        long long sum = 0, ans = LLONG_MAX;

        // Read input arrays A and B
        for (int i = 0; i < n; ++i) cin >> a[i];
        for (int i = 0; i < n; ++i) cin >> b[i];

        // Create pairs of (A_i, B_i)
        for (int i = 0; i < n; ++i) p[i] = {a[i], b[i]};

        // Sort pairs based on A_i in descending order
        sort(p.begin(), p.end(), cmp);

        // Initialize sum and answer for the first K elements
        for (int i = 0; i < k; ++i) {
            sum += p[i].second;
        }
        ans = p[k-1].first * sum;

        // Iterate through the remaining elements to find the minimum value
        for (int i = k; i < n; ++i) {
            sum -= p[i-k].second;
            sum += p[i].second;
            ans = min(ans, p[i].first * sum);
        }

        cout << ans << "\n";
    }
    return 0;
}