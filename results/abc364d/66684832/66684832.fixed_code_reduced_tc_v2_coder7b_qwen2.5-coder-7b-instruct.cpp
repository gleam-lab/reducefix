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

// Function to find the k-th closest distance
int findKthClosest(int b, int k) {
    int left = 0, right = 2e8; // Maximum possible distance
    while (left < right) {
        int mid = (left + right) / 2;
        int count = 0;
        
        // Count how many points are within distance mid of b
        for (int i = 1; i <= n; ++i) {
            if (abs(a[i] - b) <= mid) {
                ++count;
            }
        }
        
        if (count >= k) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    return left;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); // Disable synchronization with cin/cout
    
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    
    while (q--) {
        int x, k;
        cin >> x >> k;
        cout << findKthClosest(x, k) << endl;
    }
    
    return 0;
}