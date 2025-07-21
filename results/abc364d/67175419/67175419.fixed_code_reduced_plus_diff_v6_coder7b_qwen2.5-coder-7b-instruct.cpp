#include <bits/stdc++.h>
using namespace std;

vector<int> dist;

void preprocess(vector<int>& A, vector<pair<int, int>>& B) {
    int n = A.size();
    int q = B.size();
    
    for(int j = 0; j < q; ++j) {
        int x = B[j].first;
        int k = B[j].second;
        
        dist.clear();
        for(int i = 0; i < n; ++i) {
            dist.push_back(abs(A[i] - x));
        }
        
        sort(dist.begin(), dist.end());
        
        cout << dist[k - 1] << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, q;
    cin >> n >> q;
    
    vector<int> A(n);
    for(int i = 0; i < n; ++i) {
        cin >> A[i];
    }
    
    vector<pair<int, int>> B(q);
    for(int i = 0; i < q; ++i) {
        cin >> B[i].first >> B[i].second;
    }
    
    preprocess(A, B);
    
    return 0;
}