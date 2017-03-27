#include <iostream>
#include <vector>
#include <limits>
#include <cmath>
int main()
{
	int n;
	std::cin >> n;
    std::vector < std::vector < double > > Matrix;
    Matrix.clear();
    Matrix.resize(n);
    for(int i = 0; i < n; i++) {
        Matrix[i].resize( n , 0 );
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < i; j++){
            std::cin >> Matrix[i][j];
            if(Matrix[i][j] == -1){
                Matrix[i][j] = 0;
            }
        }
        Matrix[i][i] = 1;
        for(int j = i + 1; j < n; j++){
            std::cin >> Matrix[i][j];
            if(Matrix[i][j] == -1){
                Matrix[i][j] = 0;
            }
        }
    }

    for(int k = 0; k < n; k++){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(( Matrix[i][j] < Matrix[i][k] * Matrix[k][j])&&(Matrix[i][j]!=0)){
                    Matrix[i][j] = Matrix[i][k] * Matrix[k][j];
                }
            }
        }
    }
    int ans = 0;
    for(int i=0; i<n; i++){
        if (Matrix[i][i] > 1){
            ans = 1;
        }
    }
    if(ans == 0){
        std::cout << "No";
    }
    else{
        std::cout << "Yes";
    }
    Matrix.clear();
	return 0;
}
