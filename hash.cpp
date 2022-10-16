#include <deque>
#include <vector>
#include <climits>
#include "utils.cpp"

using namespace std;

constexpr int MAX_SIZE = INT_MAX;

typedef long long ll;

class Hash{ //the hash function used is a polynomial function a_n*z^n+a_(n-1)*z^(n-1)+...+a^1*z % mod
    private:
        long long mod; 
        long long z;
        long long z_inv;
        long long offset = 0;
        long long offset_hash = 0;
        vector<long long> z_powers;
        vector<long long> z_inv_powers;
        deque<long long> prefixes;
        
    public:
        Hash(long long new_mod, long long new_z){ //require mod*mod < LLONG_MAX
            mod = new_mod;
            z = new_z;
            z_inv = dncPower(z,mod,mod-2);
        }
        long long substring( int s, int e){ //return hash of substring [s,e)

            return (((prefixes[e-1]-(s == 0? offset_hash:prefixes[s-1])+mod)%mod)*power(z_inv_powers, z_inv, mod, (long long)s+offset))%mod;
        }
        void update(char c, int buffsize = MAX_SIZE){
            if(prefixes.size() == buffsize){
                offset++;
                offset_hash = prefixes.front();
                prefixes.pop_front();
            }
            prefixes.push_back((prefixes.back()+(long long)c*power(z_powers,z,mod,offset+prefixes.size())%mod)%mod);
        }
};