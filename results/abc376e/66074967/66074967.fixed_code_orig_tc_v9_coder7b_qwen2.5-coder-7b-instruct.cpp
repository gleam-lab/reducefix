#include<bits/stdc++.h>
using namespace std;

struct Node {
    int val, idx;
    bool operator<(const Node &other) const {
        return val > other.val;
    }
};

int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int T;
    cin >> T;
    while(T--){
        int n, k;
        cin >> n >> k;
        vector<Node> A(n), B(n);
        for(int i=0;i<n;i++){
            cin >> A[i].val;
            A[i].idx = i;
        }
        for(int i=0;i<n;i++){
            cin >> B[i].val;
            B[i].idx = i;
        }
        
        sort(A.begin(), A.end());
        sort(B.begin(), B.end());
        
        priority_queue<int> pq;
        int ans = INT_MAX;
        long long sum = 0;
        for(int i=0;i<k;i++){
            sum += B[i].val;
            pq.push(B[i].val);
        }
        for(int i=k;i<n;i++){
            sum += B[i].val;
            pq.push(B[i].val);
            sum -= pq.top();
            pq.pop();
            ans = min(ans, (long long)A[i].val * sum);
        }
        cout << ans << '\n';
    }
    return 0;
}