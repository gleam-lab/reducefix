#include <iostream>
#include <limits>
using namespace std;
#define int long long
const int N = 105;

int n;
int x;
int a[N], b[N], p[N], q[N];

int c[N];
bool check(int mid) {
    for (int i = 1; i <= n; i++) {
        c[i] = numeric_limits<int>::max();
        for (int j = 0; j <= b[i]; j++) {
            int val1 = j * p[i] + (mid - j * a[i]) / b[i] * q[i];
            int val2 = j * q[i] + (mid - j * b[i]) / a[i] * p[i];
            c[i] = min(c[i], val1);
            c[i] = min(c[i], val2);
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        ans += c[i];
    }
    return ans <= x;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i] >> p[i] >> b[i] >> q[i];
    }
    int l = 1, r = n;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (check(mid)) {
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    cout << l;
    return 0;
}