#include <string>
#include <iostream>

using namespace std;


class B1{//vf() f()

	public:
		virtual void vf(){cout << "B1::vf()" << endl;};
		void f(){cout << "B1::f()" << endl;};
		virtual void pvf() = 0;


};
class D1: public B1{
	 
	public:
		void vf(){cout << "D1::vf()" << endl;};
		void f(){cout << "D1::f()" << endl;};
		
		
};
class D2 : public D1{
	public:
	
		void pvf(){cout << "D2::pvf()" << endl;};
};
class B2{
	public:
		virtual void pvf() = 0;
};

class D21: public B2{
	public:
		string s;
		virtual void pvf(){cout << "D21_pvf(): " << s << endl;};
		
};
class D22: public B2{
	public:
		int n;
		virtual void pvf(){cout << "D22_pvf(): " << n << endl;};
		
};
void f(B2& b2)
{
	b2.pvf();
}

int main(){

	//B1 pelda1;
	//pelda1.vf();
	//pelda1.f();
	
	//D1 pelda2;
	//pelda2.vf();
	//pelda2.f();
	
	//B1& b1ref = pelda2;
	//b1ref.vf();
	//b1ref.f();
	
	//d2peldany
	D2 peldaD2;
	peldaD2.vf();
	peldaD2.f();
	peldaD2.pvf();
	
	D21 jaj;
	jaj.s = "neheheheh";
	jaj.pvf();
	
	D22 jaj2;
	jaj2.n = 420;
	jaj2.pvf();
	
	f(jaj);
	f(jaj2);
	
}

