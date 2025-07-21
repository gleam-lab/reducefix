#include <bits/stdc++.h>
using namespace std;

const int N = 2e6 + 5;

int n, m;
long long a[N];
map<int, int> freq;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        a[i + n] = a[i]; // Duplicate the array for circular handling
    }

    long long total = 0;
    long long prefix = 0;
    freq[0] = 1; // Initialize with zero prefix sum mod m

    for (int i = 1; i < 2 * n; ++i) {
        prefix = (prefix + a[i]) % m;

        // Count how many times this mod has been seen before
        total += freq[prefix];

        // If we're within the first n elements, update frequency
        if (i < n) {
            freq[prefix]++;
        } else {
            // Remove the contribution of the element that slides out of the window
            int remove_prefix = (a[i - n + 1] % m + m) % m;
            prefix = (prefix - a[i - n + 1] + m) % m;
            freq[prefix]--;
            prefix = (prefix + a[i - n + 1]) % m;
        }
    }

    cout << total << endl;
    return 0;
}