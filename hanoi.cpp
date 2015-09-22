#include <iostream>
#include <stack>
#include <vector>
using namespace std;


class Hanoi {
  private:
    int number;
    stack<int> pegs[3];

    void print(){
      stack<int> printPegs[3] = {pegs[0], pegs[1], pegs[2]};
      for(int i=0; i<number; i++){
	for(int j=0; j<3; j++){
	  if(!printPegs[j].empty()){
	    cout << printPegs[j].top() << "\t\t";
	    printPegs[j].pop();
	  } else {
	    cout << "\t\t";
	  }
	} cout << endl;
      }
      cout << "========================" << endl;
    }

    void move(int disc, int from, int to){
      pegs[from].pop();
      pegs[to].push(disc);
      print();
      usleep(10000);
    }
	
    void solve(int disc, int from, int to){
      int other;
      if((from == 0 && to == 1) || (from == 1 && to == 0)){
	other = 2;
      } else if((from == 1 && to == 2) || (from == 2 && to == 1)) {
	other = 0;
      } else {
	other = 1;
      }
      //base case
      if(disc == 0){
	return;
      } else {
	solve(disc-1, from, other);
	move(disc, from, to);
	solve(disc-1, other, to);
      }
    }
  public:
    Hanoi(int n){ //n is the number of total discs pushed onto peg 1
      for(int i = n; i>0; i--){
	pegs[0].push(i);
      }
      number = n;
      print();
    }

    void solvePuzzle(){
      solve(number, 0, 2);
    }
};

int main(){

  Hanoi H(10);
  H.solvePuzzle();

}
