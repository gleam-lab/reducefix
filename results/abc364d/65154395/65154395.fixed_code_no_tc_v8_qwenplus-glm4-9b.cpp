#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int a[N], cnt[N];

bool check(int mid, int x, int y) {
    int start = max(0, x - mid);
    int end = min(N - 1, x + mid);
    return cnt[end] - (start ? cnt[start - 1] : 0) >= y;
}

void solve() {
    int n, q;
    cin >> n >> q;
    memset(cnt, 0, sizeof(cnt));

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        cnt[x] += 1;
    }

    for (int j = 0; j < q; j++) {
        int x, y;
        cin >> x >> y;
        int l = 0, r = N;
        while (r - l > 1) {
            int mid = (l + r) / 2;
            if (check(mid, x, y)) {
                r = mid;
            } else {
                l = mid;
            }
        }
        cout << r << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}