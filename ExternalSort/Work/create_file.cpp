

#include <stdio.h>
#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>

using namespace std;

double t;
void rr(long int n){
   int i;
   double a;
   freopen("input.txt","w",stdin);
   for(i = 0; i < n; i++){ 
	   fprintf(stdin,"%d",rand()*rand());
	   fputs(" ",stdin);
   };
   fclose(stdin);

};

int main()
{   
    rr(1000000);
	cin>>t;
    return 0;
}
