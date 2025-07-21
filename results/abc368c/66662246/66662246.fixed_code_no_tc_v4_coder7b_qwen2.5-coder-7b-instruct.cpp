#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)

int main() {
    int n;
    cin >> n;
    vector<long long> a(n);
    rep(i, n) cin >> a[i];

    long long ans = 0;
    while(true){
        bool flag = false;
        rep(i, n){
            if(a[i] > 0){
                flag = true;
                if((ans + 1) % 3 == 0){
                    a[i] -= 3;
                }else{
                    a[i] -= 1;
                }
                ans += 1;
            }
        }
        if(!flag){
            break;
        }
    }

    cout << ans << endl;
}