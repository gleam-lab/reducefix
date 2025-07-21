#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 5;

int t, n, k, a[MAXN], b[MAXN];

// Comparator function for sorting pairs based on the ratio of second element to first element
bool cmp(const pair<int, int>& p1, const pair<int, int>& p2) {
    return (double)p1.second / p1.first > (double)p2.second / p2.first;
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

        // Create pairs and sort them based on the ratio of B_i / A_i
        for (int i = 0; i < n; ++i) p[i] = {a[i], b[i]};
        sort(p.begin(), p.end(), cmp);

        // Calculate the initial sum of the largest K elements in B
        for (int i = 0; i < k; ++i) sum += p[i].second;

        // Initialize the answer with the product of the maximum A_i in the first K elements and the sum of B_i
        ans = p[k - 1].first * sum;

        // Use two-pointer technique to find the minimum possible value
        int j = k;
        for (int i = k; i < n && j > 0; ++i) {
            if (p[j - 1].second <= p[i].second) continue;
            sum -= p[j - 1].second;
            sum += p[i].second;
            --j;
            ans = min(ans, (long long)p[i].first * sum);
        }

        cout << ans << "\n";
    }

    return 0;
}