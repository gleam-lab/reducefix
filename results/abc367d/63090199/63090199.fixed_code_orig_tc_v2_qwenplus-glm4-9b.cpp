#include<bits/stdc++.h>
using namespace std;
int n, m;
int main() {
    cin >> n >> m;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    vector<int> prefixsum(n+1, 0);
    for (int i = 0; i < n; i++) { // æ± prefixsum
        prefixsum[i + 1] = prefixsum[i] + nums[i];
    }
    int count = 0;
    // å¯»æ¾æå¯è½ç (s, t) å¯¹
    for (int s = 1; s <= n; s++) {
        for (int t = s + 1; t <= n; t++) { // ç¡®ä¿ s < t
            if (s == t) continue;
            int step = 0;
            if (s < t) {
                step = prefixsum[t] - prefixsum[s];
            } else {
                step = prefixsum[n] - prefixsum[t] + prefixsum[s];
            }
            if (step % m == 0) {
                count++;
            }
        }
    }
    cout << count << endl;
    return 0;
}