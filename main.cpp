#include <bits/stdc++.h>
#include "Multime.h"

using namespace std;

int main()
{
	cout << "Dati numarul de tablouri: ";

	int n;

	cin >> n;
	Multime* Multimi = CitireAfisare(n);
	for (int i = 0; i < n - 1; i++)
	{
		cout<<"Reuniunea dintre "<<i<<" "<<i+1<<": "<<Multimi[i]+Multimi[i+1];
        cout<<"Intersectia dintre "<<i<<" "<<i+1<<": "<<Multimi[i]*Multimi[i+1];
        cout<<"Diferenta dintre "<<i<<" "<<i+1<<": "<<Multimi[i]-Multimi[i+1];
        cout<<"\n";
	}
	delete[]Multimi;
	return 0;
}
