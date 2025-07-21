#include<bits/stdc++.h>
using namespace std;

const int MAXN = 105;
const int INF = 2e9;

int n, x;
int a[MAXN], p[MAXN], b[MAXN], q[MAXN];

bool check(long long mid) {
    long long sum = 0;
    for (int i = 1; i <= n; ++i) {
        long long minn = INF;
        for (int j = 0; j <= b[i]; ++j) {
            long long cost = j * p[i];
            if ((mid - j * a[i]) > 0) {
                cost += (mid - j * a[i]) / b[i] * q[i];
                if ((mid - j * a[i]) % b[i] != 0) {
                    cost += q[i];
                }
            }
            minn = min(minn, cost);
        }
        for (int j = 0; j <= a[i]; ++j) {
            long long cost = j * q[i];
            if ((mid - j * b[i]) > 0) {
                cost += (mid - j * b[i]) / a[i] * p[i];
                if ((mid - j * b[i]) % a[i] != 0) {
                    cost += p[i];
                }
            }
            minn = min(minn, cost);
        }
        sum += minn;
    }
    return sum <= x;
}

int main() {
    cin >> n >> x;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i] >> p[i] >> b[i] >> q[i];
    }

    long long l = 0, r = 1e9;
    while (l < r) {
        long long mid = l + (r - l + 1) / 2;
        if (check(mid)) {
            l = mid;
        } else {
            r = mid - 1;
        }
    }

    cout << l << endl;
    return 0;
}