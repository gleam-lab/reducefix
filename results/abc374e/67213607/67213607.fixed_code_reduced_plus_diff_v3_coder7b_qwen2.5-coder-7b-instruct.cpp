#include<bits/stdc++.h>
using namespace std;

bool check(long long mid, int n, vector<int>& a, vector<int>& p, vector<int>& b, vector<int>& q, int x) {
    long long sum = 0;
    for(int i = 0; i < n; ++i) {
        long long minn = LLONG_MAX;
        for(int j = 0; j <= b[i]; ++j) {
            if((mid - j * a[i]) >= 0) {
                minn = min(minn, 1LL * j * p[i] + (mid - j * a[i]) / b[i] * q[i]);
            }
        }
        for(int j = 0; j <= a[i]; ++j) {
            if((mid - j * b[i]) >= 0) {
                minn = min(minn, 1LL * j * q[i] + (mid - j * b[i]) / a[i] * p[i]);
            }
        }
        sum += minn;
    }
    return sum <= x;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n, x;
    cin >> n >> x;
    
    vector<int> a(n), p(n), b(n), q(n);
    for(int i = 0; i < n; ++i) {
        cin >> a[i] >> p[i] >> b[i] >> q[i];
    }

    long long l = 0, r = 1e9;
    while(l < r) {
        long long mid = (l + r + 1) / 2;
        if(check(mid, n, a, p, b, q, x)) {
            l = mid;
        } else {
            r = mid - 1;
        }
    }

    cout << l << endl;

    return 0;
}