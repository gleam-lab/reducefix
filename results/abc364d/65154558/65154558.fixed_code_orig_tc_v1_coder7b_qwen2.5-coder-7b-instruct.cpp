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
const int MAXN = 2e8 + 5;
int ls(int x) { return x << 1; }
int rs(int x) { return x << 1 | 1; }
int f1[8][2] = { 1, 0, 0, 1, -1, 0, 0, -1, 1, 1, 1, -1, -1, 1, -1, -1 };
int f2[8][2] = { 2, 1, 1, 2, -1, 2, -2, 1, -2, -1, -1, -2, 1, -2, 2, -1 };

vector<int> a;

bool check(int mid, int x, int y){
    auto pos = lower_bound(a.begin(), a.end(), x - mid);
    if(pos == a.end() || *pos > x + mid) return false;
    int cnt = 0;
    for(; pos != a.end(); ++pos){
        if(*pos > x + mid) break;
        if(abs(*pos - x) <= mid && abs(*pos - y) <= mid) cnt++;
    }
    return cnt >= k;
}

void solve(void) {
    int n, q; cin >> n >> q;
    for(int i = 1; i <= n; i++){
        int x; cin >> x;
        a.push_back(x);
    }
    sort(a.begin(), a.end());
    for(int i = 1; i <= q; i++){
        int x, k; cin >> x >> k;
        int l = 0, r = 2e8;
        while(l < r){
            int mid = (l + r) / 2;
            if(check(mid, x, x)) r = mid;
            else l = mid + 1;
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