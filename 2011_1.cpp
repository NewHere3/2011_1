#include <bits/stdc++.h>

using namespace std;

ifstream duom("Duomenys.txt");
ofstream rez("Rezultatai.txt");

struct patiekalas
{
    string pavadinimas="Error";
    int produktai_kaina[10]={0};
};

int patiekalo_kaina(patiekalas patiekalai[12], int n, int pr_sk);
int pietu_kaina(patiekalas patiekalai[12], int n, int pr_sk);

int main()
{
    int produktai=0, patiekalu_sk=0;
    int produktu_kainos[10]={0};
    patiekalas patiekalai[12];
    duom >> produktai >> patiekalu_sk;
    for(int i=0; i<produktai; i++)
    {
        duom >> produktu_kainos[i];
    }
    for(int i=0; i<patiekalu_sk; i++)
    {
        duom.ignore();
        char temp[16];
        duom.get(temp, 16);
        patiekalai[i].pavadinimas=temp;
        for(int j=0; j<produktai; j++)
        {
            duom >> patiekalai[i].produktai_kaina[j];
            patiekalai[i].produktai_kaina[j]*=produktu_kainos[j];
        }
    }

    for(int i=0; i<patiekalu_sk; i++)
    {
            rez << patiekalai[i].pavadinimas;
            rez << patiekalo_kaina(patiekalai, i, produktai) << '\n';
    }

    rez << pietu_kaina(patiekalai, patiekalu_sk, produktai)/100 << ' ' << pietu_kaina(patiekalai, patiekalu_sk, produktai)%100;
    return 0;
}

int patiekalo_kaina(patiekalas patiekalai[12], int n, int pr_sk)
{
    int x=0;
    for(int i=0; i<pr_sk; i++)
    {
        x+=patiekalai[n].produktai_kaina[i];
    }
return x;
}
int pietu_kaina(patiekalas patiekalai[12], int n, int pr_sk)
{
    int x=0;
    for(int i=0; i<n; i++)
    {
        x+=patiekalo_kaina(patiekalai, i, pr_sk);
    }
    return x;
}
