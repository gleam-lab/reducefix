#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    long double cost = 0;
    long double ans = 0;
    int operation;
    int nowX = 0 , nowY = 0;
    int nextX, nextY;

    cin >> operation;

    for(int i = 0;  i < operation; i++) {
        cin >> nextX >> nextY;
        ans += sqrt(pow(nextX - nowX, 2) + pow(nextY - nowY, 2));
        nowX = nextX;
        nowY = nextY;
    }

    ans += sqrt(pow(nowX, 2) + pow(nowY, 2));

    cout << fixed << setprecision(10) << ans << endl;

    return 0;
}