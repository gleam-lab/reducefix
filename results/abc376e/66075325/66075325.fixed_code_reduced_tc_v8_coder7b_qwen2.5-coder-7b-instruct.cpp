#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

const int INF = 0x3f3f3f3f3f3f3f3f;

struct Node {
    int val, id;
    bool operator<(const Node &other) const {
        return val > other.val;
    }
};

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int T;
    cin >> T;
    while(T--) {
        int N, K;
        cin >> N >> K;
        
        vector<Node> A(N), B(N);
        for(int i = 0; i < N; ++i) {
            cin >> A[i].val;
            A[i].id = i;
        }
        for(int i = 0; i < N; ++i) {
            cin >> B[i].val;
            B[i].id = i;
        }

        sort(A.begin(), A.end());
        sort(B.begin(), B.end());

        vector<int> prefix_sum(N+1, 0);
        for(int i = 1; i <= N; ++i) {
            prefix_sum[i] = prefix_sum[i-1] + B[i-1].val;
        }

        long long res = INF;
        priority_queue<Node> pq;
        for(int i = 0; i < N; ++i) {
            pq.push(A[i]);
            if(pq.size() > K) {
                pq.pop();
            }
            if(pq.size() == K) {
                int max_val = pq.top().val;
                res = min(res, 1LL * max_val * (prefix_sum[i+1] - prefix_sum[i-K+1]));
            }
        }

        cout << res << '\n';
    }

    return 0;
}