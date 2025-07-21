#include<bits/stdc++.h>
using namespace std;

void solve(){
    long long N;
    cin >> N;
    vector<long long> A(N), B(N-1);
    for(int i = 0; i < N; ++i) cin >> A[i];
    for(int i = 0; i < N-1; ++i) cin >> B[i];

    sort(A.begin(), A.end(), greater<long long>());
    sort(B.begin(), B.end(), greater<long long>());

    int a_idx = 0, b_idx = 0;
    while (a_idx < N && b_idx < N-1) {
        if (A[a_idx] <= B[b_idx]) {
            a_idx++;
            b_idx++;
        } else {
            break;
        }
    }

    if (a_idx == N) {
        cout << -1 << endl;
    } else {
        cout << A[a_idx] << endl;
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();

    return 0;
}