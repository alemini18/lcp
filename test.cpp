#include <bits/stdc++.h>

using namespace std;

int main(){
    srand(time(0));
    int n=1e6;
    cout<<n<<endl;
    for(int i=0;i<n;i++){
        cout<<rand()%2;
    }
}