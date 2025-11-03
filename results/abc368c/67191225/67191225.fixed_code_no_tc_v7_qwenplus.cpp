#include<iostream>
#include<vector>

using namespace std;
using ll = long long;

int main()
{
    int N;
    cin >> N;
    vector<ll> H(N);
    for (int i = 0; i < N; i++)
    {
        cin >> H[i];
    }
    
    ll T = 0;
    int current_enemy = 0;
    
    while (current_enemy < N)
    {
        T++;
        // If the current frontmost enemy is already defeated, move to next
        while (current_enemy < N && H[current_enemy] <= 0)
            current_enemy++;
            
        if (current_enemy >= N) break;
        
        // Attack the frontmost enemy
        if (T % 3 == 0)
        {
            H[current_enemy] -= 3;
        }
        else
        {
            H[current_enemy] -= 1;
        }
    }
    
    cout << T << endl;
}