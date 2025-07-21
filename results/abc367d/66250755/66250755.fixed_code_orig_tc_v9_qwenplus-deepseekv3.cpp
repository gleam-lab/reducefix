#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i] %= m;
    }

    unordered_map<int, int> mod_count;
    mod_count[0] = 1;  // To account for prefix sums that are 0 mod m
    long long prefix = 0;
    long long result = 0;

    for (int i = 1; i <= n; i++) {
        prefix = (prefix + a[i]) % m;
        if (prefix < 0) prefix += m;  // Ensure it's positive
        result += mod_count[prefix];
        mod_count[prefix]++;
    }

    cout << result << '\n';
    return 0;
}