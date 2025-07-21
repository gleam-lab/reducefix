#include <bits/stdc++.h>
using namespace std;

const int N = 2e6 + 5;
int n, m;
long long a[N];
map<int, int> cnt;
long long sum = 0, prefix = 0;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        a[i + n] = a[i]; // Duplicate array for circular handling
    }

    cnt[0] = 1; // To count subarrays starting from index 0

    for (int i = 1; i < 2 * n; ++i) {
        prefix = (prefix + a[i]) % m;
        sum += cnt[prefix];
        cnt[prefix]++;
        
        // When sliding window moves beyond first n elements, decrement counts from the front
        if (i >= n) {
            cnt[(prefix - a[i - n + 1] + m) % m]--;
        }
    }

    cout << sum << endl;
    return 0;
}