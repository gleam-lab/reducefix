#include<bits/stdc++.h>
using namespace std;

const int MAXN = 400005;
long long a[MAXN], t[MAXN * 2];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; ++i) {
        cin >> a[i];
        a[i] %= m;
        a[i + n] = a[i];
    }

    long long ans = 0;
    for(int i = 1; i < 2 * n; ++i) {
        t[a[i]]++;
        if(i > n) {
            t[a[i - n]]--;
        }
        if(i >= n) {
            ans += t[a[i]];
        }
    }

    cout << ans << '\n';
    return 0;
}