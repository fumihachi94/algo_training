#include <iostream>

using namespace std;

int main(void){
  char s;
  cin >> s;
  if (isupper(s)) 
    cout << "A: 大文字" << endl;
  else
    cout << "a: 小文字" <<endl;
  
  return 0;
}