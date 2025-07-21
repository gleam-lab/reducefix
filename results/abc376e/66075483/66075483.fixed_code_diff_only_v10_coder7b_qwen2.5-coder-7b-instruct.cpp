#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

#define int long long

const int inf = 0x3f3f3f3f3f3f3f3f;

struct node {
    int val, idx;
};

bool cmp(node a, node b) {
    return a.val < b.val;
}

signed main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<node> a(n), b(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i].val;
            a[i].idx = i;
        }
        for (int i = 0; i < n; i++) {
            cin >> b[i].val;
        }
        
        // Sort both arrays based on their values
        sort(a.begin(), a.end(), cmp);
        sort(b.begin(), b.end());
        
        // Calculate the initial sum of the smallest k elements of B
        int sum = 0;
        for (int i = 0; i < k; i++) {
            sum += b[i].val;
        }
        
        int ans = inf;
        
        // Iterate through the sorted array A
        for (int i = 0; i <= n - k; i++) {
            // Update the sum by removing the smallest element that is no longer in the window
            if (i > 0) {
                sum -= b[b[i - 1].idx].val;
            }
            // Add the next element to the sum
            sum += b[a[i + k - 1].idx].val;
            // Calculate the current product and update the answer if it's smaller
            ans = min(ans, sum * a[i].val);
        }
        
        cout << ans << endl;
    }
    return 0;
}