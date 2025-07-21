#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

#define ll long long

struct Node {
    int idx, val;
};

bool cmpNode(Node a, Node b) {
    return a.val < b.val;
}

ll findMinExpression(int n, int k, vector<ll>& A, vector<ll>& B) {
    vector<Node> nodes(n);
    for (int i = 0; i < n; ++i) {
        nodes[i] = {i, A[i]};
    }
    
    sort(nodes.begin(), nodes.end(), cmpNode);
    sort(B.begin(), B.end());
    
    priority_queue<ll> pq;
    ll sum = 0;
    for (int i = 0; i < k; ++i) {
        sum += B[nodes[i].idx];
        pq.push(sum);
    }
    
    ll ans = pq.top() * nodes[k - 1].val;
    for (int i = k; i < n; ++i) {
        sum += B[nodes[i].idx] - pq.top();
        pq.pop();
        pq.push(sum);
        ans = min(ans, pq.top() * nodes[i].val);
    }
    
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        
        vector<ll> A(n), B(n);
        for (int i = 0; i < n; ++i) cin >> A[i];
        for (int i = 0; i < n; ++i) cin >> B[i];
        
        ll result = findMinExpression(n, k, A, B);
        cout << result << '\n';
    }
    
    return 0;
}