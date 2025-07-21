#include<bits/stdc++.h>
using namespace std;

int n, m;

int main() {
    cin >> n >> m;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    vector<int> prefixsum(n + 1, 0);
    for (int i = 0; i < n; i++) {
        prefixsum[i + 1] = prefixsum[i] + nums[i];
    }
    int count = 0;

    // å¯»æ¾å¯è½å­å¨ç (s, t) å¯¹
    for (int s = 1; s <= n; s++) {
        for (int t = 1; t <= n; t++) {
            if (s == t) continue; // s å t ä¸è½ç¸å
            int step = 0;
            if (s < t) {
                step = prefixsum[t] - prefixsum[s] + m; // å ä¸ modulo m
            } else if (s > t) {
                step = (prefixsum[n] - prefixsum[s] + prefixsum[t]) % m;
            }

            if (step != 0 && step % m == 0) { // å¦æ step ä¸ä¸º 0 ä¸è½è¢« m æ´é¤
                count++;
            }
        }
    }
    cout << count << endl;
    return 0;
}