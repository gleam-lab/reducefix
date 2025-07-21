#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

const int MAXN = 2e5 + 9, INF = 0x3f3f3f3f;
typedef long long ll;

struct Node {
    int val, idx;
};

bool compare(Node a, Node b) {
    if (a.val != b.val) return a.val > b.val;
    else return a.idx < b.idx;
}

ll solve(int n, int k, vector<int>& A, vector<int>& B) {
    vector<Node> nodes(n);
    for (int i = 0; i < n; ++i) {
        nodes[i].val = A[i];
        nodes[i].idx = i;
    }
    
    sort(nodes.begin(), nodes.end(), compare);
    
    vector<ll> prefixSum(n + 1);
    for (int i = 1; i <= n; ++i) {
        prefixSum[i] = prefixSum[i - 1] + B[nodes[i - 1].idx];
    }
    
    ll result = INF;
    for (int i = 0; i + k - 1 < n; ++i) {
        ll currentMax = nodes[i].val;
        ll currentSum = prefixSum[i + k] - prefixSum[i];
        result = min(result, currentMax * currentSum);
    }
    
    return result;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        
        vector<int> A(n), B(n);
        for (int i = 0; i < n; ++i) cin >> A[i];
        for (int i = 0; i < n; ++i) cin >> B[i];
        
        cout << solve(n, k, A, B) << '\n';
    }
    
    return 0;
}