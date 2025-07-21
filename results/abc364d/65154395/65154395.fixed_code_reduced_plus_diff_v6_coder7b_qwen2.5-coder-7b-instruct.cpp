#include<bits/stdc++.h>
#include<algorithm>
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

vector<int> arr;
vector<int> ans;

bool cmp(int a, int b){
    return arr[a] < arr[b];
}

void solve(void) {
    int n, q; cin >> n >> q;
    for(int i = 1; i <= n; i++){
        int x; cin >> x;
        arr.push_back(x);
    }
    
    sort(arr.begin(), arr.end());
    
    for(int i = 1; i <= q; i++){
        int x, y; cin >> x >> y;
        vector<int> indices(n);
        iota(indices.begin(), indices.end(), 0);
        sort(indices.begin(), indices.end(), [&](int a, int b){return abs(x - arr[a]) < abs(x - arr[b]);});
        ans.push_back(abs(x - arr[indices[k - 1]]));
    }
    
    for(auto it : ans){
        cout << it << endl;
    }
}

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1; //cin >> t;
    while (t--) solve();
    return 0;
}