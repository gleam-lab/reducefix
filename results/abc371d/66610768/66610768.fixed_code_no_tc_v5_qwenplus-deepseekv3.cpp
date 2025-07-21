#include<bits/stdc++.h>
using namespace std;
using LL = __int128;
typedef long long ll;
const int N = 1e6+7;

int main() {
    int n, m;
    cin >> n;
    vector<pair<int, int>> ab(n);
    for(int i = 0; i < n; i++) {
        cin >> ab[i].first;
    }
    for(int i = 0; i < n; i++) {
        cin >> ab[i].second;
    }
    sort(ab.begin(), ab.end());
    vector<int> a(n), b(n), c(n+1, 0);
    for(int i = 0; i < n; i++) {
        a[i] = ab[i].first;
        b[i] = ab[i].second;
        c[i+1] = c[i] + b[i];
    }
    cin >> m;
    while(m--) {
        int l, r;
        cin >> l >> r;
        auto l_i = lower_bound(a.begin(), a.end(), l);
        auto r_j = upper_bound(a.begin(), a.end(), r);
        int i = l_i - a.begin();
        int j = r_j - a.begin();
        cout << c[j] - c[i] << endl;
    }
    return 0;
}