#pragma once
#include <ostream>
#include <math.h>
#include <limits.h>
class kesir
{
private:
	
public:
	long long pay;
	long long payda;
	kesir();
	kesir(long long p, long long pa);
	friend std::ostream&  operator<<(std::ostream&  os,  kesir  x);
	void set(long long p,long long pa);
	kesir dtokesir(double);
	kesir operator+(  kesir  x);
	kesir operator-(  kesir  x);
	kesir operator*(  kesir  x);
	kesir operator/(  kesir  x);
	void operator+=(  kesir  x);
	void operator-=(  kesir  x);
	void operator*=(  kesir  x);
	void operator/=(  kesir  x);
	kesir  operator++();
	kesir  operator--();
	kesir operator++(int);
	kesir operator--(int);
	bool operator<(  kesir  x);
	bool operator>(  kesir  x);
	bool operator>=(  kesir  x);
	bool operator<=(  kesir  x);
	bool operator==(  kesir  x);
	bool operator!=(  kesir  x);
	kesir operator+(long long x);
	kesir operator-(long long  x);
	kesir operator*(long long  x);
	kesir operator/(long long  x);
	void operator+=(long long  x);
	void operator-=(long long  x);
	void operator*=(long long  x);
	void operator/=(long long  x);
	bool operator<(long long  x);
	bool operator>(long long  x);
	bool operator>=(long long  x);
	bool operator<=(long long  x);
	bool operator==(long long);
	bool operator!=(long long);
	kesir operator+(int  x)
	{
		return this->operator+((long long)x);
	}
	kesir operator-(int  x)
	{
		return this->operator-((long long)x);
	}
	kesir operator*(int  x)
	{
		return this->operator*((long long)x);
	}
	kesir operator/(int  x)
	{
		return this->operator/((long long)x);
	}
	void operator+=(int  x)
	{
		return this->operator+=((long long)x);
	}
	void operator-=(int  x)
	{
		return this->operator-=((long long)x);
	}
	void operator*=(int  x)
	{
		return this->operator*=((long long)x);
	}
	void operator/=(int  x)
	{
		return this->operator/=((long long)x);
	}
	bool operator<(int  x)
	{
		return this->operator<((long long)x);
	}
	bool operator>(int  x)
	{
		return this->operator>((long long)x);
	}
	bool operator>=(int  x)
	{
		return this->operator>=((long long)x);
	}
	bool operator<=(int  x)
	{
		return this->operator<=((long long)x);
	}
	bool operator==(int x)
	{
		return this->operator==((long long)x);
	}
	bool operator!=(int x)
	{
		return this->operator!=((long long)x);
	}
	kesir operator+( double x);
	kesir operator-(  double  x);
	kesir operator*(  double  x);
	kesir operator/(  double  x);
	void operator+=(  double  x);
	void operator-=(  double  x);
	void operator*=(  double  x);
	void operator/=(  double  x);
	bool operator<(  double  x);
	bool operator>(  double  x);
	bool operator>=(  double  x);
	bool operator<=(  double  x);
	bool operator==(  double );
	bool operator!=(  double );
private:

};
kesir operator+(int i, kesir x);
kesir operator-(int i, kesir x);
kesir operator*(int i, kesir x);
kesir operator/(int i, kesir x);
bool operator<(int i, kesir x);
bool operator>(int i, kesir x);
bool operator<=(int i, kesir x);
bool operator>=(int i, kesir x);
bool operator==(int i, kesir x);
bool operator!=(int i, kesir x);

kesir operator+(long long i, kesir x);
kesir operator-(long long i, kesir x);
kesir operator*(long long i, kesir x);
kesir operator/(long long i, kesir x);
bool operator<(long long i, kesir x);
bool operator>(long long i, kesir x);
bool operator<=(long long i, kesir x);
bool operator>=(long long i, kesir x);
bool operator==(long long i, kesir x);
bool operator!=(long long i, kesir x);

kesir operator+(double i, kesir x);
kesir operator-(double i, kesir x);
kesir operator*(double i, kesir x);
kesir operator/(double i, kesir x);
bool operator<(double i, kesir x);
bool operator>(double i, kesir x);
bool operator<=(double i, kesir x);
bool operator>=(double i, kesir x);
bool operator==(double i, kesir x);
bool operator!=(double i, kesir x);