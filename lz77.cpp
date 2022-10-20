#include <cstdio>
#include<iostream>
#include "lz77.hpp"

using namespace std;

int main(){
    int n;
    cin>>n;
    getchar();
    char text[n];
    for(int i=0;i<n;i++)text[i]=getchar();
    int p=lz77::lz77(text,n);
    std::cerr<<"Compressed "<<n<<" bytes  in "<<p<<" phrases"<<std::endl;
}