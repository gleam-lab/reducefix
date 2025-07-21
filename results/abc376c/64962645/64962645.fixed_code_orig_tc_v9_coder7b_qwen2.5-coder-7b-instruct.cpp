#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<long long> A(n), B(n-1);
    for (int i = 0; i < n; i++) cin >> A[i];
    for (int i = 0; i < n-1; i++) cin >> B[i];

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    for (int i = 0; i < n-1; i++) {
        if (A[i] > B[i]) {
            cout << -1 << endl;
            return 0;
        }
    }

    cout << *max_element(A.begin(), A.end()) << endl;
    return 0;
}