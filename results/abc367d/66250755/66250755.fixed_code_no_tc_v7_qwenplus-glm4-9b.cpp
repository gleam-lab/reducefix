#include<bits/stdc++.h>
using namespace std;
int n, m, a[400005], t[1000005], an, w[400005];

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i] %= m;
        a[i + n] = a[i];
    }

    // Initialize the first window and the prefix sum array
    w[1] = a[1];
    t[w[1]]++;
    an = 1; // There is one number that is equal to the first number

    // Iterate over the array to calculate the number of valid sequences
    for (int i = 2; i <= 2 * n; i++) {
        w[i] = (w[i - 1] + a[i]) % m;
        t[w[i]]++;

        // Check if the current prefix sum has been seen before
        if (i >= n) { // Only consider windows of length at least n
            an += t[w[i]];
        }

        if (i > n) { // Only decrement for windows of length > n
            t[w[i - n]]--;
        }
    }

    cout << an;
    return 0;
}