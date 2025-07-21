#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<string>
#include<stack>
#include<queue>
#include<set>
#include<map>
#include<numeric>
#include <iomanip>

using namespace std;
using ll = long long;

int main() {
    int N;
    cin >> N;
    vector<ll> H(N);
    for (int i = 0; i < N; ++i) {
        cin >> H[i];
    }
    ll T = 0;
    for (ll h : H) {
        ll cycles = h / 5;
        T += cycles * 3;
        ll remaining = h % 5;
        if (remaining == 0) continue;
        if (T % 3 == 0) {
            if (remaining <= 3) {
                T += 1;
            } else {
                T += 2;
            }
        } else if (T % 3 == 1) {
            if (remaining <= 1) {
                T += 1;
            } else if (remaining <= 2) {
                T += 2;
            } else {
                T += 3;
            }
        } else { // T % 3 == 2
            if (remaining <= 1) {
                T += 1;
            } else {
                T += 2;
            }
        }
    }
    cout << T << endl;
    return 0;
}