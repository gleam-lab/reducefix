#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0;i<n;++i)

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<long long> h(n);
    rep(i,n) cin >> h[i];

    long long ans = 0;
    for(auto &x:h){
        ans += x/3 + (x%3 != 0);
    }

    cout << ans << '\n';
    return 0;
}