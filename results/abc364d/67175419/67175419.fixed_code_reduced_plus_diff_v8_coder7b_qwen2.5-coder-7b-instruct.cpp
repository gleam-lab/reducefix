#include<bits/stdc++.h>
using namespace std;

vector<int> A, B;

void solve() {
    int n, q;
    cin >> n >> q;
    A.resize(n + 1), B.resize(q + 1);
    
    for(int i = 1; i <= n; i++) 
        cin >> A[i];
    
    sort(A.begin(), A.end());
    
    for(int i = 1; i <= q; i++) {
        cin >> B[i] >> A[i];
        auto it = lower_bound(A.begin(), A.end(), B[i]);
        
        if(it == A.end())
            cout << abs(B[i] - A[n]) << '\n';
        else if(it == A.begin())
            cout << abs(B[i] - A[1]) << '\n';
        else {
            int idx = it - A.begin();
            int dist1 = abs(B[i] - A[idx]), dist2 = abs(B[i] - A[idx - 1]);
            cout << min(dist1, dist2) << '\n';
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    solve();
    return 0;
}