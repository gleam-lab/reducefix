#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

#define int long long

const int N = 2e5 + 9;
int t, n, k;
int a[N], b[N];

struct Node {
    int sum, idx;
};

bool cmp(int &a, int &b) {
    return a > b;
}

void solve() {
    cin >> n >> k;
    
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }
    
    // Sort A in descending order
    sort(a, a + n, cmp);
    
    // Priority queue to store the sum of B values for current set of A values
    priority_queue<Node, vector<Node>, greater<Node>> pq;
    int totalSum = 0;
    
    for (int i = 0; i < k; ++i) {
        pq.push({totalSum + b[i], i});
        totalSum += b[i];
    }
    
    int bestAns = LLONG_MAX;
    
    for (int i = 0; i < n; ++i) {
        int currMax = a[i];
        int currMinSum = pq.top().sum;
        
        bestAns = min(bestAns, currMax * currMinSum);
        
        if (i + k < n) {
            pq.pop();
            pq.push({currMinSum - b[pq.top().idx] + b[i + k], i + k});
        } else {
            break;
        }
    }
    
    cout << bestAns << '\n';
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}