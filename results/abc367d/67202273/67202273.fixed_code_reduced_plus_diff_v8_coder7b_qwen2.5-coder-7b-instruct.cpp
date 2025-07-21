#include <bits/stdc++.h>
using namespace std;

const int MAXN = 4e5 + 10;
long long a[MAXN], sum[MAXN], cnt[MAXN];

int main() {
    long long n, m, ans = 0;
    cin >> n >> m;
    for (long long i = 1; i <= n; i++) {
        cin >> a[i];
        a[i + n] = a[i];
    }
    for (long long i = 1; i <= 2 * n; i++) {
        sum[i + 1] = (sum[i] + a[i]) % m;
        if (i <= n) cnt[sum[i]]++;
    }
    for (long long i = n + 1; i <= 2 * n; i++) {
        cnt[sum[i - n]]--;
        ans += cnt[sum[i]];
        cnt[sum[i]]++;
    }
    cout << ans << endl;
    return 0;
}