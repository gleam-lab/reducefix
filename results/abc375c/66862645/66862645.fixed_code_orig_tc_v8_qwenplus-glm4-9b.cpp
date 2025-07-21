#include <iostream>
#include <cmath>
using namespace std;

int main() {
    long double ans = 0.0;
    int nowX = 0, nowY = 0;
    
    int N;
    cin >> N;

    for (int i = 0; i < N; ++i) {
        int nextX, nextY;
        cin >> nextX >> nextY;
        ans += sqrt((long double)(nextX - nowX) * (nextX - nowX) + (nextY - nowY) * (nextY - nowY));
        nowX = nextX;
        nowY = nextY;
    }
    ans += sqrt((long double)(nowX - 0) * (nowX - 0) + (nowY - 0) * (nowY - 0));
    
    cout.precision(10);
    cout << fixed << ans << endl;
    
    return 0;
}