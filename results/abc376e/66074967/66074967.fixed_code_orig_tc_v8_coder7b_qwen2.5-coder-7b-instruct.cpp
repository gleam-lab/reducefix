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
        vector<pair<int, int>> a(n);
        vector<int> b(n);

        for (int i = 0; i < n; ++i) {
            cin >> a[i].first;
            a[i].second = i;
        }
        
        for (int i = 0; i < n; ++i) {
            cin >> b[i];
        }

        // Sort A based on the first element
        sort(a.begin(), a.end());
        // Sort B based on the original indices of A
        sort(b.begin(), b.end(), [&](int i, int j) {
            return a[i] < a[j];
        });

        long long ans = LLONG_MAX;
        long long sum = 0;

        // Calculate initial sum of the smallest k-1 elements in B
        for (int i = 0; i < k - 1; ++i) {
            sum += b[a[i].second];
        }

        // Iterate through the sorted A and find the minimum product
        for (int i = k - 1; i < n; ++i) {
            long long product = (long long)a[i].first * (sum + b[a[i].second]);
            ans = min(ans, product);
            sum += b[a[i].second] - b[a[i - k + 1].second];
        }

        cout << ans << endl;
    }
    return 0;
}