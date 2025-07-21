#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> H(N);
    for(int i = 0; i < N; i++) {
        cin >> H[i];
    }

    long long ans = 0;
    while(true) {
        bool any_positive = false;
        for(int i = 0; i < N; i++) {
            if(H[i] > 0) {
                any_positive = true;
                if((ans + 1) % 3 == 0) {
                    H[i] -= 3;
                } else {
                    H[i]--;
                }
                if(H[i] <= 0) {
                    H[i] = 0;
                }
                ans++;
                break;
            }
        }
        if(!any_positive) {
            break;
        }
    }

    cout << ans << endl;
    return 0;
}