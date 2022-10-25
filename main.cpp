#include <bits/stdc++.h>

using namespace std;

ifstream duom("Duomenys.txt");
ofstream rez("Rezultatai.txt");

int read(int kv[100], int km[100], int dv[100], int dm[100]);
int poros(int n, int rk[100], int rd[100]);
int atliko(int n, int rk[100], int rd[100], int p);

int main()
{
 int kv[100]={0};
 int km[100]={0};
 int dv[100]={0};
 int dm[100]={0};
 int n=read(kv, km, dv, dm);
 rez << n << '\n';
 rez << poros(n, km, dm) << '\n';
 rez << poros(n, kv, dv) << '\n';
 rez << atliko(n, km, dm, poros(n, km, dm)) << '\n';
 rez << atliko(n, kv, dv, poros(n, kv, dv)) << '\n';
return 0;
}

int atliko(int n, int rk[100], int rd[100], int p)
{
    int x=0;
    for(int i=0; i<100; i++)
    {
        if(rk[i]!=0)
        {
            x++;
        }
    }
        for(int i=0; i<100; i++)
    {
        if(rd[i]!=0)
        {
            x++;
        }
    }
return x-2*p;
}

int poros(int n, int rk[100], int rd[100])
{
    int x=0;

    int rk2[100]={0};
    for(int i=0; i<n; i++)
    {
        rk2[i]=rk[i];
        cout << rk[i] << ' ';
    }
    cout << '\n';
    int rd2[100]={0};
    for(int i=0; i<n; i++)
    {
        rd2[i]=rd[i];
        cout <<rd[i] << ' ';
    }

    for(int i=0; i<100; i++)
    {
        for(int j=0; j<100; j++)
        {
            if(rk2[i]!=0)
            {
                cout << rk2[i] <<' ';
                cout << rd2[j] <<'\n';
            }

            if(rk2[i]==rd2[j] && rk2[i]!=0)
            {
                x++;
                rk2[i]=0;
                rd2[j]=0;
            }
        }
    }
    return x;
}

int read(int kv[100], int km[100], int dv[100], int dm[100])
{
    int n=0;
    duom >> n;
    int l=0, r=0, d=0;
    for(int i=0; i<n;i++)
    {
        duom >> l >> r >> d;
        if(l==3)
        {
            if(r==1)
            {
                kv[i]=d;
            }else if(r==2)
            {
                dv[i]=d;
            }else rez << "Error" << '\n';
        }else if(l==4)
        {
            if(r==1)
            {
                km[i]=d;
            }else if(r==2)
            {
                dm[i]=d;
            }else rez << "Error" << '\n';
        }else rez << "Error" << '\n';
    }
    return n;
}
