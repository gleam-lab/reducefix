#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int q;
    cin >> q;

    unordered_map<int, int> countMap;
    int distinctCount = 0;

    for (int i = 0; i < q; ++i) {
        int type;
        cin >> type;

        if (type == 1 || type == 2) {
            int x;
            cin >> x;
            int &cnt = countMap[x];
            if (type == 1) {
                cnt++;
                if (cnt == 1) {
                    distinctCount++;
                }
            } else { // type == 2
                cnt--;
                if (cnt == 0) {
                    distinctCount--;
                }
            }
        } else if (type == 3) {
            cout << distinctCount << '\n';
        }
    }

    return 0;
}