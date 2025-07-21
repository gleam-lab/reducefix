#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

typedef long long ll;

struct Node {
    ll a, b;
};

bool cmp(Node &a, Node &b) {
    return a.a > b.a || (a.a == b.a && a.b < b.b);
}

ll solve(int n, int k, vector<ll>& A, vector<ll>& B) {
    vector<Node> v(n);
    for (int i = 0; i < n; ++i) {
        v[i] = {A[i], B[i]};
    }
    
    sort(v.begin(), v.end(), cmp);
    
    priority_queue<ll> pq;
    ll sum = 0, res = 0;
    
    for (int i = 0; i < n; ++i) {
        sum += v[i].b;
        pq.push(-v[i].b); // Using negative to simulate min-heap with max-heap
        
        if (pq.size() > k) {
            sum += pq.top();
            pq.pop();
        }
        
        if (pq.size() == k) {
            res = max(res, v[i].a * sum);
        }
    }
    
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
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
        
        cout << solve(n, k, A, B) << "\n";
    }
    
    return 0;
}