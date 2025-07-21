#include<bits/stdc++.h>
#include<array>
#define endl "\n"
#define lowbit(x) (x & (-x))
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef double db;

const int INF = 0x3f3f3f3f;
const db eps = 1e-9;
const ll mod = 1e9 + 7;
const int N = 2e8 + 5;
int ls(int x) { return x << 1; }
int rs(int x) { return x << 1 | 1; }
int f1[8][2] = { 1, 0, 0, 1, -1, 0, 0, -1, 1, 1, 1, -1, -1, 1, -1, -1 };
int f2[8][2] = { 2, 1, 1, 2, -1, 2, -2, 1, -2, -1, -1, -2, 1, -2, 2, -1 };

int a[N];

bool check(int mid, int x, int y){
    return a[min(N - 1, x + mid)] - a[max(0, x - mid - 1)] >= y;
}

void solve(void) {
    int n, q; cin >> n >> q;
    vector<int> points(n);
    for(int i = 0; i < n; i++) {
        cin >> points[i];
    }
    sort(points.begin(), points.end());
    for(int i = 1; i <= q; i++){
        int x, y; cin >> x >> y;
        auto it = lower_bound(points.begin(), points.end(), x);
        int idx = it - points.begin() + 1;
        int left = idx - 1, right = n - idx;
        if(k == 1 && left == 0) {
            cout << abs(points[0] - x) << endl;
            continue;
        }
        if(k == n && right == 0) {
            cout << abs(points.back() - x) << endl;
            continue;
        }
        int ans = min(abs(points[idx - 1] - x), abs(points[idx] - x));
        cout << ans << endl;
    }
}

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1; //cin >> t;
    while (t--) solve();
    return 0;
}