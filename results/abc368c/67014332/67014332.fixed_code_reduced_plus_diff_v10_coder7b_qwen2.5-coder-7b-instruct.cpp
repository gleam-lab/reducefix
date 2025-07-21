#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<ll> hp(n);
    for(int i = 0; i < n; ++i) cin >> hp[i];

    ll t = 0;
    for(int i = 0; i < n; ++i) {
        while(hp[i] > 0) {
            ++t;
            if(t % 3 == 0) hp[i] -= 3;
            else hp[i]--;
        }
    }

    cout << t << '\n';
    return 0;
}