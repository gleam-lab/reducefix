#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
typedef long long ll;

const int INF = 0x3f3f3f3f;
const int MAXN = 200005;

int a[MAXN], b[MAXN], c[MAXN];
vector<int> dists;

bool check(int mid, int k) {
    auto it = lower_bound(dists.begin(), dists.end(), mid);
    return it != dists.end() && it - dists.begin() + 1 >= k;
}

void solve(void) {
    int n, q; cin >> n >> q;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= q; i++) cin >> b[i] >> c[i];
    
    // Combine all points into one array and sort them
    for(int i = 1; i <= n; i++) c[n + i] = a[i];
    sort(c + 1, c + 2 * n + 1);
    
    // Calculate distances and store them in a vector
    for(int i = 1; i <= q; i++) {
        for(int j = 1; j <= n; j++) {
            dists.push_back(abs(b[i] - c[j]));
        }
        sort(dists.begin(), dists.end());
        
        // Binary search to find the k-th smallest distance
        int l = 0, r = 2e8;
        while(l < r) {
            int m = (l + r) >> 1;
            if(check(m, c[i])) r = m;
            else l = m + 1;
        }
        cout << l << endl;
        
        // Clear the distances for the next query
        dists.clear();
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t = 1; // cin >> t;
    while(t--) solve();
    return 0;
}