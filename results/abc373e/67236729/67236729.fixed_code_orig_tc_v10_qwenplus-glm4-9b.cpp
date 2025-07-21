#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using u64 = unsigned long long;

int main() {
    i64 N, M, K;
    cin >> N >> M >> K;
    vector<i64> A(N);
    for (i64 &x : A) cin >> x;
    
    sort(A.begin(), A.end(), greater<i64>());
    
    vector<pair<i64, i64>> votes_needed(N);
    i64 tmp = 0, num = 0, remaining_votes = K - accumulate(A.begin(), A.end(), 0LL);
    
    for (i64 i = 0; i < N; ++i) {
        if (num > M) {
            i64 votes_to_surpass = A[i] + (M + 1 - num) * A[i];
            votes_needed[i] = {votes_to_surpass, tmp};
        } else {
            votes_needed[i] = {0, 0};
        }
        tmp += A[i];
        num++;
    }
    
    for (auto &v : votes_needed) {
        cout << v.second << ' ';
    }
    cout << '\n';
    
    return 0;
}