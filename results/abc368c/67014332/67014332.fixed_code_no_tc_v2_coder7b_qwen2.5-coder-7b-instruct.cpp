#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    long long ans = 0, T = 0;
    cin >> n;
    vector<long long> h(n);
    for(int i = 0; i < n; ++i)
        cin >> h[i];
    
    while(true) {
        bool attacked = false;
        for(int i = 0; i < n; ++i) {
            if(h[i] > 0) {
                --T;
                if(T % 3 == 0)
                    h[i] -= 3;
                else
                    --h[i];
                
                attacked = true;
            }
        }
        
        if(!attacked)
            break;
        
        ++ans;
    }
    
    cout << ans << endl;
    return 0;
}