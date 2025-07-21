#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 1e5 + 5;
vector<int> a(N);

void solve() {
    int n, q; cin >> n >> q;
    for(int i = 0; i < n; i++) {
        int x; cin >> x;
        a[x]++;
    }
    partial_sum(a.begin(), a.end(), a.begin());
    for(int i = 0; i < q; i++) {
        int x, k; cin >> x >> k;
        int pos = lower_bound(a.begin(), a.end(), k) - a.begin();
        if(pos == 0 && k != a[0]) pos++;
        cout << abs(x - pos) << endl;
    }
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t = 1; //cin >> t;
    while(t--) solve();
    return 0;
}