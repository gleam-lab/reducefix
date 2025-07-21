#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

#define int long long
const int N = 2e5 + 9, inf = 0x3f3f3f3f3f3f3f3f;

signed main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<pair<int, int>> a(n), b(n);
        for(int i = 0; i < n; ++i) {
            cin >> a[i].first;
            a[i].second = i;
        }
        for(int i = 0; i < n; ++i) {
            cin >> b[i].first;
            b[i].second = i;
        }
        
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());

        int ans = inf;
        for(int i = 0; i <= n-k; ++i) {
            int sum = 0;
            for(int j = 0; j < k; ++j) {
                sum += b[(a[i+j].second+k)%n].first;
            }
            ans = min(ans, static_cast<long long>(a[i+k-1].first) * sum);
        }

        cout << ans << endl;
    }
    return 0;
}