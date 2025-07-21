#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> H(N);
    for(int i = 0; i < N; i++) {
        cin >> H[i];
    }

    long long T = 0;
    while(true) {
        bool alive = false;
        for(int i = 0; i < N; i++) {
            if(H[i] > 0) {
                alive = true;
                if((T + 1) % 3 == 0) {
                    H[i] -= 3;
                } else {
                    H[i]--;
                }
                break;
            }
        }
        if(!alive) break;
        T++;
    }

    cout << T << endl;
    return 0;
}