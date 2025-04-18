#include <vector>
#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;
#define ll long double 


ll Mat[5][5] = {
    {-3.17, 1, 0, 0, 0},
    {1, -2, 1, 0L, 0},
    {0, 1, -2, 1, 0},
    {0, 0, 1, -2, 1},
    {0, 0, 0, 1, -3.17}
};

ll b[5] = {0, 1, 1, 1, 0};
ll E = 0.001;


void f1() {
    vector<ll> Piter = { 0,0,0,0,0 };
    vector<ll> Niter = { 0,0,0,0,0 };
    ll PN = 1;
    long long iter = 0;
    while (PN > E) {   
        for (int i = 0; i < 5; i++) {
            ll sum = 0;
            for (int j = 0; j < 5; j++) {
                if (i != j) {
                    sum += Mat[i][j] * Piter[j] * -1;
                }
            }
            sum += b[i];
            sum /= Mat[i][i];
            Niter[i] = sum;
        }
        vector<ll> d;

        for (int i = 0; i < 5; i++) {
            d.push_back(abs(Niter[i] - Piter[i]));
        }

        PN = d[0];
        for (auto i : d) {
            if (PN < i) {
                PN = i;
            }
        }

        Piter = Niter;

        iter++;
    }
    for (auto i : Niter) {
        cout << i << ' ';
    }
    cout << endl << iter;
    cout << endl << PN;
    cin.get();
    cin.get();
}


void f2() {
    for (ll w = 0.2; w <= 2; w += 0.2) {
        vector<ll> Piter = { 0,0,0,0,0 };
        vector<ll> Niter = { 0,0,0,0,0 };
        vector<ll> NRelax = { 0,0,0,0,0 };
        vector<ll> PRelax = { 0,0,0,0,0 };
        ll PN = 1;
        long long iter = 0;
        while (PN > E) {
            for (int i = 0; i < 5; i++) {
                ll sum = 0;
                for (int j = 0; j < 5; j++) {
                    if (i != j) {
                        sum += Mat[i][j] * Piter[j] * -1;
                    }
                }
                sum += b[i];
                sum /= Mat[i][i];
                NRelax[i] = sum * w + (1 - w) * Piter[i];
                Niter[i] = sum;
            }
            vector<ll> d;

            for (int i = 0; i < 5; i++) {
                d.push_back(abs(NRelax[i] - PRelax[i]));
            }

            PN = d[0];
            for (auto i : d) {
                if (PN < i) {
                    PN = i;
                }
            }

            Piter = Niter;
            PRelax = NRelax;
            iter++;
        }
        cout << w << endl;
        cout << iter << endl;
        for (auto i : Niter) {
            cout << i << ' ';
        }
        cout << endl << endl;
    }
    cin.get();
    cin.get();
}



int main()
{
    setlocale(LC_ALL, "Russian");
    /*for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cout << Mat[i][j] << "\t";
        }
        cout << " - " << b[i] << endl;
    }*/
    int a;
    while (true) {
        system("cls");
        cout << "----------Меню----------\n";
        cout << "1.Метод простой итерации\n";
        cout << "2.Простая итерация + релаксация\n";
        cout << "3.Выход\n";
        cin >> a;
        switch (a)
        {
        case 1:
            f1();
            break;
        
        case 2:
            f2();
            break;

        case 3:
            return 0;
            break;
        }
    }
}
