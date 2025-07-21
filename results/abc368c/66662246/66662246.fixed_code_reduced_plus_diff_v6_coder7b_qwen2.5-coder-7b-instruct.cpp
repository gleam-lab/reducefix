#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<long long> h(n);
    for(int i = 0; i < n; i++) cin >> h[i];

    long long ans = 0, t = 0;
    while(true){
        bool changed = false;
        for(int i = 0; i < n; i++){
            if(h[i] > 0){
                changed = true;
                t++;
                if(t % 3 == 0) h[i] -= 3;
                else h[i]--;
            }
        }
        if(!changed) break;
        ans = t;
    }

    cout << ans << "\n";
    return 0;
}