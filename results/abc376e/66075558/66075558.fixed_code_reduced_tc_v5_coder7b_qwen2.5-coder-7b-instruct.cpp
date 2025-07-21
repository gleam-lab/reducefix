#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

#define int long long

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    cin >> T;
    while (T--) {
        int N, K;
        cin >> N >> K;
        
        vector<pair<int, int>> A(N), B(N);
        for (int i = 0; i < N; ++i) {
            cin >> A[i].first;
            A[i].second = i;
        }
        for (int i = 0; i < N; ++i) {
            cin >> B[i].first;
            B[i].second = i;
        }
        
        // Sort A by first element and B by first element
        sort(A.begin(), A.end());
        sort(B.begin(), B.end());
        
        // Calculate prefix sums for B
        vector<int> prefix_sum_B(N + 1, 0);
        for (int i = 1; i <= N; ++i) {
            prefix_sum_B[i] = prefix_sum_B[i - 1] + B[i - 1].first;
        }
        
        int min_value = LLONG_MAX;
        for (int i = 0; i <= N - K; ++i) {
            int max_A = A[i + K - 1].first;
            int sum_B = prefix_sum_B[i + K] - prefix_sum_B[i];
            min_value = min(min_value, static_cast<long long>(max_A) * sum_B);
        }
        
        cout << min_value << endl;
    }
    return 0;
}