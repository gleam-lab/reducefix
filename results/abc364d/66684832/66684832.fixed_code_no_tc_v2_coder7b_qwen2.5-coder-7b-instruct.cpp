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
int a[N], f[N],sum[N];
bool vis[N];

// Corrected function to find the k-th closest point to B_j
int findans(int pos, int k) {
    vector<int> distances;
    // Calculate all distances from B_j to A_i
    for (int i = 1; i <= n; i++) {
        distances.push_back(abs(a[i] - pos));
    }
    // Sort the distances
    sort(distances.begin(), distances.end());
    // Return the k-th smallest distance
    return distances[k-1];
}

signed main()
{
    ios::sync_with_stdio(false);
    
    cin >> n >> q;
    for (int i = 1; i <= n; i++)cin >> a[i];
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; i++)sum[i] = sum[i-1]+a[i];
    while (q--) {
        int x, k;
        cin >> x >> k;
        cout << findans(x, k) << endl;
    }
    
    return 0;
}