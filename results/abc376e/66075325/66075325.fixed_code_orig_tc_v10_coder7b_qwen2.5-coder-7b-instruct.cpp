#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

typedef pair<long long, long long> pii;

long long solve(int n, int k, vector<int>& A, vector<int>& B) {
    vector<pii> AB(n);
    for (int i = 0; i < n; ++i) {
        AB[i] = {A[i], B[i]};
    }
    
    // Sort based on A values
    sort(AB.begin(), AB.end());
    
    priority_queue<int, vector<int>, greater<int>> pq;
    long long totalSumB = 0;
    for (int i = 0; i < k; ++i) {
        pq.push(AB[i].second);
        totalSumB += AB[i].second;
    }
    
    long long result = totalSumB * AB[k - 1].first;
    
    for (int i = k; i < n; ++i) {
        totalSumB -= pq.top();
        pq.pop();
        
        pq.push(AB[i].second);
        totalSumB += AB[i].second;
        
        result = min(result, totalSumB * AB[i].first);
    }
    
    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    
    while (t--) {
        int n, k;
        cin >> n >> k;
        
        vector<int> A(n), B(n);
        for (int i = 0; i < n; ++i) {
            cin >> A[i];
        }
        for (int i = 0; i < n; ++i) {
            cin >> B[i];
        }
        
        cout << solve(n, k, A, B) << '\n';
    }
    
    return 0;
}