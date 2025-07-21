#include <bits/stdc++.h>
using namespace std;

const int N = 2e6 + 5;
int n, m, a[N];
long long prefix_sum = 0, total = 0;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    map<int, int> cnt;
    cnt[0] = 1;

    prefix_sum = 0;
    for (int i = 0; i < 2 * n; ++i) {
        prefix_sum += a[i % n];
        int mod = prefix_sum % m;
        total += cnt[mod]++;
    }

    cout << total << endl;
    return 0;
}