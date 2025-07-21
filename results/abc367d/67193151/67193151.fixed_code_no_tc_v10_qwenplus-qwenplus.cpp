#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 1e6 + 5;

int n, m;
ll a[N], prefix[2*N];
map<int, int> cnt;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        a[i + n] = a[i];  // Duplicate array for circular handling
    }

    ll total = 0;
    cnt[0] = 1; // For subarrays starting at index 0

    for (int i = 1; i < 2*n; ++i) {
        prefix[i] = (prefix[i-1] + a[i]) % m;

        // If i > n, remove the count from the corresponding position in first half
        if (i > n) {
            cnt[prefix[i - n] % m]--;
        }

        total += cnt[prefix[i] % m];
        if (i < n) {
            cnt[prefix[i] % m]++;
        }
    }

    cout << total;
    return 0;
}