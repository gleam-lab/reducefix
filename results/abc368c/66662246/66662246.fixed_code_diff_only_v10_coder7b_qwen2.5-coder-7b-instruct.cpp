#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)

int main() {
    int n;
    cin >> n;
    vector<long long> a(n);
    rep(i, n) cin >> a[i];

    long long ans = 0;
    for(int i=0;i<n;i++){
        while(a[i]>0){
            a[i]--;
            ans++;
            if(ans%3==0 && a[i]>=3){
                a[i]-=3;
                ans+=2;
            }
        }
    }

    cout << ans << endl;
}