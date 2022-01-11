#include<iostream>
using namespace std;

const int N = 5;

void inputMatrix(double s[][N]);

void findLocalMax(const double s[][N], bool r[][N]);

void showMatrix(const bool r[][N]);

int main(){
	double A[N][N]; 
	bool B[N][N]; 
	cout << "Input the matrix.....\n";
	inputMatrix(A);
	findLocalMax(A,B);
	cout << "Result is \n";
	showMatrix(B);
	return 0;
}

void inputMatrix(double s[][N]){
	for(int i = 0; i < N; i++){
		cout << "Row" << i + 1 << ": ";
		for(int j = 0; j < N; j++){
			cin >> s[i][j];
		}
	}
}

void showMatrix(const bool r[][N]){
	int i,j;
	for( i = 0; i < N; i++){
		for( j = 0; j < N; j++){
			if(r[i][j] == true)
				cout << "1 ";
			else cout << "0 ";
		}
		cout << "\n";
	}
}

void findLocalMax(const double s[][N], bool r[][N]){
	int x,y;
	for( x = 0; x < N; x++){
		for( y = 0; y < N; y++){
			if(s[x][y] < s[x][y+1] || s[x][y] < s[x][y-1] || s[x][y] < s[x+1][y] || s[x][y]<s[x-1][y]){
				r[x][y] = 0;
			}else{r[x][y] = 1;
			r[0][y] = 0;
			r[N-1][y] = 0;
			}
		}
		r[x][0] = 0;
		r[x][N-1] = 0;

	}
}
