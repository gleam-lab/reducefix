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
const int N = 2e5 + 5;
int ls(int x) { return x << 1; }
int rs(int x) { return x << 1 | 1; }
int f1[8][2] = { 1, 0, 0, 1, -1, 0, 0, -1, 1, 1, 1, -1, -1, 1, -1, -1 };
int f2[8][2] = { 2, 1, 1, 2, -1, 2, -2, 1, -2, -1, -1, -2, 1, -2, 2, -1 };

vector<int> a;
vector<pair<int,int>> b;

bool check(int mid, int x, int y){
    return a[min((int)a.size() - 5, x + mid)] - a[max(0, x - mid - 1)] >= y;
}

void solve(void) {
    int n, q; cin >> n >> q;
    a.resize(n + 1);
    b.resize(q);
    
    for(int i = 1; i <= n; i++){
        int x; cin >> x;
        a[i] = x;
    }

    sort(a.begin(), a.end());
    a.push_back(INF); // sentinel value
    
    for(int i = 0; i < q; i++){
        int x, y; cin >> x >> y;
        b[i].first = x;
        b[i].second = y;
    }
    
    for(auto [x, y] : b){
        int l = 0, r = 2e8;
        while(r > l){
            int mid = l + r >> 1;
            if(check(mid, x, y)) r = mid;
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