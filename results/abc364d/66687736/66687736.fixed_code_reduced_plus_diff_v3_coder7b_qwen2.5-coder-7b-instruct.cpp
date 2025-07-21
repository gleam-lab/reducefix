#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9 + 7;

vector<long long> solve(const vector<long long>& A, const vector<long long>& B, int k) {
    vector<long long> dist(A.size());
    for (size_t i = 0; i < A.size(); ++i) {
        dist[i] = abs(A[i] - B[0]);
    }
    sort(dist.begin(), dist.end());
    return {dist[k - 1]};
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    
    int N, Q;
    cin >> N >> Q;
    vector<long long> A(N), B(Q);
    for (auto& x : A) cin >> x;
    for (auto& x : B) cin >> x;
    
    vector<vector<long long>> results;
    for (auto& x : B) {
        results.push_back(solve(A, {x}, 1)[0]);
    }

    for (auto& result : results) {
        cout << result << '\n';
    }

    return 0;
}