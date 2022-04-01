#include "std_lib_facilities.h"

template<typename T> struct S
{
	S() {}
	S(T v): val{v} {}

	T& get(); 
	const T& get() const;

	void set(T t) { val = t; }
	S& operator= (const T& t) { val = t; return *this; }


	friend istream& operator>> (istream& is, S<T>& t)
	{
		is >> t.val;
		return is;
	}

private:
	T val;
    
};
   // template<typename T> ostream& operator<< (ostream& os, T& t) {os<<t.get();}

template<typename T>
T& S<T>::get()
{
	return val;
}

template<typename T>
const T& S<T>::get() const
{
	return val;
}

template<typename T>
void read_val(T& v)
{
	cin >> v;
}

int main()
try
{
	S<int> sint {5};
	sint.set(17);
    sint=18;
	cout << sint.get() << endl << "S int: ";
	read_val(sint);
	cout << sint.get() << endl;

	S<char> schar {'y'};
	cout << schar.get() << endl << "S char: ";
	read_val(schar);
	cout << schar.get() << endl;

	S<double> sdouble {1.234};
	cout << sdouble.get() << endl << "S double: ";
	read_val(sdouble);
	cout << sdouble.get() << endl;
	
	S<string> sstring {"hm"};
	cout << sstring.get() << endl;

	S<vector<int>> sintvector {vector<int>(9,14)};
	for(auto i : sintvector.get())
	cout << i << endl;
	
	return 0;

}catch(exception& e)
{
	cerr << e.what() << endl;
}catch(...)
{
	cerr << "F\n"; 
}