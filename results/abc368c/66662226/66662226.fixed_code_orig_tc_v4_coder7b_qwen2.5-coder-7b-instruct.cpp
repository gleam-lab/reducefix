#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<int> h(n);
    for(int i=0;i<n;i++) cin >> h[i];

    long long t = 0;
    while(true) {
        bool done = true;
        for(int i=0;i<n;i++) {
            if(h[i]>0) {
                done = false;
                if(t%3==0) h[i]-=3;
                else h[i]-=1;
                t++;
            }
        }
        if(done) break;
    }

    cout << t << '\n';
    return 0;
}