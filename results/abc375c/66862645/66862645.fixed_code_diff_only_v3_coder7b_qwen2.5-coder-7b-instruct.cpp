#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    long double cost = 0;
    long double ans = 0;
    int N;
    cin >> N;

    long double nowX = 0 , nowY = 0;
    long double nextX, nextY;

    for(int i = 0;  i < N; i++) {
        cin >> nextX >> nextY;

        cost = sqrtl( powl((nowX - nextX) , 2.0) + powl((nowY - nextY) , 2.0) );

        ans += cost;

        nowX = nextX;
        nowY = nextY;

    }

    cost = sqrtl( powl((nowX - 0) , 2.0) + powl((nowY - 0) , 2.0) );

    ans += cost;

    cout << ans << endl;

    return 0;
}