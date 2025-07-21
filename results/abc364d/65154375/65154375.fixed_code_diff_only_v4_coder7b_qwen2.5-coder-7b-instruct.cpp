#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
typedef long long ll;

const int INF = 0x3f3f3f3f;
const int N = 1e5 + 5;

vector<int> a[N], b[N];

void preprocess() {
    for(int i = 1; i <= N; i++) {
        sort(a[i].begin(), a[i].end());
    }
}

void solve(void) {
    int n, q; cin >> n >> q;
    for(int i = 1; i <= n; i++){
        int x, k; cin >> x >> k;
        a[k].push_back(x);
    }
    preprocess();

    for(int i = 1; i <= q; i++){
        int k, j; cin >> k >> j;
        cout << a[j][k - 1] - b[j][k - 1] << endl;
    }
}

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1; //cin >> t;
    while (t--) solve();
    return 0;
}