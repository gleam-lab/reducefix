#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

#define int long long

const int N = 2e5 + 9, inf = 0x3f3f3f3f3f3f3f3f;
int n, m, t, ans, k;
int s, q;
pair<int, int> a[N], b[N];

bool cmp(pair<int, int> pa, pair<int, int> pb) {
    return pa.first == pb.first ? b[pa.second] < b[pb.second] : pa.first < pb.first;
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    cin >> t;
    while (t--) {
        cin >> n >> k;
        for (int i = 1; i <= n; i++) {
            cin >> a[i].first;
            a[i].second = i;
        }
        for (int i = 1; i <= n; i++) {
            cin >> b[i];
        }
        
        sort(a + 1, a + n + 1, cmp);
        
        int sum_b = 0;
        for(int i=1;i<=k;i++){
            sum_b += b[a[i].second];
        }
        
        ans = sum_b * a[k].first;
        for(int i=k+1;i<=n;i++){
            sum_b += b[a[i].second] - b[a[i-k].second];
            ans = min(ans, sum_b * a[i].first);
        }
        
        cout << ans << endl;
    }
    return 0;
}