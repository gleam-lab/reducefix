#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<long long> h(n);
    for(int i = 0; i < n; ++i) {
        cin >> h[i];
    }

    long long t = 0;
    bool changed = true;
    while(changed) {
        changed = false;
        for(int i = 0; i < n; ++i) {
            if(h[i] > 0) {
                changed = true;
                ++t;
                if(t % 3 == 0) {
                    h[i] -= 3;
                } else {
                    --h[i];
                }
            }
        }
    }

    cout << t << endl;
    return 0;
}