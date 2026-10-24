#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxBeneficio(int C,const vector<int>& p, const vector<int>& b, int i, vector<vector<int>>& M){
	if (C<=0){
		return 0;
	}
	else if(i<0){
		return 0;
	}
	else if(M[C][i]!=-1){
		return M[C][i];
	
	}
	else{
		int exc=maxBeneficio(C, p, b, i-1, M);
		int inc=0;
		if (C>=p[i]){
			inc=b[i]+ maxBeneficio(C-p[i], p, b, i-1, M);
		}

		M[C][i]=max(inc,exc);
	
	}
	return M[C][i];

}

int main(){
	int C=15;
	int n=3;
	vector<int> p = {9,6,5};
	vector<int> b = {38,40,24};
	vector<vector<int>> M(C + 1, vector<int>(n, -1));

	int beneficio=maxBeneficio(C,p,b,n-1,M);

	cout << beneficio << endl;

	return 0;
}
