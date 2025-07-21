#include<bits/stdc++.h>
using namespace std;
int n, m, a[400005], t[1000005], an = 0, w[400005];

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i] = a[i] % m;
        a[i + n] = a[i];
    }
    for (int i = 1; i <= 2 * n; i++) {
        w[a[i]] = 1; // Mark as visited
        an = (an + t[a[i]]) % m; // Update the sum of unique elements
        t[a[i]]++; // Increment the count of the current element
    }
    cout << an;
    return 0;
}