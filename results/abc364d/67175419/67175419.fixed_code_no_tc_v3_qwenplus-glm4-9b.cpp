#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n, m;
int a[N], b[N], k[N];

bool check(int x, int y) {
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (abs(a[i] - y) <= x) {
            cnt++;
        }
    }
    return cnt >= k[y];
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> b[i] >> k[i];
        b[i]--;
    }
    sort(b, b + m);

    for (int i = 0; i < m; i++) {
        int l = 0, r = 1e9;
        while (l < r) {
            int mid = (l + r + 1) / 2;
            if (check(mid, b[i])) {
                l = mid;
            } else {
                r = mid - 1;
            }
        }
        cout << r << "\n";
    }
    return 0;
}