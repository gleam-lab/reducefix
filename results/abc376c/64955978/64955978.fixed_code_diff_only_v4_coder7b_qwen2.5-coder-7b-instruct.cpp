#include<bits/stdc++.h>
#define ll long long
#define yes cout<<"YES\n"
#define no cout<<"NO\n"
#define sp ' '
using namespace std;

void solve(){
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

    // Check if we can place the largest toy in any box
    if(a.back() > b.back()) {
        cout << -1 << endl;
        return;
    }

    // Find the minimum box size needed to place the largest toy
    ll min_box_size = a.back();
    bool found = false;
    for(ll box : b) {
        if(box >= min_box_size) {
            found = true;
            break;
        }
    }

    if(!found) {
        cout << -1 << endl;
        return;
    }

    cout << min_box_size << endl;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();

    return 0;
}