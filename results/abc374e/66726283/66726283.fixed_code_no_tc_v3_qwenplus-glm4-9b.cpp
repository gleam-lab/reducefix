#include <iostream>
using namespace std;
#define int long long
const int N = 105;
int n;
int x;
int a[N], b[N], p[N], q[N];

int c[N];
bool check(int mid) {
    for (int i = 1; i <= n; ++i) {
        c[i] = numeric_limits<int>::max();
        for (int j = 0; j <= b[i]; ++j) {
            c[i] = min(c[i], j * p[i] + (mid - j * a[i]) * q[i] / b[i]);
        }
        for (int j = 0; j <= a[i]; ++j) {
            c[i] = min(c[i], j * q[i] + (mid - j * b[i]) * p[i] / a[i]);
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        ans += c[i];
    }
    return ans <= x;
}

int main() {
    cin.tie(0);
    cout.tie(0);
    cin >> n >> x;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i] >> p[i] >> b[i] >> q[i];
    }
    int l = 1, r = n;
    while (l < r) {
        int mid = (l + r + 1) / 2;
        if (check(mid)) {
            l = mid;
        } else {
            r = mid - 1;
        }
    }
    cout << l;
    return 0;
}