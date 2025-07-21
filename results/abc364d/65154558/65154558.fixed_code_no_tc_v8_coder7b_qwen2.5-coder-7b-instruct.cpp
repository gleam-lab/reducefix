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

struct Point{
    int id, dist;
};

bool cmp(Point p1, Point p2){
    return p1.dist < p2.dist;
}

vector<Point> A;

void solve(void) {
    int n, q; cin >> n >> q;
    for(int i = 1; i <= n; i++){
        int x; cin >> x;
        A.push_back({i, abs(x)});
    }
    sort(A.begin(), A.end(), cmp);
    vector<int> ans(q);
    for(int i = 0; i < q; i++){
        int x, y; cin >> x >> y;
        ans[i] = A[y - 1].dist;
    }
    for(int i = 0; i < q; i++){
        cout << ans[i] << endl;
    }
}

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1; //cin >> t;
    while (t--) solve();
    return 0;
}