#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define int long long
const int N = 105;

int n;
int x;
vector<int> a, p, b, q;

vector<int> c;

bool check(int mid) {
    fill(c.begin(), c.end(), INT_MAX);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= b[i]; j++) {
            c[i] = min(c[i], j * p[i] + q[i] * (mid - j * a[i]) / a[i]);
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= b[i]; j++) {
            c[i] = min(c[i], j * q[i] + p[i] * (mid - j * b[i]) / b[i]);
        }
    }
    return accumulate(c.begin(), c.end(), 0LL) <= x;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    a.resize(n);
    p.resize(n);
    b.resize(n);
    q.resize(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i] >> p[i] >> b[i] >> q[i];
    }
    cin >> x;

    int l = 1, r = n;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (check(mid)) {
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }

    cout << r << endl;
    return 0;
}