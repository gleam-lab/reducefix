#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int n;
    cin >> n;
    vector<long long> A(n), B(n-1);
    
    for(int i = 0; i < n; ++i) cin >> A[i];
    for(int i = 0; i < n-1; ++i) cin >> B[i];

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    for(int i = n-2; i >= 0; --i) {
        B[i] += B[i+1];
    }

    long long ans = -1;
    for(int i = 0; i < n-1; ++i) {
        if(A[i] <= B[i]) {
            ans = A[i];
            break;
        }
    }

    cout << ans << '\n';
    return 0;
}