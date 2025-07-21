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

    int T = 0;
    while(true) {
        bool changed = false;
        for(int i = 0; i < N; ++i) {
            if(H[i] > 0) {
                if((T + 1) % 3 == 0) {
                    H[i] -= 3;
                } else {
                    H[i]--;
                }
                T++;
                changed = true;
            }
        }
        if(!changed) break;
    }

    cout << T << endl;
    return 0;
}