#include<bits/stdc++.h>
using namespace std;

const int N = 400005;
int n, m, a[N], t[N], an, w[N];

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        a[i] %= m;
        a[i + n] = a[i];
    }
    
    // Initialize the prefix sum array with -1 to handle the case when the prefix sum is not present in the map
    memset(w, -1, sizeof(w));
    w[0] = 0;
    t[0] = 1; // There's one way to have a prefix sum of 0
    
    for (int i = 1; i < 2 * n; ++i) {
        w[i] = (w[i - 1] + a[i]) % m;
        if (i > n) --t[w[i - n]];
        if (i >= n) an += t[w[i]];
        ++t[w[i]];
    }
    
    cout << an;
    return 0;
}