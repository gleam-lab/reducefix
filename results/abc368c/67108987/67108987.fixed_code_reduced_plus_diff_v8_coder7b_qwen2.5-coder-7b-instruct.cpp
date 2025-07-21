#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> H(N);
    for (int i = 0; i < N; i++) cin >> H[i];
    long long T = 0;
    
    while (!H.empty()) {
        T++;
        bool attacked = false;
        for (auto &h : H) {
            if (h > 0) {
                if (T % 3 == 0) h -= 3;
                else h -= 1;
                if (h <= 0) {
                    H.erase(remove(H.begin(), H.end(), h), H.end());
                    break;
                }
                attacked = true;
            }
        }
        if (!attacked) break;
    }
    
    cout << T << endl;
    return 0;
}