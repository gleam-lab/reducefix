#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int n, m, k, sum, cnt, a[N], b[N], d[N];

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr); 
    cin >> n >> m;

    // Initialize the array b with 0s
    memset(b, 0, sizeof(b));

    // Read array a and extend it by repeating it
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i+n] = a[i];
    }

    // Initialize b[0] to 1 as we have one whole array
    b[0] = 1;

    // Process the array
    for (int i = 1; i < n*2; i++) {
        // Decrement the frequency of the current value if i >= n
        if (i >= n) {
            b[d[i-n] % m]--;
        }

        // Append the value of a[i] to the cumulative sum
        d[i] = d[i-1] + a[i];

        // Add the frequency of the current value's remainder to the sum
        sum += b[d[i] % m];

        // If i is not in the first half of the extended array, increment the frequency
        if (i < n) {
            b[d[i] % m]++;
        }
    }

    cout << sum << '\n';
    return 0;
}