#include <bits/stdc++.h>
using namespace std;

const int MAXN = 400005;
const int MAXM = 1000005;

int n, m, a[MAXN], t[MAXM];
long long an, w[MAXN];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        a[i] %= m;
        a[i + n] = a[i];
    }

    // Prefix sums modulo m
    map<int, long long> cnt;
    cnt[0] = 1;  // For the empty prefix

    long long current_sum = 0;
    for (int i = 1; i < 2 * n; ++i) {
        current_sum = (current_sum + a[i]) % m;
        an += cnt[current_sum];
        cnt[current_sum]++;
    }

    cout << an << endl;
    return 0;
}