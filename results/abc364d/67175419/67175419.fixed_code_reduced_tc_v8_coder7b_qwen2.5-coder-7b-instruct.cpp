#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 5;
int n, q;
vector<int> a[MAXN], b[MAXN];

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    cin >> n >> q;

    for(int i = 1; i <= n; ++i) {
        cin >> a[i][0];
    }

    for(int i = 1; i <= q; ++i) {
        cin >> b[i][0] >> b[i][1];
    }

    sort(a[1].begin(), a[1].end());
    sort(b[1].begin(), b[1].end());

    for(int i = 1; i <= q; ++i) {
        int pos = lower_bound(a[1].begin(), a[1].end(), b[i][0]) - a[1].begin();
        cout << abs(a[1][pos] - b[i][0]) << '\n';
    }

    return 0;
}