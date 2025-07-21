#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

const int INF = 1e9;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int T;
    cin >> T;
    while(T--) {
        int N, K;
        cin >> N >> K;
        vector<pair<int, int>> A(N), B(N);
        for(int i = 0; i < N; ++i) {
            cin >> A[i].first;
            A[i].second = i;
        }
        for(int i = 0; i < N; ++i) {
            cin >> B[i].first;
            B[i].second = i;
        }

        sort(A.begin(), A.end());
        sort(B.begin(), B.end());

        long long best = INF;
        long long prefix_sum_B[200005] = {};
        for(int i = 0; i < N; ++i) {
            prefix_sum_B[i+1] = prefix_sum_B[i] + B[i].first;
        }

        for(int i = K-1; i < N; ++i) {
            long long current_max_A = A[i].first;
            long long current_sum_B = prefix_sum_B[i+1] - prefix_sum_B[i-K+1];
            best = min(best, current_max_A * current_sum_B);
        }

        cout << best << '\n';
    }
}