#include <iostream>
#include <vector>

using namespace std;

int main() {
  int N;
  cin >> N;
  
  vector<int> health(N);
  for(int i = 0; i < N; i++) {
    cin >> health[i];
  }

  int time = 0;
  while(true) {
    bool done = true;
    for(int i = 0; i < N; i++) {
      if(health[i] > 0) {
        done = false;
        time++;
        if(time % 3 == 0) {
          health[i] -= 3;
        } else {
          health[i]--;
        }
      }
    }
    if(done) break;
  }
  
  cout << time << endl;
}