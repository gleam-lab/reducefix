#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define N 100005
int a[N], b[N], k[N], d[N];

int main() {
    int q, n;
    cin >> n >> q;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    for (int i = 1; i <= q; ++i) {
        cin >> b[i] >> k[i];
        d[i] = abs(a[k[i]] - b[i]);
    }

    sort(d + 1, d + q + 1);

    for (int i = 1; i <= q; ++i) {
        cout << d[i] << endl;
    }

    return 0;
}