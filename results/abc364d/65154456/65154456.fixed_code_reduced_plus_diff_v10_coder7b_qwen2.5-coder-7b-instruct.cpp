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
const int N = 1e5 + 5;
int ls(int x) { return x << 1; }
int rs(int x) { return x << 1 | 1; }

vector<int> arr[N];

void solve(void) {
    int n, q; cin >> n >> q;
    for(int i = 1; i <= n; i++){
        int x; cin >> x;
        arr[x].push_back(i);
    }
    for(int i = 1; i < N; i++){
        sort(arr[i].begin(), arr[i].end());
    }
    for(int i = 1; i <= q; i++){
        int x, k; cin >> x >> k;
        if(k > arr[x].size()){
            cout << "0" << endl;
        }else{
            cout << abs(x - arr[x][k - 1]) << endl;
        }
    }
}

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1; //cin >> t;
    while (t--) solve();
    return 0;
}