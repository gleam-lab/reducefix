#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, m;
ll a[400005], w[400005];
map<ll, int> t;
ll an;

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i] %= m;
        a[i + n] = a[i];
    }
    
    for (int i = 1; i <= 2 * n; i++) {
        w[i] = (w[i - 1] + a[i]) % m;
    }
    
    t[0] = 1;
    for (int i = 1; i < n; i++) {
        t[w[i]]++;
    }
    
    for (int i = n; i <= 2 * n - 1; i++) {
        if (i > n) {
            t[w[i - n]]--;
        }
        an += t[w[i]];
        if (i < 2 * n) {
            t[w[i + 1]]++;
        }
    }
    
    cout << an;
    return 0;
}