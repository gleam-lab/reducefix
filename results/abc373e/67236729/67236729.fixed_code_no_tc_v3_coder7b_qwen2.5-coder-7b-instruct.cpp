#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for(int i = 0; i < n; ++i)

long long calc(long long a, long long b, long long k) {
    return a * (a + 1) / 2 - (a - b) * (a - b + 1) / 2 + k;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    long long k;
    cin >> n >> m >> k;

    vector<long long> a(n), s(n);
    rep(i, n) {
        cin >> a[i];
        s[i] = (i == 0 ? 0 : s[i-1]) + a[i];
    }

    vector<long long> ans(n);
    rep(i, n) {
        long long need = 0;
        long long sum = 0;
        for(int j = 0; j < n; ++j) {
            if(j != i) {
                sum += a[j];
            }
        }
        if(sum + k < (long long)m * a[i]) {
            ans[i] = -1;
            continue;
        }
        need = (long long)m * a[i] - sum - k;
        ans[i] = need;
    }

    rep(i, n) {
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}