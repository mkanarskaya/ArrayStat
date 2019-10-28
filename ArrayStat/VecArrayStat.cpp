#include "VecArrayStat.h"

#include <fstream>
#include <algorithm>
#include <numeric>
#include <iostream>
#include <cmath>

using namespace std;

int squar(array <int, 3> a) {
	return a[0] * a[0] + a[1] * a[1] + a[2] * a[2];
}

bool comp(array <int, 3> a, array <int, 3> b) {
	return squar(a)>squar(b);
}

VecArrayStat::VecArrayStat(const string& fname) {
	ifstream file(fname, ifstream::in);
	if (!file.good()) {
		cout << "Cannot open file " << endl;
		exit(1);
	}
	while (!file.eof()) {
		array <int, 3> n;
		int x, y, z;
		file >> x >> y >> z;
		n[0] = x;
		n[1] = y;
		n[2] = z;
		data.push_back(n);
	}
	sort(begin(data), end(data), comp);
	
	vector<double> vec_len(data.size());
	transform(begin(data), end(data), begin(vec_len), [](array <int, 3> val) {return sqrt(squar(val));});
	m_mean = accumulate(begin(vec_len), end(vec_len), 0.) / vec_len.size();

	vector<int> squares(data.size());
	transform(begin(vec_len), end(vec_len), begin(squares), [](int val) {return val * val; });

	double mean_sq = accumulate(begin(squares), end(squares), 0.) / squares.size();
	m_rms = sqrt(mean_sq - m_mean * m_mean);
}

double VecArrayStat::get_mean() const {
	return m_mean;
};

double VecArrayStat::get_rms() const {
	return m_rms;
};

array <int, 3> VecArrayStat::get_max() const {
	return data[data.size() - 1];
};

array <int, 3> VecArrayStat::get_min() const {
	return data[0];
};

size_t VecArrayStat::countLarger(int a) const {
	size_t count = 0;
	for (int i = 0; i < data.size(); i++) {
		if (squar(data[i]) > a*a) {
			count += 1;
		}
	}
	return count;
}

void VecArrayStat::print() const {
	std::cout << "Input const a ";
	double a;
	std::cin >> a;
	std::cout << "average value = " << get_mean() << "; rms = "
		<< get_rms() << "; count value which is more a = " << countLarger(a) << ";\n";
	for (int i = 0; i < data.size(); i++) {
		cout << data[i][0] << " " << data[i][1] << " " << data[i][2] << endl;
	}
}

