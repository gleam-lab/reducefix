#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

#define int long long

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

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
        }

        // Sort A by the first element in descending order
        sort(a.begin(), a.end(), [&](const pair<int, int>& p1, const pair<int, int>& p2) {
            return p1.first > p2.first;
        });

        // Sort B by the first element in ascending order
        sort(b.begin(), b.end());

        int ans = 0;
        for(int i = 0; i < k; ++i) {
            ans += a[i].first * b[a[i].second].first;
        }

        cout << ans << '\n';
    }
    return 0;
}