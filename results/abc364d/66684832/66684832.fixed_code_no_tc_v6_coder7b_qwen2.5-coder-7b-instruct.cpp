#include <iostream>
#include<algorithm>
#include<queue>
#include<map>
#include<vector>
#include<cstring>
using namespace std;
#define int long long
#define endl '\n'
const int N = 2e5 + 9, inf = 0x3f3f3f3f3f3f3f3f;
int n, q;
int a[N];

bool compare(int x, int y) {
    return abs(x) < abs(y);
}

signed main()
{
    ios::sync_with_stdio(false);
    
    cin >> n >> q;
    for (int i = 1; i <= n; i++)cin >> a[i];
    sort(a + 1, a + n + 1, compare);

    while (q--) {
        int x, k;
        cin >> x >> k;
        auto it = upper_bound(a + 1, a + n + 1, x);
        int dist = *it - x;
        if (dist < 0) {
            dist = -(a[n] - x);
        }
        cout << dist << endl;
    }

    return 0;
}