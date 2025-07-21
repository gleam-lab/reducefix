#include <bits/stdc++.h>
using namespace std;

const int N = 2e6 + 5;

int n, m;
long long sum;
int a[N];
map<int, int> cnt;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        a[i + n] = a[i]; // Duplicate array for circular handling
    }

    vector<long long> prefix(2 * n + 1, 0);
    for (int i = 0; i < 2 * n; ++i) {
        prefix[i + 1] = prefix[i] + a[i];
    }

    // Use mod m and count prefix sums within sliding window of size n
    cnt[0] = 1;
    for (int i = 1; i <= 2 * n; ++i) {
        int current_mod = (prefix[i] % m + m) % m;
        sum += cnt[current_mod];
        cnt[current_mod]++;
        if (i >= n) {
            int out_of_window_mod = (prefix[i - n] % m + m) % m;
            cnt[out_of_window_mod]--;
        }
    }

    cout << sum << '\n';
    return 0;
}