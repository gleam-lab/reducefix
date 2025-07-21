#include<bits/stdc++.h>
using namespace std;
using LL = __int128;
typedef long long ll;
const int N = 1e6+7;
int n, m;
vector<int> a(N+1), b(N+1), c(N+1);

int main() {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for(int i = 1; i <= n; i++) {
        cin >> b[i];
        c[i] = b[i] + c[i-1];
    }
    cin >> m;
    while(m--) {
        int l, r;
        cin >> l >> r;
        auto l_i = lower_bound(a.begin(), a.end(), l);
        auto r_j = upper_bound(a.begin(), a.end(), r);
        int i = l_i - a.begin();
        int j = r_j - a.begin();
        if(r >= a[n]) {
            cout << c[n] - c[i] << endl;
        } else {
            cout << c[j-1] - c[i] << endl;
        }
    }
    return 0;
}