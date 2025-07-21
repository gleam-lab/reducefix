#include <bits/stdc++.h>
using namespace std;

const int N = 2e6 + 5;
int n, m;
long long a[N];
map<long long, long long> cnt;
long long sum = 0;
long long prefix = 0;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        a[i + n] = a[i];  // Duplicate the array for circular handling
    }

    cnt[0] = 1;  // To count subarrays starting from index 0

    for (int i = 1; i < 2 * n; ++i) {
        prefix = (prefix + a[i]) % m;
        sum += cnt[prefix];
        if (i < n) {
            cnt[prefix]++;
        }
    }

    cout << sum << endl;
    return 0;
}