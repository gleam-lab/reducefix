#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

#define int long long

const int INF = 0x3f3f3f3f3f3f3f3f;

struct Node {
    int val, idx;
    bool operator<(const Node &other) const {
        return val > other.val;
    }
};

void solve(int n, int k, vector<int>& A, vector<int>& B) {
    vector<Node> nodes(n);
    for (int i = 0; i < n; ++i) {
        nodes[i] = {A[i], B[i]};
    }
    
    // Sort based on A[i] first, then B[i]
    sort(nodes.begin(), nodes.end());
    
    priority_queue<int> pq;
    long long sum = 0;
    for (int i = 0; i < n; ++i) {
        pq.push(nodes[i].idx);
        sum += nodes[i].val;
        
        // Maintain the size of the queue to be exactly K
        if (pq.size() > k) {
            sum -= nodes[pq.top()].val;
            pq.pop();
        }
        
        // Calculate the result once we have at least K elements
        if (pq.size() == k) {
            int max_A = nodes[i].val;
            int current_sum = sum;
            int result = max_A * current_sum;
            cout << result << endl;
            return;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> A(n), B(n);
        for (int i = 0; i < n; ++i) {
            cin >> A[i];
        }
        for (int i = 0; i < n; ++i) {
            cin >> B[i];
        }
        
        solve(n, k, A, B);
    }
    
    return 0;
}