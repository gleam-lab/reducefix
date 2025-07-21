#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> h(n);
    for (int i = 0; i < n; ++i) {
        cin >> h[i];
    }
    
    long long t = 0;
    while (true) {
        bool done = true;
        for (int i = 0; i < n; ++i) {
            if (h[i] > 0) {
                done = false;
                if (t % 3 == 0) {
                    h[i] -= 3;
                } else {
                    h[i]--;
                }
                if (h[i] % 3 == 0) {
                    t += (h[i] / 3) * 3;
                } else {
                    t += h[i];
                }
            }
        }
        if (done) break;
        t++;
    }
    cout << t << endl;
    return 0;
}