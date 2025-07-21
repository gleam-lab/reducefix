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
        vector<int> a(n), b(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        for (int i = 0; i < n; ++i) {
            cin >> b[i];
        }

        sort(a.begin(), a.end());
        sort(b.begin(), b.end());

        long long ans = 0;
        long long sum = 0;
        for (int i = 0; i < k; ++i) {
            ans = max(ans, (long long)a[i] * sum);
            sum += b[i];
        }

        for (int i = k; i < n; ++i) {
            sum -= b[i - k];
            sum += b[i];
            ans = min(ans, (long long)a[i] * sum);
        }

        cout << ans << endl;
    }
    return 0;
}