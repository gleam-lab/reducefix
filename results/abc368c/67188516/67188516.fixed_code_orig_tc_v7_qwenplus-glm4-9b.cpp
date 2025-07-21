#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<long long> H(N);
    
    for (int i = 0; i < N; ++i) {
        cin >> H[i];
    }
    
    long long ans = 0;
    for (int i = 0; i < N; ++i) {
        if (H[i] % 3 == 0) {
            // If H[i] is divisible by 3, we need (H[i] / 3) * 2 attacks to bring it to 0, and one more when T is a multiple of 3.
            ans += (H[i] / 3) * 2 + 1;
        } else {
            // If H[i] is not divisible by 3, we need (H[i] - 1) * 2 attacks to bring it to 1, and one more when T is a multiple of 3.
            ans += (H[i] - 1) * 2 + 1;
        }
    }
    
    cout << ans << endl;
    return 0;
}