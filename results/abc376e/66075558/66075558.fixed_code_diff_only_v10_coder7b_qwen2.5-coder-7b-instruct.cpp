#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

#define int long long
const int N = 2e5 + 9, inf = 0x3f3f3f3f3f3f3f3f;

struct Node {
    int val, idx;
};

bool cmp(const Node &a, const Node &b) {
    return a.val > b.val || (a.val == b.val && a.idx < b.idx);
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    int t; cin >> t;
    while(t--){
        int n, k; cin >> n >> k;
        
        vector<Node> a(n), b(n);
        for(int i = 0; i < n; ++i){
            cin >> a[i].val; a[i].idx = i;
        }
        for(int i = 0; i < n; ++i){
            cin >> b[i].val; b[i].idx = i;
        }
        
        sort(a.begin(), a.end(), cmp);
        sort(b.begin(), b.end(), cmp);
        
        vector<int> sum(n+1);
        for(int i = 1; i <= n; ++i){
            sum[i] = sum[i-1] + b[i-1].val;
        }
        
        int ans = inf;
        for(int i = 0; i <= n-k; ++i){
            ans = min(ans, (long long)a[i].val * sum[i+k]);
        }
        
        cout << ans << '\n';
    }
    
    return 0;
}