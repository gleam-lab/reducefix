#include <bits/stdc++.h>
using namespace std;

const int N = 2e6 + 5;
int n, m;
long long a[N];
map<long long, long long> cnt;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        a[i + n] = a[i];  // Duplicate array for circular handling
    }

    long long sum = 0;
    long long prefix = 0;
    cnt[0] = 1;  // Initialize with mod 0 having count 1

    for (int i = 1; i < 2 * n; ++i) {
        prefix = (prefix + a[i]) % m;
        sum += cnt[prefix];
        if (i < n) {
            cnt[prefix]++;
        } else {
            // Remove the element that's sliding out of the window
            long long to_remove = (prefix - a[i - n + 1] + m) % m;
            cnt[to_remove]--;
            if (cnt[to_remove] == 0) {
                cnt.erase(to_remove);
            }
        }
    }

    cout << sum << endl;
    return 0;
}