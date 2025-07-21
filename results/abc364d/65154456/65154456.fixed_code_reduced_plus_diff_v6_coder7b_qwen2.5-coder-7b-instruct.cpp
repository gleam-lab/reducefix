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
int ls(int x) { return x << 1; }
int rs(int x) { return x << 1 | 1; }

struct Node{
    int L, R, sum;
}tr[N * 4];

void pushup(int u){
    tr[u].sum = tr[ls(u)].sum + tr[rs(u)].sum;
}

void build(int u, int l, int r){
    tr[u] = {l, r, 0};
    if(l == r){
        return ;
    }
    int mid = l + r >> 1;
    build(ls(u), l, mid);
    build(rs(u), mid + 1, r);
    pushup(u);
}

void modify(int u, int pos, int val){
    if(tr[u].L == tr[u].R){
        tr[u].sum = val;
        return ;
    }
    int mid = tr[u].L + tr[u].R >> 1;
    if(pos <= mid) modify(ls(u), pos, val);
    else modify(rs(u), pos, val);
    pushup(u);
}

int query(int u, int l, int r){
    if(l <= tr[u].L && r >= tr[u].R){
        return tr[u].sum;
    }
    int ans = 0;
    int mid = tr[u].L + tr[u].R >> 1;
    if(l <= mid) ans += query(ls(u), l, r);
    if(r > mid) ans += query(rs(u), l, r);
    return ans;
}

int a[N], b[N];

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, q; cin >> n >> q;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        modify(1, a[i] + 100000000, 1);
    }
    build(1, 1, 200000000);
    for(int i = 1; i <= q; i++){
        cin >> b[i] >> a[i];
        int l = 0, r = 200000000;
        while(r > l){
            int mid = l + r >> 1;
            if(query(1, 1, mid) >= a[i]) r = mid;
            else l = mid + 1;
        }
        cout << r << endl;
    }
    return 0;
}