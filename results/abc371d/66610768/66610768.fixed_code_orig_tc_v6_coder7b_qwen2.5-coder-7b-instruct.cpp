#include<bits/stdc++.h>
using namespace std;
using LL = __int128;
typedef long long ll;
const int N = 1e6+7;

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n,m;
    cin >> n;
    vector<int> a(n+1,0),b(n+1,0),c(n+1,0);
    for(int i=1;i<=n;i++) cin >> a[i];
    partial_sum(b.begin()+1,b.end(),c.begin()+1);
    cin >> m;
    while(m--) {
        int l,r;
        cin >> l >> r;
        if(l == r) cout << b[r] << '\n';
        else cout << c[r] - c[l-1] << '\n';
    }
    return 0;
}