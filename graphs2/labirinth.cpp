#include <iostream>
#include <deque>
#include <vector>
//#include <limits>
#include <string>
#include <sstream>
#define INT_MAX 2147483647
#define INT_MIN -2147483648
struct Pair{
    int a;
    int b;
};
int main()
{
	int n = 0;
	Pair p, t;
    int x1, x2;
    int y1, y2;
    std::string str;

    std::vector < std::vector < int > > Matrix;
    std::deque <Pair> MyQueue;
    Matrix.clear();

    std::getline( std::cin, str );
    std::istringstream ist( str );
    ist >> n;
    Matrix.resize( n + 2 );
    for( int i = 0; i < n + 2; i++ ) {
        Matrix[i].resize( n + 2, INT_MAX );
    }

    for( int i = 1; i <= n; ++i ) {
        std::getline( std::cin, str );
        ist.str( str );
        ist.clear();
        while( ist >> x1 >> x2) {
            for( int j = x1+1; j <= x2; ++j ) {
                Matrix[i][j] = INT_MIN;
            }
        }
    }
    for(int i=0; i < n+2; i++){
        Matrix[0][i] = INT_MIN;
        Matrix[i][0] = INT_MIN;
        Matrix[n+1][i] = INT_MIN;
        Matrix[i][n+1] = INT_MIN;
    }

    std::cin >> x1 >> y1;
    std::cin >> x2 >> y2;

//    print();

    x1+=1;
    y1+=1;
    x2+=1;
    y2+=1;
  /*  for(int i = 0; i <n+2; i++){
        for(int j = 0; j< n+2; j++){
            std::cout<<Matrix[i][j]<<" ";
        }
        std::cout<<x1<<" "<<y1<<" "<<x2<<" " <<y2<<"\n";
    }*/

    if(Matrix[x1][y1]!= INT_MIN){
        Matrix[x1][y1] = 0;
        p.a = x1;
        p.b = y1;
        MyQueue.push_back(p);
        while(!MyQueue.empty()){
            p = MyQueue.front();
            MyQueue.pop_front();
            if( Matrix[p.a+1][p.b] == INT_MAX){
                Matrix[p.a+1][p.b]  = Matrix[p.a][p.b]+1;
                t.a = p.a+1;
                t.b = p.b;
              //  std::cout <<t.a<<" "<<t.b<<" \n";
                MyQueue.push_back(t);
            }
            if( Matrix[p.a-1][p.b] == INT_MAX){
                Matrix[p.a-1][p.b]  = Matrix[p.a][p.b]+1;
                t.a = p.a-1;
                t.b = p.b;
                //  std::cout <<t.a<<" "<<t.b<<" \n";
                MyQueue.push_back(t);
            }
            if( Matrix[p.a][p.b+1] == INT_MAX){
                Matrix[p.a][p.b+1]  = Matrix[p.a][p.b]+1;
                t.a = p.a;
                t.b = p.b+1;
                  //std::cout <<t.a<<" "<<t.b<<" \n";
                MyQueue.push_back(t);
            }
            if( Matrix[p.a][p.b-1] == INT_MAX){
                Matrix[p.a][p.b-1]  = Matrix[p.a][p.b]+1;
                t.a = p.a;
                t.b = p.b-1;
                  //std::cout <<t.a<<" "<<t.b<<" \n";
                MyQueue.push_back(t);
            }

        }

    }
        /*
    for(int i = 0; i <n+2; i++){
        for(int j = 0; j< n+2; j++){
            std::cout<<Matrix[i][j]<<" ";
        }
        std::cout<<"\n";
    }*/
    if((Matrix[x2][y2]!=INT_MAX)&&(Matrix[x2][y2]!=INT_MIN)){
        std::cout << Matrix[x2][y2];
    }
    else{
        std::cout << "No way";
    }
    // std::cout<< INT_MIN <<" "<< INT_MAX<<"\n";

    Matrix.clear();
    MyQueue.clear();
	return 0;
}
