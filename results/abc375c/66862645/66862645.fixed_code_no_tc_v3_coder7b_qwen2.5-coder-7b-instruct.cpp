#include <iostream>
#include <cmath>
using namespace std;

int main(){
    int N;
    cin >> N;
    long double cost = 0, ans = 0;
    long double nowX = 0, nowY = 0, nextX, nextY;

    for(int i = 0; i < N; i++) {
        cin >> nextX >> nextY;
        cost = sqrt(pow(nowX - nextX, 2) + pow(nowY - nextY, 2));
        ans += cost;
        nowX = nextX;
        nowY = nextY;
    }

    cost = sqrt(pow(nowX, 2) + pow(nowY, 2));
    ans += cost;

    cout << ans << endl;
    return 0;
}