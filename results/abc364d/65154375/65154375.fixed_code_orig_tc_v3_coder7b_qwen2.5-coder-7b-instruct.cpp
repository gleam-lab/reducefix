#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
typedef long long ll;

const int N = 1e5 + 5;
int a[N], b[N], c[N];

bool cmp(int x, int y) {
    return a[x] < a[y];
}

int main() {
    int n, q;
    cin >> n >> q;
    for(int i = 1; i <= n; ++i) cin >> a[i];
    for(int i = 1; i <= q; ++i) cin >> b[i] >> c[i];
    
    vector<int> v(n);
    iota(v.begin(), v.end(), 1);
    sort(v.begin(), v.end(), cmp);

    for(int i = 1; i <= q; ++i) {
        int pos = upper_bound(v.begin(), v.end(), b[i]) - v.begin();
        if(pos == 0 || abs(a[v[pos]] - b[i]) < abs(a[v[pos - 1]] - b[i])) cout << abs(a[v[pos]] - b[i]) << '\n';
        else cout << abs(a[v[pos - 1]] - b[i]) << '\n';
    }

    return 0;
}