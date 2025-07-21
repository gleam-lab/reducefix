#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

#define int long long

const int MAXN = 2e5 + 5;

signed main() {
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
        // Sort B in ascending order
        sort(b.begin(), b.end());

        // Calculate the sum of the smallest K elements in B
        int sum = 0;
        for (int i = 0; i < k; ++i) {
            sum += b[i];
        }

        // Find the maximum element in the last K elements of A
        int max_a = a[n - k].first;

        // Calculate the result
        int result = max_a * sum;

        cout << result << endl;
    }
    return 0;
}