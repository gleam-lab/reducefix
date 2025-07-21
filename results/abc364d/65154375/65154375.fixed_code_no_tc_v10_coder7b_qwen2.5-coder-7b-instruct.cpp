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
const int N = 100010;
int ls(int x) { return x << 1; }
int rs(int x) { return x << 1 | 1; }
int f1[8][2] = { 1, 0, 0, 1, -1, 0, 0, -1, 1, 1, 1, -1, -1, 1, -1, -1 };
int f2[8][2] = { 2, 1, 1, 2, -1, 2, -2, 1, -2, -1, -1, -2, 1, -2, 2, -1 };

struct Point{
    int x, k;
}B[N];

vector<int> A[N];

bool cmp(Point a, Point b){
    return abs(a.x - b.x) < abs(b.x - a.x);
}

void build(int u, int l, int r){
    if(l == r){
        A[u].push_back(B[l].x);
        sort(A[u].begin(), A[u].end());
        return ;
    }
    int mid = (l + r) >> 1;
    build(ls(u), l, mid); build(rs(u), mid + 1, r);
}

int query(int u, int L, int R, int l, int r){
    if(L <= l && r <= R){
        auto it = lower_bound(A[u].begin(), A[u].end(), B[L].x);
        return *(it + B[L].k - 1);
    }
    int mid = (l + r) >> 1, ans = INF;
    if(L <= mid) ans = min(ans, query(ls(u), L, R, l, mid));
    if(R > mid) ans = min(ans, query(rs(u), L, R, mid + 1, r));
    return ans;
}

void solve(void) {
    int n, q; cin >> n >> q;
    for(int i = 1; i <= n; i++){
        int x; cin >> x;
        A[1].push_back(x);
    }
    sort(A[1].begin(), A[1].end());
    for(int i = 1; i <= q; i++){
        cin >> B[i].x >> B[i].k;
    }
    sort(B + 1, B + q + 1, cmp);
    build(1, 1, q);
    for(int i = 1; i <= q; i++){
        cout << query(1, i, i, 1, q) - B[i].x << endl;
    }
}

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1; //cin >> t;
    while (t--) solve();
    return 0;
}