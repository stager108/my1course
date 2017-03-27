#include "stdio.h"
#include "limits.h"
#include <iostream>

bool is_ok(int n, int m, int prof){
    bool ans = false;
    int aa[10];
    int bb[10];
    for(int i=0; i<prof; i++){
        aa[i] = n%2;
        n = n/2;
    }
    for(int i=0; i<prof; i++){
        bb[i] = m%2;
        m = m/2;
    }

    for(int i=0; i< prof-1; i++){
        ans = ans || ((aa[i]==0)&&(aa[i+1]==0)&&(bb[i]==0)&&(bb[i+1]==0));
        ans = ans || ((aa[i]==1)&&(aa[i+1]==1)&&(bb[i]==1)&&(bb[i+1]==1));

    }
    return (!ans);
}



int main() {
    int n;
	int m;
	int answer = 0;
	int prof = 1;
	std::cin >> n;
    std::cin >> m;
    if (n > m) std::swap(n , m);
    for(int i=0; i < n; i++) prof *= 2;

	int** ans = new int*[prof];
	for (int i = 0; i < prof; i++)
	     ans[i] = new int [m];


	int** mask = new int*[prof];
	for (int i = 0; i < prof; i++)
	     mask[i] = new int [prof];



	for (int i = 0; i < prof; i++)
		for (int j = 0; j < n; j++)
            ans[i][j] = 0;


    for(int i = 0; i < prof; i++)
        for(int j = 0; j < prof; j++)
            mask[i][j] = is_ok(i,j,n);

    for(int i = 0; i < prof; i++)
         ans[i][0] = 1;


    for(int i = 1; i < m; i++){
        for(int k = 0; k < prof; k++){
           for(int j = 0; j < prof; j++){
            ans[k][i] = ans[k][i] + ans[j][i-1]*mask[j][k];
           }
       }
    }

    for(int i = 0; i < prof; i++){
        answer += ans[i][m-1];
    }

    std::cout << answer;
    for (int i = 0; i < prof; i++) delete [] ans[i];
	delete [] ans;
    for (int i = 0; i < prof; i++) delete [] mask[i];
	delete [] mask;
	return 0;

}
