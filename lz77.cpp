#include <bits/stdc++.h>
#include "lz77.hpp"

using namespace std;

int main(){
    int n;
    cin>>n;
    getchar();
    char text[n];
    for(int i=0;i<n;i++)text[i]=getchar();
    std::cerr<<mini::lz77(text,n);
}