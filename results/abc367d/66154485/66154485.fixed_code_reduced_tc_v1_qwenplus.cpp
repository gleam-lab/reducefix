#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    long long ans = 0;
    map<int, int> prefixCount;
    prefixCount[0] = 1;

    for (int i = 0; i < 2 * n; i++) {
        static long long prefixSum = 0;
        prefixSum += arr[i % n];
        int mod = ((prefixSum % m) + m) % m;
        
        ans += prefixCount[mod];
        prefixCount[mod]++;
        
        if (i >= n - 1) {
            int removeMod = ((prefixSum - arr[(i - n + 1) % n]) % m + m) % m;
            prefixCount[removeMod]--;
            if (prefixCount[removeMod] == 0) {
                prefixCount.erase(removeMod);
            }
        }
    }

    cout << ans;
    return 0;
}