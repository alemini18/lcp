#include <set>
#include <iostream>
#include<stdio.h>
#include<algorithm>
 namespace lz77{

const int BUFF_DIM=1<<12;
const long long z=31;
const long long inv=129032259;
const long long mod=1e9+7;

long long* A_text, *pot;
char* text;
int n,log;
int lcp(int a, int b){
    long long f1=(A_text[a]-(a==0?0:(A_text[a-1]*z)%mod)+mod)%mod;
    long long f2=(A_text[b]-(b==0?0:(A_text[b-1]*z)%mod)+mod)%mod;
    if(text[a]!=text[b])return -1;
    int l=0,r=std::min({n-a,n-b});
    bool flag=true;
        while(r-l>1){
            int m;
            if(flag){
                m=log;
                flag=false;
            }
            else m=l+(r-l)/2;
            f1=(A_text[a+m]-(a==0?0:(A_text[a-1]*pot[m+1])%mod)+mod)%mod;
            f2=(A_text[b+m]-(b==0?0:(A_text[b-1]*pot[m+1])%mod)+mod)%mod;
            if(f1==f2)l=m;
            else r=m;
        }
        return l;
}
bool cmp( int a, int b){
        int l=lcp(a,b)+1;
        if(l+a>=n)return true;
        if(l+b>=n)return false;
        return text[a+l]<text[b+l];
    }
void print_number(int a){
    if(a<10){putchar(a+'0');
    return;}
    print_number(a/10);
    putchar(a%10+'0');
}
void print(int a, int b, int c){
    /*
    putchar('(');
    print_number(a);
    putchar(',');
    print_number(b);
    putchar(',');
    putchar(c);
    putchar(')');
    */
   putchar(a);
   putchar(b);
   putchar(c);
}
int lz77(char* textn, int nn){
    n=nn;
    log=std::__lg(n);
    A_text=new long long[n];
    text=textn;
    pot=new long long[n+2];
    A_text[0]=text[0];
    pot[0]=1;
    for(int i=1;i<n;i++){
        A_text[i]=((A_text[i-1]*z+text[i])%mod);
        pot[i]=(pot[i-1]*z)%mod;
    }
    pot[n]=(pot[n-1]*z)%mod;
    pot[n+1]=(pot[n]*z)%mod;
    
    std::set<int,decltype(cmp)*> bst(cmp);
    int k=0;
    for(int i=0;i<n;){
        
        auto l=bst.lower_bound(i);
        auto u=bst.upper_bound(i);
        int pi,lambda,c;
        if(l==bst.end()&&u==bst.end()){
           pi=0;
           lambda=0;
           c=text[i];
        }else if(l==bst.end()){
            lambda=lcp(*u,i)+1;
            pi=*u;
            c=i+lambda>=n?'\0':text[i+lambda];
        }else if(u==bst.end()){
            lambda=lcp(*l,i)+1;
            pi=*l;
            c=i+lambda>=n?'\0':text[i+lambda];
        }else{
            if(l!=bst.begin())l--;
            int lam1=lcp(*l,i)+1;
            int lam2=lcp(*u,i)+1;
            if(lam1>lam2){
                lambda=lam1;
                pi=*l;
                c=i+lambda+1>=n?'\0':text[i+lambda];
            }else{
                lambda=lam2;
                pi=*u;
                c=i+lambda+1>=n?'\0':text[i+lambda];
            }
        }
        print(pi,lambda,c);
        k++;
        for(int j=0;j<lambda+1;j++){
            bst.insert(i);
            i++;
        }
    }
    return k;
}
};

