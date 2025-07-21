#include<bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;
int n, m, a[N * 2], prefix[N * 2], cnt[N];

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        a[i + n] = a[i];
    }

    prefix[0] = 0;
    for (int i = 1; i <= 2 * n; ++i) {
        prefix[i] = (prefix[i - 1] + a[i]) % m;
    }

    long long res = 0;
    cnt[0] = 1;
    for (int i = 1; i <= 2 * n; ++i) {
        if (i > n) {
            cnt[prefix[i - n]]--;
        }
        res += cnt[prefix[i]];
        if (i < n) {
            cnt[prefix[i]]++;
        } else {
            cnt[prefix[i]]++;
        }
    }

    cout << res << endl;
    return 0;
}