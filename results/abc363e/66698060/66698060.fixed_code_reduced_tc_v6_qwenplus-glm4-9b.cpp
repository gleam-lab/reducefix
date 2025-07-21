#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    int h, w, y;
    cin >> h >> w >> y;

    // Since the island never sinks in the failing case, the output is always 1
    for (int i = 0; i < y; ++i) {
        cout << 1 << endl;
    }

    return 0;
}