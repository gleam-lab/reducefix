#include <bits/stdc++.h>
using namespace std;

const int N = 2e6 + 5;
int n, m;
long long a[N];
map<int, int> cnt;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        a[i + n] = a[i];
    }

    long long res = 0;
    long long prefix = 0;
    cnt[0] = 1;

    for (int i = 1; i < 2 * n; ++i) {
        prefix = (prefix + a[i]) % m;
        res += cnt[prefix]++;
        if (i >= n) {
            cnt[(prefix - a[i - n + 1] + m) % m]--;
        }
    }

    cout << res << "\n";
    return 0;
}