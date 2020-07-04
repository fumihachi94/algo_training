#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std; 

int detect(int N, vector<int> A){
	vector<int>::iterator iter = max_element(A.begin(), A.end());
	size_t max_index = distance(A.begin(), iter);
	if(max_index!=0){
		for(int n=max_index; n>0; n--){
			if(A[n] - A[n-1] < 0) return 1;
		}
	}
	if(max_index!=N){
		for(int n=max_index; n<N-1; n++){
			if(A[n] - A[n+1] < 0) return 1;
		}
	}
	return 0;
}

int chnage_order(int N, vector<int> A){

	int count = 0;

	// while (detect(N, A))
	while (true)
	{
		if(N == 1) break;
		vector<int>::iterator iter = min_element(A.begin(), A.end());
		size_t min_index = distance(A.begin(), iter);

		if(min_index==0) {
			A.erase(A.begin());
			N--;
			continue;
		}
		else if(min_index==N-1){
			A.pop_back();
			N--;
			continue;
		}

		int tmp = A[min_index];
		if(min_index < N/2){
			A[min_index] = A[min_index-1];
			A[min_index-1] = tmp;
			count++;
		}else{
			A[min_index] = A[min_index+1];
			A[min_index+1] = tmp;
			count++;
		}
	}

	return count;
}

int main()
{
	ifstream in("input.txt");
	cin.rdbuf(in.rdbuf());
	
	int dst[3];

	for(int i=0; i<3; i++){
		int N;
		cin >> N;
		vector<int> A(N);

		for(int n=0; n<N; n++){
			cin >> A[n];
			// cout << A[n] << " " ;
		}
		// cout << chnage_order(N, A);
		dst[i] = chnage_order(N, A);
	}

	// 答え合わせ
	ifstream an("answer.txt");
	cin.rdbuf(an.rdbuf());
	for(int i=0; i<3; i++){
		int ans;
		cin >> ans;
		cout << "No." << i << ": " << dst[i];
		if(dst[i]==ans) cout <<  " " << "OK\n";
		else cout << " " << "NG\n";
	}

	return 0;
}	
