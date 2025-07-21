#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, k;
        cin >> n >> k;

        vector<pair<int, int>> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i].first;
        }
        for (int i = 0; i < n; ++i) {
            cin >> a[i].second;
        }

        // Sort by the first element descending, if equal, then by the second element descending
        sort(a.begin(), a.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
            return a.first > b.first || (a.first == b.first && a.second > b.second);
        });

        // We need the largest k elements, which are the first k elements in the sorted vector
        long long max_a = a[k - 1].first;
        long long sum_b = 0;

        // Calculate the sum of the second elements of the first k elements
        for (int i = 0; i < k; ++i) {
            sum_b += a[i].second;
        }

        // The answer for this test case
        long long answer = max_a * sum_b;
        cout << answer << endl;
    }

    return 0;
}