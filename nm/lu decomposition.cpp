#include <iostream> 
using namespace std; 

const int MAX = 100; 

void luDecomposition(int mat[][MAX], int n) 
{ 
	int lower[n][n], upper[n][n]; 
	memset(lower, 0, sizeof(lower)); 
	memset(upper, 0, sizeof(upper)); 

	for (int i = 0; i < n; i++) { 


		for (int k = i; k < n; k++) { 


			int sum = 0; 
			for (int j = 0; j < i; j++) 
				sum += (lower[i][j] * upper[j][k]); 


			upper[i][k] = mat[i][k] - sum; 
		} 


		for (int k = i; k < n; k++) { 
			if (i == k) 
				lower[i][i] = 1;  
			else { 

 
				int sum = 0; 
				for (int j = 0; j < i; j++) 
					sum += (lower[k][j] * upper[j][i]); 


				lower[k][i] = (mat[k][i] - sum) / upper[i][i]; 
			} 
		} 
	} 


	cout << "Lower Triangular"
		 << "\t \tUpper Triangular" << endl; 

 
	for (int i = 0; i < n; i++) { 

		for (int j = 0; j < n; j++) 
			cout << lower[i][j] << "\t"; 
		cout << "\t"; 


		for (int j = 0; j < n; j++) 
			cout << upper[i][j] << "\t"; 
		cout << endl; 
	} 
} 


int main() 
{ 
	int mat[][MAX] = { { 2, -1, -2 }, 
					{ -4, 6, 3 }, 
					{ -4, -2, 8 } }; 

	luDecomposition(mat, 3); 
	return 0; 
} 
