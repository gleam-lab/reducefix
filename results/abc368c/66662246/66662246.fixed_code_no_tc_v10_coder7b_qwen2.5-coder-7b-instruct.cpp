#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;

int main()
{
    int n;
    cin >> n;
    vector<int> h(n);
    rep(i, n) cin >> h[i];
    ll t = 0;
    bool changed = true;
    while(changed){
        changed = false;
        t++;
        for(int i = 0; i < n; i++){
            if(h[i] > 0){
                changed = true;
                if(t % 3 == 0){
                    h[i] -= 3;
                }else{
                    h[i]--;
                }
            }
        }
    }
    cout << t << endl;
}