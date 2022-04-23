#include <iostream>
#include <fstream>
#include <vector>
#include <numeric>
#include <algorithm>

int main()
{
	std::vector<double> vd;

	std::ifstream ifs("hehej.txt");
    if(!ifs) std::cout << "nincs ilyen txt" << std::endl;
    double in;
	while(ifs >> in)
	{
		vd.push_back(in);
	}
	ifs.close();
    for(int i = 0; i<vd.size();i++){
        std::cout << vd[i] << "\n";
    }
    std::cout << std::endl;

	std::vector<int> vi(vd.size(), 0);
	copy(vd.begin(), vd.end(), vi.begin());

	for(int i = 0;i < vd.size(); ++i)
		std::cout << vd[i] << '\t' << vi[i] << std::endl;

	double vd_sum = std::accumulate(vd.begin(), vd.end(), 0.0);
	std::cout << "\nsum of vd:\t" << vd_sum << std::endl;

	std::cout << "difference between the two sum:\t" << 
		vd_sum - std::accumulate(vi.begin(), vi.end(), 0) << std::endl;

	std::cout << "\nreversed vd: \n";
	std::reverse(vd.begin(), vd.end());
	for(auto& d : vd)
		std::cout << d << '\n';

	double vd_avg = vd_sum/vd.size();
	std::cout << "\nmean value of vd:\t" << vd_avg <<'\n'<< std::endl;

	int n = 0;
	for(int i = 0; i < vd.size(); ++i) if(vd[i] < vd_avg)
        ++n;
	std::vector<double> vd2(n, 0);
    

	std::copy_if(vd.begin(), vd.end(), vd2.begin(), [vd_avg](double x){ return x < vd_avg; });
	std::cout << "less than mean number (vd2):\n ";
	for(auto& d : vd2)
		std::cout << d << '\n';
	std::cout << std::endl;


	sort(vd.begin(), vd.end());
	std::cout << "sorted vd:\n";
	for(auto& d : vd)
		std::cout << d << '\n';
	std::cout << std::endl;


	return 0;
}