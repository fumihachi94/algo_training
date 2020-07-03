#include <iostream>
#include <string>
#include <fstream>
using namespace std; 

#define N 10

int main()
{
	ifstream in("input.txt");
	cin.rdbuf(in.rdbuf());

	string name[N];
	bool flag = true;

	for(int n=0; n<2; n++){
		cin >> name[n];
		int sz = name[n].length();
		cout << name[n] << " : ";

		for(int i=0; i<sz; i++){
			if(name[n][i]!=name[n][sz-1-i]) {
				cout << "NO" << endl;
				flag = false;
				break;
			}
		}

		if(flag) cout << "YES" << endl;
	}

	return 0;
}	
