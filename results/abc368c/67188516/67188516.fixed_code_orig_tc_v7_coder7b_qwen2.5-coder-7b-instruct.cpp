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

    long long T = 0;
    for(int i = 0; i < N;) {
        int j = i;
        while(j < N && H[j] > 0) {
            if((T + 1) % 3 == 0) {
                H[j] -= 3;
            } else {
                H[j]--;
            }
            T++;
            if(H[j] <= 0) {
                j++;
            }
        }
        i = j;
    }
    cout << T << endl;
}