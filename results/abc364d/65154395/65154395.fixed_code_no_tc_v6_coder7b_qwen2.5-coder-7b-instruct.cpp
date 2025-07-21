#include<bits/stdc++.h>
using namespace std;

vector<int> A, B;
vector<long long> dist;

void solve() {
    int n, q; cin >> n >> q;
    A.resize(n); 
    for(int i = 0; i < n; i++) {
        cin >> A[i]; 
        A.push_back(A[i]); // Duplicate the array for negative coordinates
    }

    B.resize(q); 
    vector<int> K(q); 
    for(int i = 0; i < q; i++) {
        cin >> B[i] >> K[i]; 
        B.push_back(B[i]); // Duplicate the array for negative coordinates
    }

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    for(int i = 0; i < B.size(); i++) {
        auto it = lower_bound(A.begin(), A.end(), B[i]);
        int idx = it - A.begin();

        if(idx == 0) dist.push_back(abs(A[idx] - B[i]));
        else if(idx == A.size()) dist.push_back(abs(A[idx - 1] - B[i]));
        else dist.push_back(min(abs(A[idx] - B[i]), abs(A[idx - 1] - B[i])));
    }

    for(int i = 0; i < K.size(); i++)
        cout << dist[K[i] - 1] << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T = 1; cin >> T;
    while(T--)
        solve();
    
    return 0;
}