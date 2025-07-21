#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    vector<long long> prefix(2 * n + 1, 0);
    for (int i = 0; i < 2 * n; i++) {
        prefix[i + 1] = prefix[i] + arr[i % n];
    }

    unordered_map<int, int> modCount;
    modCount[0] = 1;
    long long ans = 0;

    for (int i = 1; i <= 2 * n; i++) {
        int mod = (prefix[i] % m + m) % m;
        if (i > n) {
            int prevMod = (prefix[i - n] % m + m) % m;
            modCount[prevMod]--;
        }
        ans += modCount[mod];
        modCount[mod]++;
    }

    cout << ans << endl;
    return 0;
}