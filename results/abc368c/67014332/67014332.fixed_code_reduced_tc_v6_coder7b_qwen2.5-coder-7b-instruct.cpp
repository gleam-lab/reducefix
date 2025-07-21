#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll n, ans=0, tri=1;
    cin>>n;
    vector<ll> enemies(n);
    for(int i=0;i<n;i++) {
        cin>>enemies[i];
    }

    sort(enemies.begin(), enemies.end());

    for(auto &enemy : enemies) {
        while(enemy > 0) {
            if(tri == 3) {
                enemy -= 3;
                ans++;
                tri = 1;
            } else {
                enemy -= 1;
                ans++;
                tri++;
            }
        }
    }

    cout << ans;
    return 0;
}