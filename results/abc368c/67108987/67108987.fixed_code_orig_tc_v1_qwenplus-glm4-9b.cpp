#include<bits/stdc++.h>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> H(N);
    for (int i = 0; i < N; i++) cin >> H[i];
    long long T = 0;
    for (int i = 0; i < N; i++) {
        if (H[i] % 3 == 0) {  // å¦ææäººçå¥åº·å¼æ¯3çåæ°
            H[i] -= 3;
            T += 3;
        } else {  // å¦åæäººçå¥åº·å¼æ¯1çåæ°
            H[i] -= 1;
            T += 1;
        }
    }
    cout << T << endl;
    return 0;
}