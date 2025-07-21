#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

typedef long long ll;
const int MAXN = 2e5 + 9;

struct Node {
    ll val, idx;
    bool operator<(const Node &other) const {
        return val > other.val || (val == other.val && idx < other.idx);
    }
};

ll solve(int n, int k, vector<ll>& A, vector<ll>& B) {
    priority_queue<Node> pq;
    ll total_sum = 0, max_val = 0;
    
    // Initialize the first window of size k
    for (int i = 0; i < k; ++i) {
        pq.push({B[i], i});
        total_sum += B[i];
        max_val = max(max_val, A[i]);
    }
    
    // Calculate the initial result
    ll result = max_val * total_sum;
    
    // Slide the window across the array
    for (int i = k; i < n; ++i) {
        total_sum += B[i];
        total_sum -= pq.top().val;
        pq.pop();
        pq.push({B[i], i});
        
        max_val = max(max_val, A[i]);
        result = min(result, max_val * total_sum);
    }
    
    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<ll> A(n), B(n);
        
        for (int i = 0; i < n; ++i) {
            cin >> A[i];
        }
        
        for (int i = 0; i < n; ++i) {
            cin >> B[i];
        }
        
        cout << solve(n, k, A, B) << '\n';
    }
    
    return 0;
}