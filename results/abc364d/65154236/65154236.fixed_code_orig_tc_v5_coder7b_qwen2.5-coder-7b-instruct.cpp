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
//const ll mod = 998244353;
const int N = 2e8 + 5;
int ls(int x) { return x << 1; }
int rs(int x) { return x << 1 | 1; }
int f1[8][2] = { 1, 0, 0, 1, -1, 0, 0, -1, 1, 1, 1, -1, -1, 1, -1, -1 };
int f2[8][2] = { 2, 1, 1, 2, -1, 2, -2, 1, -2, -1, -1, -2, 1, -2, 2, -1 };

vector<int> a, b, ans;

struct Node {
    int l, r;
    int sum;
} tree[4 * N];

inline void pushup(int p) {
    tree[p].sum = tree[ls(p)].sum + tree[rs(p)].sum;
}

inline void build(int p, int l, int r) {
    tree[p].l = l, tree[p].r = r;
    if(l == r) {
        tree[p].sum = a[l];
        return ;
    }
    int mid = l + r >> 1;
    build(ls(p), l, mid);
    build(rs(p), mid + 1, r);
    pushup(p);
}

inline void update(int p, int pos, int val) {
    if(tree[p].l == tree[p].r) {
        tree[p].sum = val;
        return ;
    }
    int mid = tree[p].l + tree[p].r >> 1;
    if(pos <= mid) update(ls(p), pos, val);
    else update(rs(p), pos, val);
    pushup(p);
}

inline int query(int p, int L, int R) {
    if(L <= tree[p].l && R >= tree[p].r) return tree[p].sum;
    int mid = tree[p].l + tree[p].r >> 1, ret = 0;
    if(L <= mid) ret += query(ls(p), L, R);
    if(R > mid) ret += query(rs(p), L, R);
    return ret;
}

void solve(void) {
    int n, q; cin >> n >> q;
    a.resize(n + 1); b.resize(q + 1); ans.resize(q + 1);
    for(int i = 1; i <= n; i++) cin >> a[i];
    sort(a.begin() + 1, a.end());
    for(int i = 1; i <= q; i++) cin >> b[i] >> ans[i];
    build(1, 1, n);
    for(int i = 1; i <= q; i++) {
        int l = 1, r = n, res = 0;
        while(l <= r) {
            int mid = l + r >> 1;
            int cnt = query(1, 1, mid);
            if(cnt < ans[i]) l = mid + 1;
            else r = mid - 1, res = mid;
        }
        ans[i] = abs(b[i] - a[res]);
    }
    for(int i = 1; i <= q; i++) cout << ans[i] << endl;
}

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1; //cin >> t;
    while (t--) solve();
    return 0;
}