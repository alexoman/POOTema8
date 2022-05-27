#include "Multime.h"
#include <bits/stdc++.h>

using namespace std;

Multime::Multime() /// constructor implicit
    {
        nr_elemente = 0;
        tablou = NULL;
    }
Multime::Multime(int n, int *v):nr_elemente(n) /// constructor cu parametri
    {
        tablou = new int[n];
        for(int i = 0; i < n; i++)
            this->tablou[i]=v[i];
    }
Multime::Multime(const Multime& ob) /// constructor copiere
    {
        this->nr_elemente=ob.nr_elemente;
        this->tablou=new int[ob.nr_elemente];
        for(int i=0;i<ob.nr_elemente;i++)
            this->tablou[i]=ob.tablou[i];
    }
Multime::~Multime() /// Destructor
    {
        if(nr_elemente)
            delete[] tablou;
    }

void Multime::elimina()
    {
        int *A = this->tablou;
        int n = this->nr_elemente;
        sort(A,A+n);
        int i = 0;
        while(i<n)
        {
            if(A[i] == A[i+1])
            {
                for(int j=1;j<n-1;j++)
                    A[j]=A[j+1];
                n--;
            }
            else
                i++;
        }
        if(n!=this->nr_elemente)
            n=n+1;
        this->nr_elemente=n;
    }

Multime operator+(Multime& a,Multime &b)
{
    int n1 = a.nr_elemente;
    int n2 = b.nr_elemente;
    int *A1 = a.tablou;
    int *A2 = b.tablou;
    int *v = new int[n1+n2];
    for(int i=0;i<n1;i++)
        v[i]=A1[i];
    for(int i=0;i<n2;i++)
        v[n1+i]=A2[i];
    sort(v+0,v+n1+n2);
    Multime c = Multime(n1+n2,v);
    c.elimina();
    return c;
}

Multime operator*(Multime& a,Multime& b)
{
    int n1 = a.nr_elemente;
    int n2 = b.nr_elemente;
    int *A1 = a.tablou;
    int *A2 = b.tablou;
    int *v = new int[n1];
    int nr = 0;
    for (int i=0;i<n1;i++)
    {
        int ok=0;
        for(int j=0;j<n2 && ok == 0;j++)
            if(A1[i]==A2[i])
                ok=1;
            if(ok)
                v[nr++] = A1[i];
    }
    sort(v,v+nr);
    Multime c(nr,v);
    c.elimina();
    return c;
}
Multime operator-(Multime& a, Multime& b)
{
    int n1 = a.nr_elemente;
    int n2 = b.nr_elemente;
    int *A1 = a.tablou;
    int *A2 = b.tablou;
    int *v = new int[n1];
    int nr=0;
    for(int i=0; i<n1;i++)
    {
        int ok=0;
        for(int j=0;j<n2 && ok == 0; j++)
            if(A1[i]==A2[j])
                ok=1;
        if(ok==0)
            v[nr++]=A1[i];
    }
    sort(v,v+nr);
    Multime c(nr,v);
    c.elimina();
    return c;

}

istream& operator>>(istream& intrare, Multime& ob)
{
    if(ob.nr_elemente!=0)
        delete[] ob.tablou;
    cout<<"Introduceti numarul de elemente al tabloului: ";
    intrare>>ob.nr_elemente;
    cout<<"Elementele tabloului sunt: ";
    ob.tablou = new int[ob.nr_elemente+1];
    for(int i=0; i<ob.nr_elemente;i++)
        intrare>>ob.tablou[i];
    return intrare;
}

ostream& operator<<(ostream& iesire, Multime ob)
{
    iesire<<"Tabloul are "<<ob.nr_elemente<<" elemente, acestea fiind: ";
    for(int i = 0;i<ob.nr_elemente;i++)
        iesire<<ob.tablou[i]<<" ";
    iesire<<"\n";
    return iesire;
}

Multime* CitireAfisare(int n)
{
    Multime* Multimi = new Multime[n];
    for(int i=0;i<n;i++)
        cin>>Multimi[i];
    cout<<"\n";
    for(int i=0;i<n;i++)
        cout<<Multimi[i];
    cout<<"\n";
    return Multimi;
}
