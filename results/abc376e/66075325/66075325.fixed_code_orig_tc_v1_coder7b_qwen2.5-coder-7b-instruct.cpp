#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

#define int long long

struct Element {
    int val, idx;
};

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int T;
    cin >> T;
    while (T--) {
        int N, K;
        cin >> N >> K;
        
        vector<Element> A(N), B(N);
        for (int i = 0; i < N; ++i) {
            cin >> A[i].val;
            A[i].idx = i;
        }
        for (int i = 0; i < N; ++i) {
            cin >> B[i].val;
            B[i].idx = i;
        }

        sort(A.begin(), A.end());
        sort(B.begin(), B.end());

        vector<long long> prefix_sum(N + 1, 0);
        for (int i = 0; i < N; ++i) {
            prefix_sum[i + 1] = prefix_sum[i] + B[i].val;
        }

        long long ans = LLONG_MAX;
        for (int i = K - 1; i < N; ++i) {
            ans = min(ans, (long long)A[i].val * (prefix_sum[i + 1] - prefix_sum[i - K + 1]));
        }

        cout << ans << '\n';
    }
    
    return 0;
}