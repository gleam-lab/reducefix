#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

#define ll long long

struct Compare {
    bool operator()(ll a, ll b) {
        return a > b;
    }
};

ll minExpression(int N, int K, vector<ll>& A, vector<ll>& B) {
    // Sort A in descending order and B in ascending order
    sort(A.begin(), A.end(), greater<ll>());
    sort(B.begin(), B.end());

    // Calculate the sum of the first K elements in B
    ll min_sum_B = 0;
    for (int i = 0; i < K; ++i) {
        min_sum_B += B[i];
    }

    // Priority queue to store the sums of subsets of size K
    priority_queue<ll, vector<ll>, Compare> pq;
    for (int i = 0; i < K; ++i) {
        pq.push(min_sum_B);
        min_sum_B -= B[i];
        min_sum_B += B[K + i];
    }

    // Iterate through the remaining elements of A
    ll ans = LLONG_MAX;
    for (int i = K; i < N; ++i) {
        ll max_val = A[i];
        ll current_sum_B = pq.top();
        pq.pop();

        ans = min(ans, max_val * current_sum_B);

        // Add the next element to the sum and push back into the heap
        pq.push(current_sum_B + B[i] - B[i - K]);
    }

    // Check the last subset separately
    ans = min(ans, A[N - 1] * min_sum_B);

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    while (T--) {
        int N, K;
        cin >> N >> K;
        vector<ll> A(N), B(N);
        for (int i = 0; i < N; ++i) {
            cin >> A[i];
        }
        for (int i = 0; i < N; ++i) {
            cin >> B[i];
        }

        cout << minExpression(N, K, A, B) << '\n';
    }

    return 0;
}