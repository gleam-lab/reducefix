#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    ll ans = 0;
    int current_enemy = 0;
    
    while(current_enemy < n){
        int t = 1 + ans % 3;
        if(a[current_enemy] >= t){
            a[current_enemy] -= t;
            if(a[current_enemy] == 0){
                current_enemy++;
            }
        }else{
            ans++;
        }
    }
    cout << ans << endl;
}