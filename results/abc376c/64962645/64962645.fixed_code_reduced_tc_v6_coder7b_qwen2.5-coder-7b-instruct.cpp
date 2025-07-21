#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    vector<int> A(n), B(n-1);

    for(int i = 0; i < n; ++i) cin >> A[i];
    for(int i = 0; i < n-1; ++i) cin >> B[i];

    sort(A.begin(), A.end(), greater<int>());
    sort(B.begin(), B.end(), greater<int>());

    int i = 0;
    while(i < n-1 && A[i] > B[i]) ++i;

    if(i == n-1) cout << -1 << '\n';
    else cout << A[i] << '\n';

    return 0;
}