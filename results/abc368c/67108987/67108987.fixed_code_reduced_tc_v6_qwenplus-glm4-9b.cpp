#include<bits/stdc++.h>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> H(N + 9);
    for (int i = 1; i <= N; i++) cin >> H[i];
    long long T = 0;
    for (int i = 1; i <= N; i++) {
        int curr = H[i];
        while (curr > 0) {
            if (T % 3 == 0) {
                curr -= 3;
            } else {
                curr--;
            }
            T++;
        }
    }
    cout << T << endl;
    return 0;
}