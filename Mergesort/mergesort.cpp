// mergesort.cpp : main project file.

#include <iostream>


using namespace std;

int a[10000], buffer[10000];

void MergeSort(int start, int finish, int *buffer){
	if( start + 1 < finish){
         int l = start +( finish - start)/2;//middle
         MergeSort(start, l, buffer);
         MergeSort(l, finish, buffer);
         int i = start, j = l, k = 0;// counts
         while((i < l)&&(j < finish)){
                                  if(a[i] > a[j]){
                                                buffer[k] = a[j];
                                                j++; 
												k++;
                                                } 
                                  else{
                                       buffer[k] = a[i];
                                       i++;
									   k++;
                                       };
                                  };
         if(i < l){ 
			 memcpy(buffer+k, a+i,4*(l-i));
		 } else{
                  memcpy(buffer+k, a+j,4*(finish-j));
                          };

		 memcpy(a+start, buffer,4*(finish-start));
       
         };
     
     
}
int main()
{   
    int n;
	cout<<"vvedite kolichestvo elementov\n";
    cin>>n;
	cout<<"vvedite elementi\n";
    for(int i = 0; i < n; i++)cin>>a[i];
	cout<<"vvedite start i finish\n";
	int x,y;
	cin>>x>>y;
    MergeSort(x , y, buffer);
	for(int i = 0; i < n; i++)cout<<a[i]<<' ';
	return 0;
}


