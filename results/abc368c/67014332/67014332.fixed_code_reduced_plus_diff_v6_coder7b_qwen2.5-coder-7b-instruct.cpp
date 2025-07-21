#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> h(n);
    for(int i = 0; i < n; ++i) {
        cin >> h[i];
    }

    long long ans = 0;
    int tri = 1;
    
    while(true) {
        bool attacked = false;
        
        for(int i = 0; i < n; ++i) {
            if(h[i] > 0) {
                if(tri % 3 == 0) {
                    h[i] -= 3;
                } else {
                    h[i]--;
                }
                
                ans++;
                attacked = true;
                
                if(h[i] <= 0) {
                    h[i] = 0;
                }
            }
            
            if(attacked && h[i] == 0) {
                break;
            }
        }
        
        if(!attacked) {
            break;
        }
        
        tri++;
    }
    
    cout << ans << endl;
    return 0;
}