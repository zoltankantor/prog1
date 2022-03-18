#include "std_lib_facilities.h"



struct Person 
{
	Person(string fname = "Nincs", string lname = "Nev", int inage = 0): firstname{fname}, lastname{lname}, p_age{inage}
	{	
		isvalid_name(firstname);
		isvalid_name(lastname);
		isvalid_age(p_age);
	}


	string name() const { return firstname + " " + lastname; }
	int age() const { return p_age; }

	void set_fname(string str) { firstname = str; }
	void set_lname(string str) { lastname = str; }
	void set_age(int a) { p_age = a; }


	void isvalid_name(string& name);
	void isvalid_age(int age);

	private:
	string firstname;
	string lastname;
	int p_age;

};



ostream& operator << (ostream& os, Person& p)
{
	os << "Name: " << p.name();
	os << " \tAge: " << p.age();

	return os;
}

istream& operator >> (istream& is, Person& p)
{
	int age;
	string lname, fname;

	is >> fname;
	p.set_fname(fname);
	p.isvalid_name(fname);

	is >> lname;
	p.set_lname(lname);
	p.isvalid_name(lname);

	is >> age;
	p.set_age(age);
	p.isvalid_age(age);

	return is;

}




int main() 
try {

	Person Goofy {"Mr", "Goofy", 63};
	cout << Goofy << endl;



	vector<Person> people;

	for (int i = 0; i < 3; ++i)
	{
		Person input_person;
		cin >> input_person;

		people.push_back(input_person);
	}

	for (Person& p : people)
	
		cout << p << endl;
	



	return 0;

} catch (exception& e) {
	cerr << e.what() << endl;
} catch (...) {
	cerr << "Error" << endl;
}


void Person::isvalid_age(int i) 
{
	if (i >= 150 || i < 0)
	{
		error("Please enter a valid age!\n");
	}
}


void Person::isvalid_name(string& str)
{
	for (int i = 0; i < str.length(); ++i)
	{
		if (!isalpha(str[i]))
		{
			error("Please enter valid characters for the name\n");
		}
	
	}
}