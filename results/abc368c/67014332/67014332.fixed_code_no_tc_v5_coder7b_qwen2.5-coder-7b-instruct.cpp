#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll n, ans=0;
    cin >> n;
    for(int i=0;i<n;i++) {
        ll h;
        cin >> h;
        ans += h / 3; // increase T by number of full attacks that can be made
        h %= 3; // remaining health after full attacks
        
        if(h == 2) { // if there are two units left, we need one more attack
            ans++;
        } else if(h == 1) { // if there is one unit left, we need two more attacks
            ans += 2;
        }
    }
    
    cout << ans;
}