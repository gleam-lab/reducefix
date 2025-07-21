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

int a[N];

bool check(int mid, int x, int y){
    return a[min(N - 1, x + mid)] - a[max(0, x - mid - 1)] >= y;
}

void solve(void) {
    int n, q; cin >> n >> q;
    set<int> s;
    for(int i = 1; i <= n; i++) {
        int x; cin >> x;
        s.insert(x);
    }

    for(int i = 1; i <= q; i++) {
        int x, k; cin >> x >> k;
        auto it = s.lower_bound(x);
        vector<int> dists;
        int cnt = 0;
        
        while(it != end(s)) {
            int d = abs(*it - x);
            dists.push_back(d);
            ++cnt;
            if(cnt == k) break;
            ++it;
        }

        if(k > cnt) {
            cout << "0" << endl;
            continue;
        }

        sort(begin(dists), end(dists));
        cout << dists[k - 1] << endl;
    }
}

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1; //cin >> t;
    while (t--) solve();
    return 0;
}