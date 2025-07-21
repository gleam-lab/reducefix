#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 1e6 + 7;

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n, m;
    cin >> n;
    vector<ll> a(n + 1, 0), b(n + 1, 0), c(n + 1, 0);
    
    for(int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    
    for(int i = 1; i <= n; ++i) {
        cin >> b[i];
        c[i] = b[i] + c[i - 1];
    }
    
    cin >> m;
    while(m--) {
        int l, r;
        cin >> l >> r;
        
        if(l > r || l < 1 || r > n) {
            cout << "Invalid range" << '\n';
            continue;
        }

        if(r >= a[n]) {
            cout << c[n] - c[l - 1] << '\n';
        } else {
            cout << c[r] - c[l - 1] << '\n';
        }
    }
    
    return 0;
}