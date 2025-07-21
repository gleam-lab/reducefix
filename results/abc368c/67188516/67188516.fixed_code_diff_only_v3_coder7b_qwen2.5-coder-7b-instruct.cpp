#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N;
  cin >> N;
  
  long long total_damage = 0;
  
  for(int i = 0; i < N; i++) {
    long long health;
    cin >> health;
    
    while(health > 0) {
      total_damage++;
      if(total_damage % 3 == 0) {
        health -= 3;
      } else {
        health -= 1;
      }
    }
  }
  
  cout << total_damage << endl;
  
  return 0;
}