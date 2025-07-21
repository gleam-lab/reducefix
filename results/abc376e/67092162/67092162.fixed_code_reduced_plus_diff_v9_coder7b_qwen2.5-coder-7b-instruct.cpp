#include <bits/stdc++.h>
using namespace std;

const int maxN = 2e5 + 5;
int t, n, k, a[maxN], b[maxN];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t;
    while (t--) {
        cin >> n >> k;
        vector<pair<int, int>> pairs(n);

        // Read input into pairs
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            pairs[i] = {a[i], b[i]};
        }

        // Sort pairs based on A in descending order and B in ascending order
        sort(pairs.begin(), pairs.end(), [&](const pair<int, int>& p1, const pair<int, int>& p2) {
            if (p1.first == p2.first) return p1.second < p2.second;
            return p1.first > p2.first;
        });

        long long maxA = pairs[k - 1].first;
        long long sumB = 0;
        
        // Calculate the sum of the smallest K elements in B
        for (int i = 0; i < k; ++i) {
            sumB += pairs[n - 1 - i].second;
        }

        // Output the result
        cout << maxA * sumB << "\n";
    }
    return 0;
}