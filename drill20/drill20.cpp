#include "std_lib_facilities.h"


template <typename T>
void printout (T& t)
{
	for(auto& i : t)
		cout << i << ' ';
	cout << endl;
}

template<typename C>
void increase(C& c, int n){
	for(auto& i : c)
		i+=n;
}

template <typename Iter1, typename Iter2> //copies Iter1 into Iter2
Iter2 mycopy(Iter1 f1, Iter1 e1, Iter2 f2)
{
	while(f1 != e1)
	{
		*f2 = *f1;
		f1++; f2++;
	}

	return f2;
}

int main()
{
	int tomb[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

	vector<int> vector1 = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

	list<int> lista = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};


	int tomb2[10];
	for(int i = 0; i < 10; ++i) 
		tomb2[i] = tomb[i];

	vector<int> vector2 = vector1;

	list<int> lista2 = lista;



	increase(tomb2, 2);
	increase(vector2, 3);
	increase(lista2, 5);

	cout << "initial condition:\n";
	cout << "arrays: \n";
	printout(tomb);
	printout(tomb2);

	cout << "vectors: \n";
	printout(vector1);
	printout(vector2);

	cout << "lists: \n";
	printout(lista);
	printout(lista2);

	mycopy(tomb2, &tomb2[10], vector1.begin());
	mycopy(lista2.begin(), lista2.end(), tomb);


	cout << "\nafter the copies:\n";
	cout << "arrays: \n";
	printout(tomb);
	printout(tomb2);

	cout << "vectors: \n";
	printout(vector1);
	printout(vector2);

	cout << "lists: \n";
	printout(lista);
	printout(lista2);


	//////vector find//////
	vector<int>::iterator it = find(vector1.begin(), vector1.end(), 3);
	if(it != vector1.end()) 
		cout << "value found at this position: " << distance(vector1.begin(), it) << endl;
	else 
		cout << "the value is not in the vector\n";

	//////list find//////
	list<int>::iterator itl = find(lista.begin(), lista.end(), 8);
	if(itl != lista.end()) 
		cout << "value found at this position: " << distance(lista.begin(), itl) << endl;
	else 
		cout << "the value is not in the list\n";
	


	return 0;
}