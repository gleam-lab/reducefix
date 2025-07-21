#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    i64 N, M;
    cin >> N >> M;
    vector<i64> rows(M), cols(M);
    for (int i = 0; i < M; ++i) {
        cin >> rows[i] >> cols[i];
    }

    // Calculate the number of squares that cannot be occupied due to the constraints of rows and columns
    i64 free_squares = N * N;
    for (i64 row : rows) {
        free_squares -= (N - row - 1);
    }
    for (i64 col : cols) {
        free_squares -= (N - col - 1);
    }

    // Calculate the number of squares that cannot be occupied due to diagonal constraints
    // (i+j) = constant
    vector<i64> diagonal Constraints(N * 2 + 1);
    for (i64 i = 0; i < M; ++i) {
        diagonal Constraints[rows[i] + cols[i]] = 1;
    }
    for (i64 i = 1; i <= N * 2; ++i) {
        free_squares -= (diagonal Constraints[i] - diagonal Constraints[i - 1]);
    }

    // (i-j) = constant
    vector<i64> anti_diagonal Constraints(N * 2 + 1);
    for (i64 i = 0; i < M; ++i) {
        anti_diagonal Constraints[rows[i] - cols[i]] = 1;
    }
    for (i64 i = 1; i <= N * 2; ++i) {
        free_squares -= (anti_diagonal Constraints[i] - anti_diagonal Constraints[i - 1]);
    }

    cout << free_squares << "\n";

    return 0;
}