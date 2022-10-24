#include <cstdio>
#include <chrono>
#include<iostream>
#include "lz76.hpp"
#pragma comment(linker, "/STACK:100000000")
#pragma comment(linker, "/HEAP:100000000")

using namespace std;

const int MAX_MEMORY=1e6;

char text[100000000+2];


int main(int argc, char* argv[]){
    using std::chrono::high_resolution_clock;
    using std::chrono::duration_cast;
    using std::chrono::microseconds;
    double eps=stod(argv[1]);
    int p=0;
    int n=0;
    char ch;
        auto start = high_resolution_clock::now();
    bool flag=true;
    int i=0;
    /*while(flag){
        for(i=0;i<MAX_MEMORY&&flag;i++){
            text[i]=getchar();
            n++;
            if(text[i]==EOF)flag=false;
        }
        p+=lz77::lz77(text,i,eps);
    }*/
    while((ch=getchar())!=EOF){
        text[i++]=ch;
    }
    p=lz77::lz77(text,i,eps);
        
    
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    std::cout<<duration<<" ";
    //delete[] text;
}
