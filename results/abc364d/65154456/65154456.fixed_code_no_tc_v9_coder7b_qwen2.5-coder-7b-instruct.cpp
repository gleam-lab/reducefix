#include<bits/stdc++.h>
using namespace std;

const int MAXN = 100010;
int n, q;
int a[MAXN], b[MAXN], k[MAXN];
long long dist[MAXN];

bool cmp(int i, int j) {
    return dist[i] < dist[j];
}

void solve() {
    cin >> n >> q;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for(int i = 1; i <= q; i++) {
        cin >> b[i] >> k[i];
    }

    for(int j = 1; j <= q; j++) {
        for(int i = 1; i <= n; i++) {
            dist[i] = abs(a[i] - b[j]);
        }
        sort(dist + 1, dist + n + 1);
        cout << dist[k[j]] << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    solve();
    return 0;
}