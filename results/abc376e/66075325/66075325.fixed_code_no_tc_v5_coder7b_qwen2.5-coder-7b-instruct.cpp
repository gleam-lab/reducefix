#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

#define int long long

const int N = 2e5 + 9, inf = 0x3f3f3f3f3f3f3f3f;

signed main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
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

        int ans = inf, s = 0;
        for(int i = 0; i < k; ++i) {
            s += b[i].first;
        }
        for(int i = 0; i <= n - k; ++i) {
            ans = min(ans, (long long)a[i+k-1].first * (s));
            if(i + k < n) {
                s -= b[i].first;
                s += b[i+k].first;
            }
        }

        cout << ans << endl;
    }
    return 0;
}