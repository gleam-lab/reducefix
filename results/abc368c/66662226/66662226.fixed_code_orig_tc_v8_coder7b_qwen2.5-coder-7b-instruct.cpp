#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<long long> h(n);
    for(int i = 0; i < n; i++) {
        cin >> h[i];
    }

    long long t = 0;
    while(true) {
        bool done = true;
        for(int i = 0; i < n; i++) {
            if(h[i] > 0) {
                done = false;
                t++;
                if(t % 3 == 0) {
                    h[i] -= 3;
                } else {
                    h[i]--;
                }
            }
        }
        if(done) break;
    }

    cout << t << '\n';

    return 0;
}