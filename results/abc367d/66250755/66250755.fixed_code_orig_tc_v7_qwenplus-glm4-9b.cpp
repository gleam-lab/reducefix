#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    int a[2 * n + 1];  // Extend the array size to accommodate the repetitions
    int w[2 * n + 2], t[2 * n + 1];
    int an = 0;

    // Read input and apply modulo
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i] %= m;
    }

    // Initialize the w array
    for (int i = 1; i <= 2 * n; i++) {
        t[a[i]] = 0;
    }

    // Calculate the sum of counts in the window
    for (int i = 1; i <= 2 * n; i++) {
        if (i > n) {
            t[a[i - n]]--;
            w[i + 1] = (w[i] + t[a[i - n]]) % m;
            if (t[a[i - n]] == m - 1) {  // If count reaches 0, adjust w[i]
                w[i] -= m;
            }
        } else {
            w[i + 1] = t[a[i]];
        }

        if (i >= n) {
            an = (an + w[i + 1]) % m;
        }

        t[a[i]]++;
    }

    cout << an;
    return 0;
}