#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define int long long
const int inf = 0x3f3f3f3f3f3f3f3f;

signed main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<pair<int, int>> a(n), b(n);
        for(int i = 0; i < n; ++i){
            cin >> a[i].first;
            a[i].second = i;
        }
        for(int i = 0; i < n; ++i){
            cin >> b[i].first;
            b[i].second = i;
        }
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());

        int ans = inf, s = 0;
        priority_queue<int> pq;
        for(int i = 0; i < k - 1; ++i){
            pq.push(b[i].first);
            s += b[i].first;
        }
        for(int i = k - 1; i < n; ++i){
            s += b[i].first;
            pq.push(b[i].first);
            ans = min(ans, (long long)a[i].first * s);
            s -= pq.top();
            pq.pop();
        }
        cout << ans << '\n';
    }
    return 0;
}