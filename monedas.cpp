#include <iostream>
#include <vector>
#include <limits>
using namespace std;

int minMonedas(int A[], int k, int n, vector<vector<int>>& M){
	if (k==0){
		return 0;
	}
	else if (k<0 || n<0){
		return numeric_limits<int>::max();
	}
	else if (M[n][k]!=-1){
		return M[n][k];
	}
	else{
		int inc=minMonedas(A,k-A[n], n, M);
		if (inc!= numeric_limits<int>::max()){
			inc++;
		}
		
		int exc=minMonedas(A, k, n-1, M);
		M[n][k]=min(inc,exc);
	}
	return M[n][k];
}

vector<int> recuperarMonedas(const vector<vector<int>>& M, int A[], int n, int k){
	vector<int>Sol(n, 0);
	int i=n-1;
	int j=k;
	while (i>0 && j>0){
		if (M[i][j]!=M[i-1][j]){
			Sol[i]++;
			j=j-A[i];
		}
		else{
			i=i-1;
		}
	}
	return Sol;
}

int main(){
	int n=3;
	int A[n]={1,4,6};
	int k=8;
	vector<vector<int>> M (n,vector<int>(k+1,-1));
	for (int i=0;i<n;i++){
		for (int j=0;j<k+1;j++){
			M[i][j]=-1;
		}
	}
	for (int i=0;i<n;i++){
		M[i][0]=0;
	}

	cout << minMonedas(A,k,n-1,M)<<endl;
	vector<int>Sol=recuperarMonedas(M, A, n, k);
	for (int i=0;i<n;i++){
		cout<< "Moneda de " << A[i] << ": "<< Sol[i] << endl;
	
	}
	return 0;
}
