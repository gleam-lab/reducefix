#include<bits/stdc++.h>
#define endl "\n"
#define lowbit(x) (x & (-x))
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef double db;

const int INF = 0x3f3f3f3f;
const db eps = 1e-9;
const ll mod = 1e9 + 7;
const int N = 1e5 + 5;
int a[N], b[N];

bool check(vector<int>& dists, int k) {
    sort(dists.begin(), dists.end());
    return dists[k - 1] <= dists.back();
}

void solve(void) {
    int n, q; cin >> n >> q;
    vector<int> dists(n);
    
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    
    for(int i = 1; i <= q; i++) {
        cin >> b[i] >> a[i];
    }
    
    for(int i = 1; i <= q; i++) {
        for(int j = 1; j <= n; j++) {
            dists[j - 1] = abs(a[j] - b[i]);
        }
        
        int l = 1, r = n;
        while(l < r) {
            int mid = (l + r) / 2;
            if(check(dists, mid)) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        
        cout << l << endl;
    }
}

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1; //cin >> t;
    while (t--) solve();
    return 0;
}