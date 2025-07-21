#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    long long ans = 0;
    cin >> n;
    vector<int> health(n);
    for (int i = 0; i < n; ++i)
        cin >> health[i];
    
    for (int t = 1; ; ++t) {
        bool hit = false;
        for (int i = 0; i < n; ++i) {
            if (health[i] > 0) {
                --health[i];
                hit = true;
                if (t % 3 == 0 && health[i] > 0)
                    --health[i];
                ans += !hit;
            }
        }
        if (!hit)
            break;
    }
    
    cout << ans << endl;
    return 0;
}