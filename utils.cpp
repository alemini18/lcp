#include <vector>

using namespace std;

long long power(vector<long long> &powers, long long base, long long mod, long long n){ //returns z^n % mod

            if(n >= powers.size()){
                if(powers.empty()){
                    powers.push_back(1LL);
                }
                for(long long i = powers.size(); i <=n; i++){
                    powers.push_back((base*powers.back())%mod);
                }
            }
            return powers[n];
        }

long long dncPower(long long base, long long mod, long long n){ //Standard Divide & Conquer nth-power calculation
    if(n==0){
        return 1LL;
    }
    long long tmp = dncPower(base, mod, n>>1);
    tmp = (tmp*tmp)%mod;
    if(n%2 == 1){
        tmp = (tmp*base)%mod;
    }
    return tmp;
}