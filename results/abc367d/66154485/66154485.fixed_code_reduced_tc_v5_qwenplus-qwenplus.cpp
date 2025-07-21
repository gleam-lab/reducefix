#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<int> arr(n * 2);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
        arr[i + n] = arr[i]; // duplicate for circular handling
    }

    vector<long long> prefix_mod(n * 2 + 1, 0);
    for (int i = 0; i < n * 2; ++i) {
        prefix_mod[i + 1] = (prefix_mod[i] + arr[i]) % m;
    }

    long long ans = 0;
    multiset<long long> ms;
    for (int i = 0; i < n; ++i) {
        ms.insert(prefix_mod[i]);
    }

    for (int i = n; i < 2 * n; ++i) {
        ms.insert(prefix_mod[i]);
        ans += ms.count(prefix_mod[i - n]);
        ms.erase(ms.find(prefix_mod[i - n]));
    }

    cout << ans << endl;
    return 0;
}