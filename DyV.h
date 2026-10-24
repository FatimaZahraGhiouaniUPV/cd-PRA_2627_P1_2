#include <iostream>
#include <vector>
using namespace std;


template <typename T>
int busquedaBinaria(T val, const vector <T> &v, int l, int r){
	if (l > r){
		return -1;
	}
	int medio = (l+r)/2;
	if (v[medio] == val){
		return medio;
	}
	else if (v[medio] > val) {
		return busquedaBinaria(val, v, l, medio-1);
	}
	else {
		return busquedaBinaria(val, v, medio+1, r);
	}
}
template <typename T>
int Partition (vector <T> &v,int l,int r){
	T x = v[r];
	int i=l;
	for (int j=l; j <= r-1; j++){
		if (v[j] <= x){

			swap(v[j], v[i]);
			i++;
		}
	}
	swap(v[i], v[r]);
	return i;

}

template <typename T>
void quicksort(vector<T> &v, int l, int r){
	if (l < r){
		int medio = Partition(v, l, r);
        	quicksort(v, l, medio - 1);
        	quicksort(v, medio + 1, r);
    	}
}
