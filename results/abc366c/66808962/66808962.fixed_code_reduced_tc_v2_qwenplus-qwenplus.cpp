#include <iostream>
#include <map>
using namespace std;

int main() {
    int Q;
    cin >> Q;

    map<int, int> countMap;
    int distinctCount = 0;

    for (int i = 0; i < Q; ++i) {
        int type;
        cin >> type;

        if (type == 1 || type == 2) {
            int x;
            cin >> x;

            if (type == 1) {
                countMap[x]++;
                if (countMap[x] == 1) {
                    distinctCount++;
                }
            } else { // type == 2
                countMap[x]--;
                if (countMap[x] == 0) {
                    distinctCount--;
                }
            }
        } else { // type == 3
            cout << distinctCount << "\n";
        }
    }

    return 0;
}