#include <iostream>
#include <cmath>
using namespace std;

int main() {
    long double cost = 0;
    int N;
    cin >> N;

    long double nowX = 0, nowY = 0;
    for (int i = 0; i < N; ++i) {
        long double nextX, nextY;
        cin >> nextX >> nextY;

        long double dx = nowX - nextX;
        long double dy = nowY - nextY;

        cost += sqrtl(dx * dx + dy * dy);

        nowX = nextX;
        nowY = nextY;
    }

    // Return to the origin
    cost += sqrtl(nowX * nowX + nowY * nowY);

    cout << cost << endl;
    return 0;
}