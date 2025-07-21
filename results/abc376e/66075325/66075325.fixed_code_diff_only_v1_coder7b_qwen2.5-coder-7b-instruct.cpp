#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

const int MAXN = 2e5 + 9, INF = 0x3f3f3f3f3f3f3f3f;

struct Node {
    int val, idx;
};

bool cmp(Node a, Node b) {
    return a.val > b.val;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        
        vector<Node> a(n), b(n);
        for(int i = 0; i < n; ++i) {
            cin >> a[i].val;
            a[i].idx = i;
        }
        for(int i = 0; i < n; ++i) {
            cin >> b[i].val;
        }
        
        sort(a.begin(), a.end());
        sort(b.begin(), b.end(), cmp);
        
        int sum = 0, max_val = 0;
        for(int i = 0; i < k; ++i) {
            sum += b[i].val;
            max_val = max(max_val, a[i].val);
        }
        
        int ans = sum * max_val;
        for(int i = k; i < n; ++i) {
            sum -= b[i-k].val;
            sum += b[i].val;
            max_val = max(max_val, a[i].val);
            ans = min(ans, sum * max_val);
        }
        
        cout << ans << endl;
    }
    return 0;
}