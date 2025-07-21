#include<bits/stdc++.h>
#define ll long long
#define yes cout<<"YES\n"
#define no cout<<"NO\n"
#define sp ' '
using namespace std;

void solve(){
    ll N;
    cin >> N;
    vector<ll> a(N), b(N - 1);
    for(int i = 0; i < N; i++) {
        cin >> a[i];
    }
    for(int i = 0; i < N - 1; i++) {
        cin >> b[i];
    }

    // Sort both arrays in ascending order
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    // Initialize variables
    bool x[N - 1] = {false};
    int m = 0, y = N - 1;

    // Iterate through the sorted arrays
    for(int i = 0; i < N - 1; i++) {
        if(a[i] <= b[m]) {
            x[m] = true;
            m++;
        } else if(i + 1 < N && a[i + 1] <= b[m]) {
            x[m] = true;
            m++;
            y = i;
            i++;
        } else {
            cout << -1 << endl;
            return;
        }
    }

    // Check the last box
    if(m == N - 1) {
        cout << a[y] << endl;
    } else {
        cout << -1 << endl;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}