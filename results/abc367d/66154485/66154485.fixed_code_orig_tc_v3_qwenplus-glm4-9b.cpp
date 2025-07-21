#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m, ans = 0;
    cin >> n >> m;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Using a frequency array to store the frequency of remainders
    vector<int> freq(m, 0);
    freq[0] = 1; // The frequency of 0 remainder is initially 1 (representing the sum of zero elements)

    // Calculate prefix sums
    for (int i = 0; i < n; i++) {
        arr[i] = (arr[i] % m + m) % m; // Make sure the elements are positive modulo m
    }

    long long current_sum = 0;
    for (int i = 0; i < n; i++) {
        current_sum = (current_sum + arr[i]) % m;

        // Increment the count of valid subsequences for the current remainder
        ans += freq[current_sum];

        // Update the frequency array
        freq[current_sum]++;
    }

    cout << ans;
    return 0;
}