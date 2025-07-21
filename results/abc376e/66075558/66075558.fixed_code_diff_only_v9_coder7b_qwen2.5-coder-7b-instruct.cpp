#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define int long long
const int N = 2e5 + 9, inf = 0x3f3f3f3f3f3f3f3f;
int n, k, t, ans;
pair<int, int> a[N], b[N];

bool cmp(pair<int, int> pa, pair<int, int> pb) {
    return pa.first == pb.first ? b[pa.second] < b[pb.second] : pa.first < pb.first;
}

signed main() {
    cin >> t;
    while (t--) {
        cin >> n >> k;
        for (int i = 1; i <= n; i++) {
            cin >> a[i].first;
            a[i].second = i;
        }
        for (int i = 1; i <= n; i++) {
            cin >> b[i].first;
            b[i].second = i;
        }
        sort(a + 1, a + n + 1, cmp);
        sort(b + 1, b + n + 1, [](const pair<int, int>& p1, const pair<int, int>& p2) {return p1.first > p2.first; });
        
        int max_a = a[k].first;
        int sum_b = 0;
        for(int i = 1; i <= k; ++i){
            sum_b += b[i].first;
        }
        ans = max_a * sum_b;

        for (int i = k + 1; i <= n; i++) {
            sum_b -= b[i-k].first;
            sum_b += b[i].first;
            max_a = max(max_a, a[i].first);
            ans = min(ans, max_a * sum_b);
        }
        cout << ans << endl;
    }
    return 0;
}