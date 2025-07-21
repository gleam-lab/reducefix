#include<bits/stdc++.h>
#define ll long long
#define yes cout << "YES\n"
#define no cout << "NO\n"
#define sp ' '
using namespace std;

void solve() {
    ll N;
    cin >> N;
    ll A[N], B[N-1];
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    for (int i = 0; i < N-1; i++) {
        cin >> B[i];
    }
    
    ll m = 0, y = N-1;
    for (int i = 0; i < N-1; i++) {
        if (A[i] <= B[m]) {
            m++;
        } else if (i+1 < N && A[i+1] <= B[m]) {
            m++;
            y = i;
            i++;
        } else {
            cout << -1 << endl;
            return;
        }
    }
    
    if (A[N-1] > B[N-2]) {
        cout << -1 << endl;
        return;
    }
    
    cout << B[y] << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();

    return 0;
}