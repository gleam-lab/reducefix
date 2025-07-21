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
int n, m, cnt, ans, q;
int a[N], f[N], sum[N];
bool vis[N];

// Corrected function to find the k-th closest distance
int findans(int pos, int k) {
    // Using multiset to store distances efficiently
    multiset<int> distances;
    for (int i = 1; i <= n; i++) {
        distances.insert(abs(a[i] - pos));
    }
    
    // Extracting the k-th smallest element
    auto it = next(distances.begin(), k - 1);
    return *it;
}

signed main() {
    ios::sync_with_stdio(false);
    
    cin >> n >> q;
    for (int i = 1; i <= n; i++)cin >> a[i];
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; i++)sum[i] = sum[i-1] + a[i];
    
    while (q--) {
        int x, k;
        cin >> x >> k;
        cout << findans(x, k) << endl;
    }
    
    return 0;
}