#include <bits/stdc++.h>

using namespace std;

int main(){
    srand(time(0));
    int n=5e5;
    cout<<n<<endl;
    for(int i=0;i<n;i++){
        cout<<rand()%2;
    }
}