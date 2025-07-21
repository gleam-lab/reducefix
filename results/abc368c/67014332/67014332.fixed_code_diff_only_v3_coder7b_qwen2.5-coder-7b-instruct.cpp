#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    long long ans = 0;
    cin >> n;

    vector<long long> health(n);
    for(int i = 0; i < n; i++){
        cin >> health[i];
        ans += health[i]/3;
        health[i] %= 3;
    }

    sort(health.begin(), health.end());

    int t = 0;
    while(!all_of(health.begin(), health.end(), [](long long x){return x <= 0;})){
        if((t+1)%3 == 0){
            for(auto &x: health){
                if(x > 0){
                    x -= 3;
                    ans++;
                }
            }
        } else {
            for(auto &x: health){
                if(x > 0){
                    x -= 1;
                    ans++;
                }
            }
        }
        t++;
    }

    cout << ans << "\n";

    return 0;
}