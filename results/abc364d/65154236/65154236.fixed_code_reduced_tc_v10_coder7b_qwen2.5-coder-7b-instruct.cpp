#include <bits/stdc++.h>
using namespace std;

vector<int> A, B;
vector<pair<int, int>> queries;

void solve() {
    int n, q;
    cin >> n >> q;
    
    A.resize(n);
    B.resize(q);
    
    for (int i = 0; i < n; ++i) {
        cin >> A[i];
    }
    
    for (int i = 0; i < q; ++i) {
        int b, k;
        cin >> b >> k;
        B[i] = b;
        queries.push_back({b, k});
    }
    
    sort(A.begin(), A.end());
    
    vector<long long> results(q);
    for (int i = 0; i < q; ++i) {
        int b = queries[i].first;
        int k = queries[i].second;
        
        auto it = lower_bound(A.begin(), A.end(), b);
        int index = it - A.begin();
        
        if (index == 0) {
            results[i] = abs(A[index] - b);
        } else if (index == n) {
            results[i] = abs(A[index - 1] - b);
        } else {
            int dist1 = abs(A[index] - b);
            int dist2 = abs(A[index - 1] - b);
            
            if (dist1 < dist2) {
                if (k == 1) {
                    results[i] = dist1;
                } else {
                    results[i] = dist2;
                }
            } else {
                if (k == 1) {
                    results[i] = dist2;
                } else {
                    results[i] = dist1;
                }
            }
        }
    }
    
    for (long long result : results) {
        cout << result << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    solve();
    
    return 0;
}