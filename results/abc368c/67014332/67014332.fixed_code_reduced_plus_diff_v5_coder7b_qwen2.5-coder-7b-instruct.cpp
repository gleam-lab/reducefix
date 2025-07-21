#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> h(n);
    for(int i = 0; i < n; ++i) {
        cin >> h[i];
    }

    int t = 0;
    for(int i = 0; i < n; ++i) {
        while(h[i] > 0) {
            if(t % 3 == 0) {
                h[i] -= 3;
            } else {
                --h[i];
            }
            ++t;
        }
    }

    cout << t << '\n';
    return 0;
}