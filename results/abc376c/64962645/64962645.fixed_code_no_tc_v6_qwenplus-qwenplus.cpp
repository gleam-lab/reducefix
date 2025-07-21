#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    
    vector<long long> A(N);
    vector<long long> B(N - 1);
    
    for (int i = 0; i < N; ++i) cin >> A[i];
    for (int i = 0; i < N - 1; ++i) cin >> B[i];

    // Sort toys and boxes in descending order
    sort(A.begin(), A.end(), greater<>());
    sort(B.begin(), B.end(), greater<>());

    // We need to find the smallest toy that cannot fit into the largest available box
    // The extra toy will determine the required size of the additional box

    int l = 0, r = N - 1;
    while (l < r) {
        int m = (l + r) / 2;
        bool ok = true;
        for (int i = 0; i < N - 1; ++i) {
            if (A[m] > B[i]) {
                ok = false;
                break;
            }
        }
        if (ok) {
            r = m;
        } else {
            l = m + 1;
        }
    }

    // At this point, l is the smallest index such that A[l] can be the size of the purchased box
    cout << A[l] << endl;

    return 0;
}