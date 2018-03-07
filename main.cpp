// Make and Run: g++ -I/usr/include/python2.7 main.cpp -lpython2.7 -o main && ./main
/* _Exp_map_consideration_for_Amir (001) */
#include "/usr/include/python2.7/Python.h" /* Should be first include. Find it by locate Python.h in your system*/
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
std::ifstream infile("points.txt");

vector<double> grad (vector<double> vec) {
	vector<double> tmp;
	tmp.push_back(vec[1] - vec[0]);
	int i;
	int vec_size = vec.size();
	for (i = 1; i < vec_size - 1; i++) {
		tmp.push_back(0.5 * (vec[i + 1] - vec[i - 1]));
	}
	tmp.push_back(vec[i] - vec[i - 1]);
	return tmp;
}

int main () {

vector<double> p1;
vector<double> p2;
vector<double> p3;

double a, b;
while (infile >> a >> b)
{
	p1.push_back(a);
	p2.push_back(b);
}

ofstream storefile;
storefile.open ("gradient.txt");

for (int i = 0; i < int(p1.size()); i++) {
	storefile << grad(p1)[i] << " " << grad(p2)[i] << endl;
}

storefile.close();

	char filename[] = "ploter.py";
		FILE* fp;
		Py_Initialize();
		fp = fopen(filename, "r");
		PyRun_SimpleFile(fp, filename);
Py_Finalize();
}



