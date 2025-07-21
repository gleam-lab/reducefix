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
const int MAXN = 2e5 + 5;
int a[MAXN], cnt[MAXN * 2];

bool check(int mid, int x, int y) {
    return cnt[x + mid] - cnt[max(0, x - mid - 1)] >= y;
}

void solve(void) {
    int n, q; cin >> n >> q;
    vector<int> pos(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        pos[i] = i;
    }
    sort(pos.begin(), pos.end(), [&](int i, int j){ return a[i] < a[j]; });
    
    for(int i = 0; i < n; i++) {
        int p = pos[i];
        cnt[p + 1]++;
    }

    for(int i = 1; i <= n; i++) {
        cnt[i] += cnt[i - 1];
    }

    for(int i = 0; i < q; i++) {
        int x, k; cin >> x >> k;
        int l = 0, r = n;
        while(l < r) {
            int mid = (l + r) / 2;
            if(check(mid, x, k)) r = mid;
            else l = mid + 1;
        }
        cout << a[pos[l]] - x << endl;
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1; //cin >> t;
    while(t--) solve();
    return 0;
}