#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

#define int long long

int n, m, t, ans, k;
vector<pair<int, int>> a, b;

bool cmp(const pair<int, int>& pa, const pair<int, int>& pb) {
    return pa.first == pb.first ? b[pa.second] < b[pb.second] : pa.first < pb.first;
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    cin >> t;
    while (t--) {
        a.clear(), b.clear();
        
        cin >> n >> k;
        a.resize(n+1), b.resize(n+1);
        
        for (int i = 1; i <= n; ++i) {
            cin >> a[i].first;
            a[i].second = i;
        }
        
        for (int i = 1; i <= n; ++i) {
            cin >> b[i].first;
            b[i].second = i;
        }
        
        sort(a.begin()+1, a.end(), cmp);
        
        int current_sum = 0, max_a = 0;
        for (int i = 1; i <= n; ++i) {
            current_sum += b[a[i].second].first;
            max_a = max(max_a, a[i].first);
            
            if (i >= k) {
                current_sum -= b[a[i-k+1].second].first;
            }
            
            if (i >= k) {
                ans = min(ans, static_cast<long long>(current_sum) * max_a);
            }
        }
        
        cout << ans << '\n';
    }
    
    return 0;
}