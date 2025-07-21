#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Prefix sum modulo m
    vector<int> prefix_mod(n + 1, 0);
    for (int i = 0; i < n; i++) {
        prefix_mod[i + 1] = (prefix_mod[i] + arr[i]) % m;
    }

    // Use a frequency array to count occurrences of each modulo value
    vector<int> freq(m, 0);
    int ans = 0;

    for (int i = 0; i < n; i++) {
        // For circular property, we consider all subarrays ending at index i
        // We manually compute the mod for each possible start point
        int sum = 0;
        for (int j = i; j < i + n; j++) {
            sum = (sum + arr[j % n]) % m;
            if (sum == 0) {
                ans++;
            }
        }
    }

    cout << ans << endl;
    return 0;
}