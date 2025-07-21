#include <bits/stdc++.h>

using namespace std;

// Function to find the minimum box size required
long long minBoxSize(vector<long long>& a, vector<long long>& b) {
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    int n = a.size();
    int m = b.size();
    int j = 0;

    // Iterate through each toy size
    for (int i = 0; i < n; ++i) {
        // Find the smallest box that can hold the current toy
        while (j < m && b[j] < a[i]) {
            ++j;
        }

        // If no suitable box found, return -1
        if (j == m) {
            return -1;
        }

        // Move to the next box for the next toy
        ++j;
    }

    // Return the size of the last used box
    return b[m - 1];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<long long> a(n), b(n - 1);

    // Read toy sizes
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    // Read box sizes
    for (int i = 0; i < n - 1; ++i) {
        cin >> b[i];
    }

    // Calculate and print the result
    cout << minBoxSize(a, b) << '\n';

    return 0;
}