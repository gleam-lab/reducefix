#include <iostream>
#include <map>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    map<int, int> ballCount;
    int Q;
    cin >> Q;

    int distinctCount = 0;

    for (int i = 0; i < Q; ++i) {
        int type;
        cin >> type;

        if (type == 1 || type == 2) {
            int x;
            cin >> x;

            if (type == 1) {
                if (ballCount[x] == 0) {
                    distinctCount++;
                }
                ballCount[x]++;
            } else { // type == 2
                ballCount[x]--;
                if (ballCount[x] == 0) {
                    distinctCount--;
                }
            }
        } else { // type == 3
            cout << distinctCount << '\n';
        }
    }

    return 0;
}