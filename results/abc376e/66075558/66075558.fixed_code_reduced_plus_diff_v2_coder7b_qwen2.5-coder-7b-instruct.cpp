#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

struct Node {
    int val, id;
    bool operator<(Node other) const {
        if (val != other.val) return val > other.val;
        else return id < other.id;
    }
};

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int N, K; cin >> N >> K;
        vector<Node> a(N), b(N);
        for (int i = 0; i < N; ++i) cin >> a[i].val, a[i].id = i;
        for (int i = 0; i < N; ++i) cin >> b[i].val, b[i].id = i;
        
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());

        long long ans = LLONG_MAX;
        priority_queue<long long> pq;
        long long sum = 0;
        for (int i = 0; i < K; ++i) {
            pq.push(-b[a[i].id].val);
            sum += b[a[i].id].val;
        }
        ans = min(ans, (long long)a[K-1].val * sum);

        for (int i = K; i < N; ++i) {
            sum += b[a[i].id].val + pq.top();
            pq.pop();
            pq.push(-b[a[i].id].val);
            ans = min(ans, (long long)a[i].val * sum);
        }

        cout << ans << '\n';
    }
    return 0;
}