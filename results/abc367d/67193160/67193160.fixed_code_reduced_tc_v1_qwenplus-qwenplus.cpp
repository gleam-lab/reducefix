#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;
int n, m;
long long a[N * 2];
map<long long, long long> cnt;
long long sum = 0;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        a[i + n] = a[i];
    }

    // Prefix sums
    for (int i = 1; i < 2 * n; ++i) {
        a[i] = (a[i] + a[i - 1]) % m;
    }

    cnt[0] = 1;
    for (int i = 1; i < 2 * n; ++i) {
        if (i > n) {
            cnt[a[i - n]]--;
        }
        sum += cnt[a[i]];
        cnt[a[i]]++;
    }

    cout << sum << endl;
    return 0;
}