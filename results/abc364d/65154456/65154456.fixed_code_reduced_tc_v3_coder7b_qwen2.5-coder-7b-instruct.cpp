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
const int N = 2 * 100000000 + 5;
int ls(int x) { return x << 1; }
int rs(int x) { return x << 1 | 1; }

vector<int> a;

bool check(int mid, int x, int y){
    return a[min((int)a.size() - 1, x + mid)] - a[max(0, x - mid - 1)] >= y;
}

void solve(void) {
    int n, q; cin >> n >> q;
    for(int i = 1; i <= n; i++){
        int x; cin >> x;
        a.push_back(abs(x));
    }
    sort(a.begin(), a.end());
    for(int i = 1; i < a.size(); i++){
        a[i] += a[i - 1];
    }
    for(int i = 1; i <= q; i++){
        int x, k; cin >> x >> k;
        int l = 0, r = 2 * 100000000;
        while(r > l){
            int mid = l + r >> 1;
            if(check(mid, abs(x), k)) r = mid;
            else l = mid + 1;
        }
        cout << r << endl;
    }
}

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1; //cin >> t;
    while (t--) solve();
    return 0;
}