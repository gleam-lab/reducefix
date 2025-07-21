#include <bits/stdc++.h>
using namespace std;

int main() {
    long double total_distance = 0;
    int N;
    cin >> N;
    
    int nowX = 0, nowY = 0;
    
    for (int i = 0; i < N; i++) {
        int nextX, nextY;
        cin >> nextX >> nextY;
        
        long double dx = nowX - nextX;
        long double dy = nowY - nextY;
        long double distance = sqrtl(dx * dx + dy * dy);
        
        total_distance += distance;
        nowX = nextX;
        nowY = nextY;
    }
    
    long double dx = nowX - 0;
    long double dy = nowY - 0;
    long double distance = sqrtl(dx * dx + dy * dy);
    total_distance += distance;
    
    cout << fixed << setprecision(15) << total_distance << endl;
    
    return 0;
}