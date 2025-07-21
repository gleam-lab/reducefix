#include <bits/stdc++.h>
using namespace std;

int main() {
    long double total_cost = 0;
    int N;
    cin >> N;
    int nowX = 0, nowY = 0;
    
    for (int i = 0; i < N; i++) {
        int nextX, nextY;
        cin >> nextX >> nextY;
        long double dx = nowX - nextX;
        long double dy = nowY - nextY;
        total_cost += sqrtl(dx * dx + dy * dy);
        nowX = nextX;
        nowY = nextY;
    }
    
    long double dx = nowX - 0;
    long double dy = nowY - 0;
    total_cost += sqrtl(dx * dx + dy * dy);
    
    cout << fixed << setprecision(15) << total_cost << endl;
    
    return 0;
}