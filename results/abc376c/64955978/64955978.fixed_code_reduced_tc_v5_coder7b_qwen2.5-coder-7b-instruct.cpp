#include<bits/stdc++.h>
#define ll long long
#define yes cout<<"YES\n"
#define no cout<<"NO\n"
#define sp ' '
using namespace std;

void solve() {
    ll N;
    cin >> N;
    vector<ll> a(N), b(N-1);
    for(int i = 0; i < N; i++) {
        cin >> a[i];
    }
    for(int i = 0; i < N-1; i++) {
        cin >> b[i];
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    // Check if we can place all toys in the given boxes
    bool valid = true;
    for(int i = 0; i < N-1; i++) {
        if(a[i] > b[i]) {
            valid = false;
            break;
        }
    }

    if(!valid) {
        cout << -1 << endl;
        return;
    }

    // The maximum toy size is the answer
    cout << *max_element(a.begin(), a.end()) << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();

    return 0;
}