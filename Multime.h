#ifndef MULTIME_H_INCLUDED
#define MULTIME_H_INCLUDED

#include <iostream>
using namespace std;

class Multime
{
private:
    int nr_elemente;
    int* tablou;
public:
    Multime(); /// constructor implicit
    Multime(int n, int *v); /// constructor cu parametri
    Multime(const Multime& ob);
    ~Multime(); /// destructor
    void elimina();
    friend Multime operator+(Multime& , Multime&);
    friend Multime operator*(Multime& , Multime&);
    friend Multime operator-(Multime&, Multime&);
    friend istream& operator>>(istream&, Multime&);
    friend ostream& operator<<(ostream&, Multime);
    friend Multime* CitireAfisare(int n);
};
    Multime operator+(Multime& , Multime&);
    Multime operator*(Multime& , Multime&);
    Multime operator-(Multime&, Multime&);
    istream& operator>>(istream&, Multime&);
    ostream& operator<<(ostream&, Multime);
    Multime* CitireAfisare(int n);


#endif // MULTIME_H_INCLUDED
