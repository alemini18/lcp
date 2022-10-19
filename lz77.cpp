#include <bits/stdc++.h>
#include "lz77.hpp"

using namespace std;

int main(){
    int n;
    cin>>n;
    char text[n];
    for(int i=0;i<n;i++)cin>>text[i];
    mini::lz77(text,n);
}