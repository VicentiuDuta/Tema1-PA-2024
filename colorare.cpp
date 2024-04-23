#include <iostream>
#include <fstream>

#define MOD 1000000007

using namespace std;

// functie eficienta pt ridicarea la putere
unsigned long long mod_pow(unsigned long long base, int exponent) {
    unsigned long long result = 1;
    while (exponent > 0) {
        if (exponent % 2 == 1)
            result = (result * base) % MOD;
        base = (base * base) % MOD;
        exponent /= 2;
    }
    return result;
}

int main() {
    ifstream fin("colorare.in");
    ofstream fout("colorare.out");

    int K;
    fin >> K;

    int i, numar_grupuri;
    char orientare, orientare_anterioara;
    unsigned long long int numar_moduri = 1;

    fin >> numar_grupuri >> orientare_anterioara;
    // In cazul in care primul grup e vertical,
    // prima piesa poate fi colorata in 3 moduri, iar urmatoarele in 2
    if (orientare_anterioara == 'V') {
        numar_moduri = 3;
        numar_moduri = (numar_moduri * mod_pow(2, numar_grupuri - 1)) % MOD;
    // In cazul in care primul grup de orizontal,
    // prima piesa poate fi colorata in 6 moduri, iar urmatoarele in 3
    } else {
        numar_moduri = 6;
        numar_moduri = (numar_moduri * mod_pow(3, numar_grupuri - 1)) % MOD;
    }

    for (i = 1; i < K; i++) {
        fin >> numar_grupuri >> orientare;
        if (orientare == 'V') {
            if (orientare_anterioara == 'V') {
                // V -> V = 2
                numar_moduri = (numar_moduri * mod_pow(2, numar_grupuri)) % MOD;
            } else {
                // H -> V = 1
                numar_moduri *= mod_pow(2, numar_grupuri - 1);
                numar_moduri %= MOD;
            }
        } else {
            if (orientare_anterioara == 'V') {
                // V -> H = 2
                numar_moduri = (numar_moduri * 2) % MOD;
                numar_moduri *= mod_pow(3, numar_grupuri - 1);
                numar_moduri %= MOD;
            } else {
                // H -> H = 3
                numar_moduri = (numar_moduri * mod_pow(3, numar_grupuri)) % MOD;
            }
        }
        orientare_anterioara = orientare;
    }

    fin.close();

    fout << numar_moduri;

    fout.close();
    return 0;
}
