#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define int long long

int32_t main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<pair<int, int>> a(n);
        vector<pair<int, int>> b(n);
        
        for (int i = 0; i < n; ++i) {
            cin >> a[i].first;
            a[i].second = i;
        }
        for (int i = 0; i < n; ++i) {
            cin >> b[i].first;
            b[i].second = i;
        }
        
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        
        int l = 0, r = 0, sum = 0, ans = INT_MAX;
        while (r < n) {
            sum += b[r].first;
            if (r - l + 1 < k) {
                r++;
            } else if (r - l + 1 == k) {
                ans = min(ans, a[r - 1].first * sum);
                sum -= b[l].first;
                if (b[l].second == a[r - 1].second) {
                    break;
                }
                l++;
            }
            if (b[l].second > a[r - 1].second) {
                break;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}