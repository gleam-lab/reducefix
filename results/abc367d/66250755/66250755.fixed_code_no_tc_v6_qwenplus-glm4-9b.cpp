#include<bits/stdc++.h>
using namespace std;
int n, m, a[400005], t[1000005], w[400005];

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i] %= m;
    }
    for (int i = 1; i <= 2 * n; i++) {
        w[i] = (w[i - 1] + a[i % n]) % m;
    }
    
    // Initialize the prefix sum array t
    for (int i = 1; i <= m; i++) {
        t[i] = 0;
    }
    
    // Count the occurrences of each prefix sum
    for (int i = 1; i <= 2 * n; i++) {
        t[w[i]]++;
    }
    
    // Calculate the answer
    int an = 0;
    for (int i = m; i >= 1; i--) {
        an += (t[i] * i);
        t[i - 1] += t[i];
    }
    
    cout << an;
    return 0;
}