#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K;
    cin >> N >> K;
    vector<long long> A(N);
    
    // Read the array
    for(int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    // Sort the array
    sort(A.begin(), A.end());

    // The optimal strategy is to remove the K smallest and K largest elements
    long long ans = A[N-K-1] - A[K];

    cout << ans << '\n';

    return 0;
}