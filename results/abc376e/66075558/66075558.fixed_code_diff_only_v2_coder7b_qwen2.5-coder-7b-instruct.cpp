#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

#define ll long long

const int INF = 1e18;

struct Node {
    int a, b;
    Node(int _a, int _b) : a(_a), b(_b) {}
    bool operator<(const Node& other) const {
        return a > other.a || (a == other.a && b > other.b);
    }
};

ll solve(int N, int K, vector<int>& A, vector<int>& B) {
    vector<Node> nodes(N);
    for (int i = 0; i < N; ++i) {
        nodes[i] = Node(A[i], B[i]);
    }
    
    sort(nodes.begin(), nodes.end());
    
    priority_queue<int, vector<int>, greater<int>> pq;
    ll sum_B = 0, result = INF;
    
    for (int i = 0; i < N; ++i) {
        pq.push(nodes[i].b);
        sum_B += nodes[i].b;
        
        if (pq.size() > K) {
            sum_B -= pq.top();
            pq.pop();
        }
        
        if (pq.size() == K) {
            result = min(result, (ll)nodes[i].a * sum_B);
        }
    }
    
    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T;
    cin >> T;
    
    while (T--) {
        int N, K;
        cin >> N >> K;
        
        vector<int> A(N), B(N);
        for (int i = 0; i < N; ++i) {
            cin >> A[i];
        }
        for (int i = 0; i < N; ++i) {
            cin >> B[i];
        }
        
        cout << solve(N, K, A, B) << '\n';
    }
    
    return 0;
}