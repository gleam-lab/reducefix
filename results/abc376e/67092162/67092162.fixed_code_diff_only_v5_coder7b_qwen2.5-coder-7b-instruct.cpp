#include <bits/stdc++.h>
using namespace std;

const int maxN = 2e5 + 5;
int t, n, k, a[maxN], b[maxN];
pair<int, int> p[maxN];

// Comparator function to sort pairs based on first element
bool cmp(const pair<int, int>& p1, const pair<int, int>& p2) {
    if (p1.first != p2.first)
        return p1.first < p2.first;
    return p1.second < p2.second;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t;
    while (t--) {
        cin >> n >> k;
        vector<pair<int, int>> vec(n);
        int sum = 0, ans = INT_MAX;

        // Store pairs of A_i and B_i
        for (int i = 0; i < n; ++i) {
            cin >> a[i] >> b[i];
            vec[i] = {a[i], b[i]};
        }

        // Sort the pairs based on A_i
        sort(vec.begin(), vec.end(), cmp);

        // Initialize the sum of B_i for the first K elements
        for (int i = 0; i < k; ++i) {
            sum += vec[i].second;
        }

        // Calculate the initial answer
        ans = min(ans, sum * vec[k - 1].first);

        // Sliding window approach to find the minimum possible value
        for (int i = k; i < n; ++i) {
            sum -= vec[i - k].second;
            sum += vec[i].second;
            ans = min(ans, sum * vec[i].first);
        }

        cout << ans << "\n";
    }
    return 0;
}