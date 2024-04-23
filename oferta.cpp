#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>

using namespace std;

int main() {
    ifstream fin("oferta.in");
    ofstream fout("oferta.out");

    int n, K, i, x;
    fin >> n >> K;
    vector<double> preturi(n);

    for (i = 0; i < n; i++) {
        fin >> x;
        preturi[i] = x;
    }
    fin.close();
    if (K == 1) {
        // pentru primele 3 produse, tratam separat cazurile
        vector<double> dp(n);
        dp[0] = preturi[0];
        // pentru primele 2 produse, aplicam prima reducere
        if (preturi[1] > preturi[0])
            dp[1] = preturi[1] + 1.0/2 * preturi[0];
        else
            dp[1] = preturi[0] + 1.0/2 * preturi[1];
        // pentru primele 3 produse, vedem care dintre cazuri este mai ieftin
        // caz1: grupam primele 2 produse
        double caz1 = 0;
        if (preturi[0] > preturi[1])
            caz1 = preturi[0] + 0.5 * preturi[1] + preturi[2];
        else
            caz1 = preturi[0] * 0.5 + preturi[1] + preturi[2];

        // caz2: grupam ultimele 2 produse
        double caz2 = 0;
        if (preturi[1] > preturi[2])
            caz2 = dp[0] + preturi[1] + 0.5 * preturi[2];
        else
            caz2 = dp[0] + preturi[1] * 0.5 + preturi[2];

        // caz3: grupam cele 3 produse
        double caz3 = 0;
        int minim = min(preturi[0], min(preturi[1], preturi[2]));
        caz3 = preturi[0] + preturi[1] + preturi[2] - minim;

        dp[2] = min(caz1, min(caz2, caz3));

        for (i = 3; i < n; i++) {
        // Aplic reducerea 1 pe primele 2 produse
        // si il iau pe al treilea separat
            double caz1 = 0;
            if (preturi[i - 2] > preturi[i - 1])
                caz1 = preturi[i-2] + 0.5*preturi[i-1] + preturi[i] + dp[i-3];
            else
                caz1 = preturi[i-2] * 0.5 + preturi[i-1] + preturi[i] + dp[i-3];
            // Aplic reducerea 1 pe ultimele 2 produse
            // si il iau pe primul separat
            double caz2 = 0;
            if (preturi[i - 1] > preturi[i])
                caz2 = dp[i - 2] + preturi[i - 1] + 0.5 * preturi[i];
            else
                caz2 = dp[i - 2] + 0.5 * preturi[i - 1] + preturi[i];
            // Aplic reducerea 2 pe ultimele 3 produse
            double caz3 = 0;
            minim = min(preturi[i - 2], min(preturi[i - 1], preturi[i]));
            caz3 = dp[i-3] + preturi[i-2] + preturi[i-1] + preturi[i] - minim;
            // Iau individual ultimul produs
            double caz4 = dp[i - 1] + preturi[i];

            double minim1 = min(caz1, caz2);
            double minim2 = min(caz3, caz4);
            double minim_fin = min(minim1, minim2);
            dp[i] = minim_fin;
        }
        // rezultatul final se gaseste in dp[n - 1]
        double rezultat = dp[n - 1];
        fout << fixed << setprecision(1) << rezultat << "\n";
        fout.close();
    }
    return 0;
}
