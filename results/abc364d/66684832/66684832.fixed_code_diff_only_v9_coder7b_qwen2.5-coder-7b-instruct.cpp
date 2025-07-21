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

bool compare(int a, int b) {
    return a > b;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> q;
    for (int i = 1; i <= n; i++) cin >> a[i];

    vector<int> dist[n + 1];

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= q; j++) {
            int b;
            cin >> b;
            int d = abs(a[i] - b);
            dist[j].push_back(d);
        }
    }

    for (int i = 1; i <= q; i++) {
        sort(dist[i].begin(), dist[i].end());
    }

    for (int i = 1; i <= q; i++) {
        int k;
        cin >> k;
        cout << dist[i][k - 1] << endl;
    }

    return 0;
}