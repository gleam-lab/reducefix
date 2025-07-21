#include <bits/stdc++.h>
#define INF 0x3f3f3f3f3f3f3f3f
using namespace std;

typedef unsigned long long ull;

const int MAXN = 2e5 + 10;

ull a[MAXN];
ull f[MAXN][2];
ull cnt[MAXN][2];

int main() {
    ull n;
    cin >> n;
    
    for (ull i = 1; i <= n; i++) {
        cin >> a[i];
    }
    
    for (ull i = 1; i <= n; i++) {
        f[i][0] = max(f[i - 1][0], f[i - 1][1]);
        cnt[i][0] = cnt[i - 1][0];
        
        if (cnt[i - 1][0] % 2 == 0) {
            f[i][1] = f[i - 1][0] + a[i] * 2;
            cnt[i][1] = cnt[i - 1][0] + 1;
        } else {
            f[i][1] = f[i - 1][1] + a[i];
            cnt[i][1] = cnt[i - 1][1] + 1;
        }
    }
    
    cout << max(f[n][0], f[n][1]) << endl;
    return 0;
}