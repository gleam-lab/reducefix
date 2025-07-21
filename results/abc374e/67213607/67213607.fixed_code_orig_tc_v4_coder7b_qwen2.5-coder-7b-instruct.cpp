#include <bits/stdc++.h>
using namespace std;

const int MAXN = 105;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int n, x;
    cin >> n >> x;

    vector<int> a(n), p(n), b(n), q(n);
    for(int i = 0; i < n; ++i) {
        cin >> a[i] >> p[i] >> b[i] >> q[i];
    }

    long long l = 0, r = 1e9 + 5;
    while(l <= r) {
        long long mid = (l + r) / 2;
        long long sum = 0;

        for(int i = 0; i < n; ++i) {
            long long minn = LLONG_MAX;
            for(int j = 0; j <= b[i]; ++j) {
                long long cost = j * p[i];
                if(mid >= j * a[i])
                    cost += (mid - j * a[i]) / b[i] * q[i];
                else
                    cost += ((mid - j * a[i] + b[i] - 1) / b[i]) * q[i];
                minn = min(minn, cost);
            }
            for(int j = 0; j <= a[i]; ++j) {
                long long cost = j * q[i];
                if(mid >= j * b[i])
                    cost += (mid - j * b[i]) / a[i] * p[i];
                else
                    cost += ((mid - j * b[i] + a[i] - 1) / a[i]) * p[i];
                minn = min(minn, cost);
            }
            sum += minn;
        }

        if(sum <= x) {
            ans = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }

    cout << ans << '\n';

    return 0;
}