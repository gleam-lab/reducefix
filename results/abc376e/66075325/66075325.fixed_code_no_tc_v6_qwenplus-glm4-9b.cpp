#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<pair<int, int>> a(n), b(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i].first;
            a[i].second = i;
        }
        for (int i = 0; i < n; i++) {
            cin >> b[i].first;
            b[i].second = i;
        }
        // Sort by A values to optimize finding max A_i in any subset of size k
        sort(a.begin(), a.end(), [](const pair<int, int>& p1, const pair<int, int>& p2) {
            return p1.first > p2.first;
        });
        // Sort by B values to calculate prefix sums efficiently
        sort(b.begin(), b.end(), [](const pair<int, int>& p1, const pair<int, int>& p2) {
            return p1.first > p2.first;
        });

        long long ans = LLONG_MAX;
        long long sumB = 0; // Prefix sum of B values
        long long maxA = a[0].first; // Max A value in the first k elements
        long long sumAB = 0; // Sum of A_i * B_j for i in S and j in S

        // Calculate initial prefix sum and max A for first k elements
        for (int i = 0; i < k; i++) {
            sumB += b[i].first;
            sumAB += a[i].first * b[i].first;
        }

        // Calculate the minimum possible value for the expression
        ans = min(ans, maxA * sumB);

        // Slide over all possible subsets of size k
        for (int i = k; i < n; i++) {
            sumB += b[i].first - b[i - k].first;
            sumAB = sumAB - sumAB / k * k + sumAB - k * b[i - k].first + b[i].first;
            maxA = a[i].first;
            ans = min(ans, maxA * sumB);
        }

        cout << ans << endl;
    }
    return 0;
}