#include <bits/stdc++.h>
using namespace std;

const int maxN = 2e5 + 5;
int t, n, k, a[maxN], b[maxN];

// Function to calculate the minimum value of the given expression
long long minExpressionValue(int N, int K, vector<int>& A, vector<int>& B) {
    vector<pair<int, int>> p(N);
    for (int i = 0; i < N; ++i) {
        p[i] = {A[i], B[i]};
    }
    
    // Sort pairs based on A[i] in descending order and B[i] in ascending order
    sort(p.begin(), p.end(), [](const pair<int, int>& p1, const pair<int, int>& p2) {
        if (p1.first != p2.first) return p1.first > p2.first;
        return p1.second < p2.second;
    });
    
    long long maxA = 0, sumB = 0;
    for (int i = 0; i < K; ++i) {
        maxA = max(maxA, static_cast<long long>(p[i].first));
        sumB += p[i].second;
    }
    
    long long result = maxA * sumB;
    for (int i = K; i < N; ++i) {
        if (p[i].second > p[K - 1].second) {
            sumB -= p[i - K].second;
            sumB += p[i].second;
            maxA = p[i].first;
            result = min(result, maxA * sumB);
        }
    }
    
    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> t;
    while (t--) {
        cin >> n >> k;
        vector<int> A(n), B(n);
        for (int i = 0; i < n; ++i) {
            cin >> A[i];
        }
        for (int i = 0; i < n; ++i) {
            cin >> B[i];
        }
        
        cout << minExpressionValue(n, k, A, B) << "\n";
    }
    
    return 0;
}