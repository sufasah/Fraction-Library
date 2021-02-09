#include <vector>
#include <iostream>
#include <algorithm>
#include <fstream>
#include <time.h>
#include <map>
#include <iomanip>
#include <sstream>
#include <limits.h>
#include "kesir.h"
#include <stack>

using namespace std;
void kesirTestEt()
{
	ofstream cikti("o.txt");
	vector<kesir> v;
	srand(25);
	int amount = 80;
	for(int i=0;i<amount;i++)
	{
		kesir k(rand()%21-10, rand()%21-10);
		v.push_back(k);
	}
	for (int i = 0; i < amount; i++)
	{
		int islem = rand() % 4;
		cikti <<"("<< v[i] << ") " << (islem == 0 ? "+" : islem == 1 ? "-" : islem == 2 ? "*" : "/") << " (" << v[i + 1] << ") = ";
		if(islem==0)
		{
			cikti << "(" << v[i] + v[i + 1] << ") " <<setprecision(30)<< (double)(v[i] + v[i + 1]).pay / (v[i] + v[i + 1]).payda<<"   "<<setprecision(30)<< ((double)v[i].pay / v[i].payda + (double)v[i + 1].pay / v[i + 1].payda)<<"   "<<((double)(v[i] + v[i + 1]).pay/(v[i]+v[i+1]).payda == ((double)v[i].pay / v[i].payda +(double)v[i + 1].pay / v[i + 1].payda) ?"T":"F" ) << endl;
		}
		else if(islem==1)
		{
			cikti <<"("<< v[i] - v[i + 1]<<") "<< setprecision(30) << (double)(v[i] - v[i + 1]).pay / (v[i] - v[i + 1]).payda << "   " << setprecision(30) << ((double)v[i].pay / v[i].payda - (double)v[i + 1].pay / v[i + 1].payda) << "   " << ((double)(v[i] - v[i + 1]).pay/(v[i]-v[i+1]).payda == ((double)v[i].pay / v[i].payda - (double)v[i + 1].pay / v[i + 1].payda) ? "T" : "F") <<endl;
		}
		else if(islem==2)
		{
			cikti << "("<<v[i] * v[i + 1]<<") "<< setprecision(30) << (double)(v[i] * v[i + 1]).pay / (v[i] * v[i + 1]).payda << "   " << setprecision(30) << ((double)v[i].pay / v[i].payda * v[i + 1].pay / v[i + 1].payda) << "   " << ((double)(v[i] * v[i + 1]).pay/(v[i]*v[i+1]).payda == ((double)v[i].pay / v[i].payda * v[i + 1].pay / v[i + 1].payda) ? "T" : "F") <<endl;
		}
		else
		{
			cikti <<"("<<v[i] / v[i + 1]<<") "<< setprecision(30) << (double)(v[i] / v[i + 1]).pay / (v[i] / v[i + 1]).payda << "   " << setprecision(30) << ((double)v[i].pay / v[i].payda / v[i + 1].pay * v[i + 1].payda) << "   "<< ((double)(v[i] / v[i + 1]).pay/(v[i]/v[i+1]).payda == ((double)v[i].pay / v[i].payda / v[i + 1].pay * v[i + 1].payda) ? "T" : "F") <<endl;
		}
		i++;
	}

	cikti.close();
}

int main()
{
	// -9223372036854775808 to 9223372036854775807

	kesir k1(-7,6),k2(2,0);
	kesir res = 2 + k1;
	cout << res << endl<<setprecision(100) << (double)res.pay / res.payda << endl << endl <<setprecision(100)<< 4.0 / 6.0 / 7.0 * 7.0 <<endl<<((double)res.pay/res.payda== 4.0 / 7.0 / 6.0 * 7.0 ?"T":"F")<<endl<<setprecision(100)<<2.0/3;
	kesirTestEt();
	return 0;
}
