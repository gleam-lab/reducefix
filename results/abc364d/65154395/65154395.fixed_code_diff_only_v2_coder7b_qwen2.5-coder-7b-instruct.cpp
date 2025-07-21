#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 1e5 + 5;
int a[MAXN], b[MAXN], c[MAXN];
int n, q, k;

bool cmp(int i, int j) {
    return abs(a[i] - b[k]) < abs(a[j] - b[k]);
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin >> n >> q;
    for(int i = 0; i < n; ++i) cin >> a[i];
    for(int i = 0; i < q; ++i) cin >> b[i] >> k;

    sort(a, a+n);

    for(int i = 0; i < q; ++i) {
        c[i] = lower_bound(a, a+n, b[i]) - a;
        nth_element(c, c+k-1, c+q, cmp);
        cout << abs(a[c[k-1]] - b[i]) << '\n';
    }

    return 0;
}