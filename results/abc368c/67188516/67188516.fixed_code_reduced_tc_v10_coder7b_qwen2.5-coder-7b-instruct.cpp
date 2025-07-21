#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> H(N);
    for(int i = 0; i < N; ++i) {
        cin >> H[i];
    }

    long long ans = 0;
    for(int i = 0; i < N; ++i) {
        if(H[i] > 0) {
            if((ans + 1) % 3 == 0) {
                ans += H[i] / 3;
            } else {
                ans += H[i] / 3 + (H[i] % 3 > 0 ? 1 : 0);
            }
        }
    }

    cout << ans << endl;
    return 0;
}