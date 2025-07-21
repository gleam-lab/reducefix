#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    i64 N, M;
    cin >> N >> M;
    vector<array<i64,2>> g(M);
    vector<i64> A, B, C, D;
    for (int i = 0; i < M; i ++) {
        i64 a, b;
        cin >> a >> b;
        g[i] = {a, b};
        A.push_back(a + b);
        B.push_back(a - b);
        C.push_back(a);
        D.push_back(b);
    }
    sort(begin(A), end(A)); A.erase(unique(begin(A), end(A)), end(A));
    sort(begin(B), end(B)); B.erase(unique(begin(B), end(B)), end(B));
    sort(begin(C), end(C)); C.erase(unique(begin(C), end(C)), end(C));
    sort(begin(D), end(D)); D.erase(unique(begin(D), end(D)), end(D));
    i64 ans = 0;
    
    // Counting positions in each row, column, diagonal and anti-diagonal
    unordered_set<i64> row, col, diag, adiag;
    for(auto [a, b]: g){
        row.insert(a); col.insert(b); diag.insert(a+b); adiag.insert(a-b);
    }

    // Subtracting occupied positions from total
    ans += N*N - row.size() - col.size() - diag.size() - adiag.size();

    // Adding back positions that are counted twice (positions on diagonals)
    for(auto [a, b]: g){
        if(diag.find(a+b) != diag.end()) --ans;
        if(adiag.find(a-b) != adiag.end()) --ans;
    }

    cout << ans << "\n";

    return 0;
}