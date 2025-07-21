#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;
    vector<long long> H(N);
    for (int i = 0; i < N; ++i) {
        cin >> H[i];
    }

    long long T = 0;
    for (long long h : H) {
        long long full = h / 5;
        long long rem = h % 5;

        T += full * 3;

        long long damage = 0;
        while (damage < rem) {
            T++;
            if (T % 3 == 0) {
                damage += 3;
            } else {
                damage += 1;
            }
        }
    }

    cout << T << endl;
    return 0;
}