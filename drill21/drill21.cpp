#include "std_lib_facilities.h"
#include <iostream>
#include <map>
#include <string>
#include <fstream>
#include <vector>
#include <numeric>
#include <algorithm>


struct Item {
	Item(): name{"NA"}, iid{-1}, value{-1} {}
	Item(std::string n, int id, double v): name{n}, iid{id}, value{v} {}

	std::string name;
	int iid;
	double value;
};

std::ostream& operator<< (std::ostream& os, Item& i)
{
	os << i.name << '\t' << i.iid << '\t' << i.value;

	return os;
}

std::istream& operator>> (std::istream& is, Item& i)
{
	if(!(is >> i.name >> i.iid >> i.value ))
		std::cerr << "Error in Item istream operator\n";

	return is;
}

bool operator== (const Item& a, const Item& b)
{
	if(a.iid == b.iid || a.name == b.name) return true;

	return false;
}

template <typename T>
void my_print(T& t)
{
	for(auto& a : t)
		std::cout << a << std::endl;
}
template <typename T1, typename T2>
std::ostream& operator<< (std::ostream& os, std::pair<T1,T2>& p)
{
	os << p.first << ' ' << p.second;

	return os;
}

template <typename T1, typename T2>
std::istream& operator>> (std::istream& is, std::pair<T1,T2>& p)
{
	is >> p.first >> p.second;

	return is;
}


int main()
{

    // VECTOR, LIST
	vector<Item> vi;
	list<Item> li;

	std::ifstream ifs ("itemek.txt");

	for(int i = 0; i < 10; ++i)
	{
		Item tempI;
		ifs >> tempI;

		vi.emplace_back(tempI);
		li.emplace_back(tempI);
	}
	ifs.close();
	std::cout << "original condition:\n";
	my_print(vi);
	
	std::cout << "\nsort by name:\n";
	sort(vi.begin(), vi.end(), [](Item& a, Item& b){ return a.name < b.name ; });
	my_print(vi);

	std::cout << "\nsort by iid:\n";
	sort(vi.begin(), vi.end(), [](Item& a, Item& b){ return a.iid < b.iid ; });
	my_print(vi);

	std::cout << "\nsort by value:\n";
	sort(vi.begin(), vi.end(), [](Item& a, Item& b){ return a.value > b.value ; });
	my_print(vi);

	std::cout << "\ninsert items:\n";
	vi.emplace_back(Item("horse shoe", 99, 12.34));
	vi.emplace_back(Item("Canon S400", 9988, 499.95));
	my_print(vi);

	std::cout << "\nremove by name:\n";

	Item search;
	search.name = "rozsaszintulipan";
	vi.erase(find(vi.begin(), vi.end(), search));
	search.name = "amigransok";
	vi.erase(find(vi.begin(), vi.end(), search));

	my_print(vi);
	
	std::cout << "\nremove by iid:\n";
	search.name = "NA";
	search.iid = 69;
	vi.erase(find(vi.begin(), vi.end(), search));
	search.iid = 420;
	vi.erase(find(vi.begin(), vi.end(), search));

	my_print(vi);

	std::cout << "/////////////////////////list/////////////////////////\n";

	li.sort([](Item& a, Item& b){ return a.name < b.name ; });
	li.sort([](Item& a, Item& b){ return a.iid < b.iid ; });
	li.sort([](Item& a, Item& b){ return a.value > b.value ; });

	li.emplace_back(Item("horse shoe", 99, 12.34));
	li.emplace_back(Item("Canon S400", 9988, 499.95));


	std::cout << "list remove by name" << std::endl;
	search.iid = -1;
	search.name = "hm";
	li.erase(find(li.begin(), li.end(), search));
	search.name = "hehej";
    my_print(li);
	li.erase(find(li.begin(), li.end(), search));
	std::cout << "\nlist remove by iid" <<std::endl;
	search.name = "NA";
	search.iid = 420;
	/*li.erase(find(li.begin(), li.end(), search));
	
	search.iid = 20;
	li.erase(find(li.begin(), li.end(), search));*/
	my_print(li);
    // VECTOR, LIST VEGE
	std::cout << "vector vege" << std::endl;

    //MAP
    std::map<std::string,int> msi;

	std::string pair1 = "pair0";
	for(int i = 0; i < 10; ++i)
	{
		msi.insert(std::pair<std::string,int>(pair1, i + 1 ));
		pair1 = pair1.substr(0,4) + std::to_string(i+1);
	}

	my_print(msi);

	msi.erase(msi.begin(), msi.end());

	std::cout << "erase is done!\n";
	my_print(msi);

	std::cout << "please write 10 <string,int> pair!\n";

	for(int i = 0;i < 10; ++i)
	{
		std::pair<std::string, int> p;
		std::cin >> p;
		msi.insert(p);
	}

	std::cout << "elements of msi:\n";
	my_print(msi);

	int msi_sum = 0;
	std::map<std::string,int>::iterator it;
	for(it = msi.begin(); it != msi.end(); ++it)
		msi_sum += it->second;

	std::cout << "sum of integers in msi:\t" << msi_sum << std::endl;


	std::map<int,std::string> mis;
	for(it = msi.begin(); it != msi.end(); ++it)
	{
		std::pair<int, std::string> p {it->second, it->first};
		mis.insert(p);
	}

	my_print(mis);
    // MAP VEGE

	return 0;
}