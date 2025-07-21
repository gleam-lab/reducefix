#include <bits/stdc++.h>
using namespace std;

const int N = 2e6 + 5;
int n, m, a[N];
long long prefix_sum[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    map<int, int> cnt;
    long long res = 0;
    cnt[0] = 1;

    // First pass with original array
    long long sum = 0;
    for (int i = 1; i <= n; ++i) {
        sum += a[i];
        int mod = ((sum % m) + m) % m;
        res += cnt[mod];
        cnt[mod]++;
    }

    // Second pass with doubled array for circular property
    for (int i = 1; i <= n; ++i) {
        sum += a[i];
        int mod = ((sum % m) + m) % m;
        res += cnt[mod];
        cnt[mod]++;
    }

    cout << res << endl;
    return 0;
}