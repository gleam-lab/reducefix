#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> A(N), B(N - 1);

    for(int i = 0; i < N; ++i) cin >> A[i];
    for(int i = 0; i < N - 1; ++i) cin >> B[i];

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    int ans = INT_MAX;
    for(int i = 0; i < N - 1; ++i) {
        if(A[i] <= B[i]) continue;
        ans = min(ans, A[i]);
    }

    if(ans == INT_MAX) cout << -1 << '\n';
    else cout << ans << '\n';

    return 0;
}