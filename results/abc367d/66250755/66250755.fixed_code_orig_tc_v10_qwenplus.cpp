#include<bits/stdc++.h>
using namespace std;

int n, m;
long long an;
int a[400005], w[400005];
map<int, int> t;

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i] %= m;
        a[i + n] = a[i];
    }
    
    w[0] = 0;
    for (int i = 1; i <= 2 * n; i++) {
        w[i] = (w[i - 1] + a[i]) % m;
    }
    
    t.clear();
    t[0] = n; // For positions where prefix sum mod m is 0
    
    for (int i = n + 1; i <= 2 * n; i++) {
        an += t[w[i]];
        if (i >= 2 * n) break;
        t[w[i - n + 1]]++;
    }
    
    cout << an;
    return 0;
}