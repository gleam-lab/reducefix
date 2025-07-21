#include<bits/stdc++.h>
#define endl "\n"
using namespace std;

typedef long long ll;

const int N = 4e5 + 10;
int a[N];

bool check(int mid, int x, int y) {
    int l = max(0, x - mid - 1);
    int r = min(N - 5, x + mid);
    if (l == 0) {
        return a[r] - a[0] >= y;
    }
    return a[r] - a[l] >= y;
}

void solve() {
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        a[x + (N - 5) / 2]++;
    }
    for (int i = 1; i <= N - 5; i++) {
        a[i] += a[i - 1];
    }
    for (int j = 1; j <= q; j++) {
        int x, k;
        cin >> x >> k;
        int l = 0, r = 1e8;
        while (r - l > 1) {
            int mid = (l + r) / 2;
            if (check(mid, x + (N - 5) / 2, k)) {
                l = mid;
            } else {
                r = mid;
            }
        }
        cout << l << endl;
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    solve();
    return 0;
}