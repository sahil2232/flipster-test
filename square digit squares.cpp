#include <cstring>
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <sstream>


using namespace std;
typedef long long int64;

bool is_square_digit_square(int64 x){
      stringstream ss;  ss << x; 
      string nx = ss.str();
      for(int i=0; i<nx.size(); ++i){
           if(nx[i] == '0' || nx[i] == '1' || nx[i] == '4' || nx[i] =='9' ) continue;
           else return false;
      }
      return true;
}

vector <int64> square_digit_squares;

void precompute(){
   for(int64 i=1; i<=100000; ++i) if(is_square_digit_square(i*i)) 
         square_digit_squares.push_back(i*i);
}

int tcase;
int64 a, b;

int main(){
   precompute();
   for( scanf("%d", &tcase); tcase; tcase -= 1 ) {
       scanf("%lld %lld", &a, &b);
       int res = lower_bound(square_digit_squares.begin(), square_digit_squares.end(), b+1) 
               - lower_bound(square_digit_squares.begin(), square_digit_squares.end(), a); 
       printf("%d\n", res);
   } 
   return 0;  
}

