#include "kesir.h"
long long ebob(long long a, long long b)
{
	return (b == 0 ? a : ebob(b, a % b));
}
long long ekok(long long a, long long b)
{
	return (a * b / ebob(a, b));
}
std::ostream&  operator<<(std::ostream&  os,  kesir  x)
{
	os << x.pay << " / " << x.payda;
	return os;
}
kesir kesir::dtokesir(double x)
{
	kesir res;
	if (x==0||isinf(x))
	{
		res.pay = isinf(x)?LLONG_MAX:0;
		res.payda = 1;
		return res;
	}
	res.pay = x * 10000000000;
	res.payda = 10000000000;
	long long ebobPayPayda = ebob(res.pay,res.payda);
	res.pay /= ebobPayPayda;
	res.payda /= ebobPayPayda;
	return res;
}
kesir::kesir()
{
	pay = 0;
	payda = 1;
}
kesir::kesir(long long p, long long pa)
{
	if(pa==0)
	{
		throw "Sifira Bolme Hatasi!";
	}
	else if(p==0)
	{
		this->pay = 0;
		this->payda = 1;
		return;
	}
	bool pneg = p < 0 ? true : false;
	bool paneg = pa < 0 ? true : false;
	this->payda = abs(pa);
	this->pay = (pneg!=paneg)?-abs(p):abs(p);
	long long ebobPayPayda = ebob(abs(this->pay), this->payda);
	this->pay /= ebobPayPayda;
	this->payda /= ebobPayPayda;
}
void kesir::set(long long p,long long pa)
{
	if (pa == 0)
	{
		throw "Sifira Bolme Hatasi!";
	}
	else if (p == 0)
	{
		this->pay = 0;
		this->payda = 1;
		return;
	}
	bool pneg = p < 0 ? true : false;
	bool paneg = pa < 0 ? true : false;
	this->payda = abs(pa);
	this->pay = (pneg != paneg) ? -abs(p) : abs(p);
}
kesir kesir::operator+(  kesir  x)
{
	kesir res;
	res.payda = ekok(this->payda, x.payda);
	res.pay = res.payda * this->pay / this->payda + res.payda * x.pay / x.payda ;
	if (res.pay == 0 ) {
		res.payda = 1;
		return res;
	}
	long long ebobPayPayda = ebob(abs(res.pay), res.payda);
	res.pay /= ebobPayPayda;
	res.payda /= ebobPayPayda;
	return res;
}
kesir kesir::operator-(  kesir  x)
{
	kesir res;
	res.payda = ekok(this->payda, x.payda);
	res.pay = res.payda * this->pay / this->payda - res.payda * x.pay / x.payda;
	if (res.pay == 0 )
	{
		res.payda = 1;
		return res;
	}
	long long ebobPayPayda = ebob(abs(res.pay), res.payda);
	res.pay /= ebobPayPayda;
	res.payda /= ebobPayPayda;
	return res;
}
kesir kesir::operator*(  kesir  x)
{
	kesir res;
	res.payda = this->payda*x.payda;
	res.pay = this->pay*x.pay;
											//0*inf ?
	if (res.pay==0 )
	{
		res.payda = 1;
		return res;
	}
	long long ebobPayPayda = ebob(abs(res.pay), res.payda);
	res.pay /= ebobPayPayda;
	res.payda /= ebobPayPayda;
	return res;
}
kesir kesir::operator/(  kesir  x)
{
	kesir res;
	res.payda = this->payda*x.pay;
	res.pay = this->pay*x.payda;
															//0*inf ?
	if (res.pay == 0 && res.payda == 0)
	{
		throw "Sifira Bolme Hatasi!";
	}
	else if (res.payda == 0)
	{
		res.pay = LLONG_MAX;
		res.payda = 1;
		return res;
	}
	else if (res.pay == 0)
	{
		res.pay = 0;
		res.payda = 1;
		return res;
	}
	long long ebobPayPayda = ebob(abs(res.pay), abs(res.payda));
	res.pay /= ebobPayPayda;
	res.payda /= ebobPayPayda;
	if(res.payda<0)
	{
		res.pay = -res.pay;
		res.payda = -res.payda;
	}
	return res;
}
void kesir::operator+=(  kesir  x)
{
	*this = *this + x;
}
void kesir::operator-=(  kesir  x)
{
	*this = *this - x;
}
void kesir::operator*=(  kesir  x)
{
	*this = *this*x;
}
void kesir::operator/=(  kesir  x)
{
	*this = *this / x;
}
kesir  kesir::operator++()
{
	this->pay += this->payda;
	if (pay==0)
	{
		this->payda = 1;
	}
	return *this;
}
kesir  kesir::operator--()
{
	this->pay -= this->payda;
	if (pay==0)
	{
		this->payda = 1;
	}
	return *this;
}
kesir kesir::operator++(int)
{
	this->pay += this->payda;
	if (pay==0)
	{
		this->payda = 1;
	}
	return *this;
}
kesir kesir::operator--(int)
{
	this->pay -= this->payda;
	if (pay==0)
	{
		this->payda = 1;
	}
	return *this;
}
kesir kesir::operator+(long long x)
{
	kesir res;
	res.payda = this->payda;
	res.pay = this->pay + x * this->payda;
	if (res.pay == 0 )
	{
		res.payda = 1;
		return res;
	}
	long long ebobPayPayda = ebob(abs(res.pay), res.payda);
	res.pay /= ebobPayPayda;
	res.payda /= ebobPayPayda;
	return res;
}
kesir kesir::operator-(  long long  x)
{
	kesir res;
	res.payda = this->payda;
	res.pay = this->pay - this->payda*x;
	if (res.pay == 0)
	{
		res.payda = 1;
		return res;
	}

	long long ebobPayPayda = ebob(abs(res.pay), res.payda);
	res.pay/=ebobPayPayda;
	res.payda /= ebobPayPayda;
	return res;
}
kesir kesir::operator*(  long long  x)
{
	kesir res;
	res.pay = this->pay*x;
	res.payda = this->payda;
	if (res.pay == 0)
	{
		res.payda = 1;
		return res;
	}
	long long ebobPayPayda = ebob(res.payda, abs(res.pay));
	res.pay /= ebobPayPayda;
	res.payda /= ebobPayPayda;
	return res;
}
kesir kesir::operator/(  long long  x)
{
	kesir res;
	if(this->pay==0||x==0)
	{
		res.payda = 1;
		return res;
	}
	long long ebobPayX = ebob(this->pay, abs(x));
	res.pay = this->pay / ebobPayX;
	res.payda = this->payda*x / ebobPayX;
	if(res.payda<0)
	{
		res.pay = -res.pay;
		res.payda = -res.payda;
	}
	return res;
}
void kesir::operator+=(  long long  x)
{
	*this = *this + x;
}
void kesir::operator-=(  long long  x)
{
	*this = *this - x;
}
void kesir::operator*=(  long long  x)
{
	*this = *this*x;
}
void kesir::operator/=(  long long  x)
{
	*this = *this / x;
}
kesir kesir::operator+(double x)
{
	return *this + dtokesir(x);
}
kesir kesir::operator-(  double  x)
{
	return *this - dtokesir(x);
}
kesir kesir::operator*(  double  x)
{
	return *this * dtokesir(x);
}
kesir kesir::operator/(  double  x)
{
	return *this / dtokesir(x);
}
void kesir::operator+=(  double  x)
{
	*this = *this + dtokesir(x);
}
void kesir::operator-=(  double  x)
{
	*this = *this - dtokesir(x);
}
void kesir::operator*=(  double  x)
{
	*this = *this*dtokesir(x);
}
void kesir::operator/=(  double  x)
{
	*this = *this / dtokesir(x);
}
bool kesir::operator<(  kesir  x)
{
	long long ekokPaydalar = ekok(this->payda, x.payda);
	return this->pay*ekokPaydalar / this->payda < x.pay*ekokPaydalar / x.payda;
}
bool kesir::operator>(  kesir  x)
{
	long long ekokPaydalar = ekok(this->payda, x.payda);
	return this->pay*ekokPaydalar / this->payda > x.pay*ekokPaydalar / x.payda;
}
bool kesir::operator>=(  kesir  x)
{
	long long ekokPaydalar = ekok(this->payda, x.payda);
	return this->pay*ekokPaydalar / this->payda >= x.pay*ekokPaydalar / x.payda;
}
bool kesir::operator<=(  kesir  x)
{
	long long ekokPaydalar = ekok(this->payda, x.payda);
	return this->pay*ekokPaydalar / this->payda <= x.pay*ekokPaydalar / x.payda;
}
bool kesir::operator==(  kesir  x)
{
	long long ekokPaydalar = ekok(this->payda, x.payda);
	return this->pay*ekokPaydalar / this->payda == x.pay*ekokPaydalar / x.payda;
}
bool kesir::operator!=(  kesir  x)
{
	long long ekokPaydalar = ekok(this->payda, x.payda);
	return this->pay*ekokPaydalar / this->payda != x.pay*ekokPaydalar / x.payda;
}
bool kesir::operator<(  long long  x)
{
	return pay < this->payda*x;
}
bool kesir::operator>(  long long  x)
{
	return pay > this->payda*x;
}
bool kesir::operator>=(  long long  x)
{
	return pay >= this->payda*x;
}
bool kesir::operator<=(  long long  x)
{
	return pay <= this->payda*x;
}
bool kesir::operator==(  long long  x)
{
	return pay == this->payda*x;
}
bool kesir::operator!=(  long long  x)
{
	return pay != this->payda*x;
}
bool kesir::operator<(  double  x)
{
	return *this < dtokesir(x);
}
bool kesir::operator>(  double  x)
{
	return *this > dtokesir(x);
}
bool kesir::operator>=(  double   x)
{
	return *this >= dtokesir(x);
}
bool kesir::operator<=(  double  x) 
{
	return *this <= dtokesir(x);
}
bool kesir::operator==(  double  x)
{
	return *this == dtokesir(x);
}
bool kesir::operator!=(  double  x)
{
	return *this != dtokesir(x);
}

kesir operator+(int i, kesir x)
{
	return x.operator+(i);
}
kesir operator-(int i, kesir x)
{
	return x.operator-(i);
}
kesir operator*(int i, kesir x)
{
	return x.operator*(i);
}
kesir operator/(int i, kesir x)
{
	return x.operator/(i);
}
bool operator<(int i, kesir x)
{
	return x.operator<(i);
}
bool operator>(int i, kesir x)
{
	return x.operator>(i);
}
bool operator<=(int i, kesir x)
{
	return x.operator<=(i);
}
bool operator>=(int i, kesir x)
{
	return x.operator>=
		(i);
}
bool operator==(int i, kesir x)
{
	return x.operator==(i);
}
bool operator!=(int i, kesir x)
{
	return x.operator!=(i);
}


kesir operator+(long long i, kesir x)
{
	return x.operator+(i);
}
kesir operator-(long long i, kesir x)
{
	return x.operator-(i);
}
kesir operator*(long long i, kesir x)
{
	return x.operator*(i);
}
kesir operator/(long long i, kesir x)
{
	return x.operator/(i);
}
bool operator<(long long i, kesir x)
{
	return x.operator<(i);
}
bool operator>(long long i, kesir x)
{
	return x.operator>(i);
}
bool operator<=(long long i, kesir x)
{
	return x.operator<=(i);
}
bool operator>=(long long i, kesir x)
{
	return x.operator>=
		(i);
}
bool operator==(long long i, kesir x)
{
	return x.operator==(i);
}
bool operator!=(long long i, kesir x)
{
	return x.operator!=(i);
}


kesir operator+(double i, kesir x)
{
	return x.operator+(i);
}
kesir operator-(double i, kesir x)
{
	return x.operator-(i);
}
kesir operator*(double i, kesir x)
{
	return x.operator*(i);
}
kesir operator/(double i, kesir x)
{
	return x.operator/(i);
}
bool operator<(double i, kesir x)
{
	return x.operator<(i);
}
bool operator>(double i, kesir x)
{
	return x.operator>(i);
}
bool operator<=(double i, kesir x)
{
	return x.operator<=(i);
}
bool operator>=(double i, kesir x)
{
	return x.operator>=
		(i);
}
bool operator==(double i, kesir x)
{
	return x.operator==(i);
}
bool operator!=(double i, kesir x)
{
	return x.operator!=(i);
}