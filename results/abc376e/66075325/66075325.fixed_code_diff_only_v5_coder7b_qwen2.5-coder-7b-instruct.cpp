#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

typedef long long ll;
const int MAXN = 2e5 + 5;

struct Node {
    int val, id;
    bool operator<(const Node &other) const {
        return val > other.val || (val == other.val && id < other.id);
    }
};

ll solve(int n, int k, vector<Node>& A, vector<Node>& B) {
    priority_queue<Node> pq;
    ll sum = 0, maxVal = 0, res = LLONG_MAX;

    // Initialize the priority queue with the first K elements
    for (int i = 0; i < k; ++i) {
        pq.push(B[i]);
        sum += B[i].val;
        maxVal = max(maxVal, B[i].val);
    }

    // Iterate through the remaining elements
    for (int i = k; i < n; ++i) {
        pq.push(B[i]);
        sum += B[i].val;
        maxVal = max(maxVal, B[i].val);

        // Remove the largest element to maintain the size of the window as K
        sum -= pq.top().val;
        pq.pop();

        // Calculate the current result
        res = min(res, static_cast<ll>(maxVal) * sum);
    }

    return res;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int T, N, K;
    cin >> T;
    while (T--) {
        cin >> N >> K;
        vector<Node> A(N), B(N);
        for (int i = 0; i < N; ++i) {
            cin >> A[i].val;
            A[i].id = i;
        }
        for (int i = 0; i < N; ++i) {
            cin >> B[i].val;
            B[i].id = i;
        }

        // Sort A based on its value to get the maximum value for each position
        sort(A.begin(), A.end());

        // Sort B based on its value and store the original indices
        sort(B.begin(), B.end());

        // For each unique value in A, calculate the minimum cost
        ll ans = LLONG_MAX;
        for (int i = 0; i < N; ++i) {
            if (i == 0 || A[i].val != A[i - 1].val) {
                ans = min(ans, solve(N, K, A, B));
            }
        }

        cout << ans << '\n';
    }
    return 0;
}