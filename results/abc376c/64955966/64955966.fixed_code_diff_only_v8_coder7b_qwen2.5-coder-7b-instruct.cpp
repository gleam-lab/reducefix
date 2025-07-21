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

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    // Find the maximum size among the largest toy and the second largest box
    ll max_size = max(a.back(), b.back());

    // Check if we can place the largest toy in any of the boxes
    bool found = false;
    for(int i = 0; i < N - 1; i++) {
        if(max_size <= b[i]) {
            found = true;
            break;
        }
    }

    if(found) {
        cout << max_size << endl;
    } else {
        cout << -1 << endl;
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();

    return 0;
}