// ConsoleApplication17.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
using namespace std;

class wrt {
public:
	double a, b, c, result;
	wrt() {
		a = 0;
		b = 0;
		c = 0;
		result = 0;
	}
	wrt(double aa, double bb, double cc, double res) {
		a = aa;
		b = bb;
		c = cc;
		result = res;
	}
	void add(double aa, double bb, double cc, double res) {
		a = aa;
		b = bb;
		c = cc;
		result = res;
	}
	void print() {
		cout << endl << a << "a+" << b << "b+" << c << "c" << "=" << result << endl;
	}
	double*  pint(){
		double mm[3] = { a, b, c };
		return mm;
	}
	wrt operator /(double pp) {
		wrt bi(a, b, c, result);
		bi.a /= pp;
		bi.b /= pp;
		bi.c /= pp;
		bi.result /= pp;
		return bi;
	}
	wrt operator /(wrt pp) {
		wrt bi(a, b, c, result);
		bi.a /= pp.a;
		bi.b /= pp.b;
		bi.c /= pp.c;
		bi.result /= pp.result;
		return bi;
	}
	wrt operator *(double pp) {
		wrt bi(a, b, c, result);
		bi.a *= pp;
		bi.b *= pp;
		bi.c *= pp;
		bi.result *= pp;
		return bi;
	}
	wrt operator -(wrt pp) {
		wrt bi(a, b, c, result);
		bi.a -= pp.a;
		bi.b -= pp.b;
		bi.c -= pp.c;
		bi.result -= pp.result;
		return bi;
	}
};
double kramer_delta(wrt mp[3], int a) {
	wrt m[3] = {mp[0], mp[1], mp[2]};
	if (a == 1) {
		m[0].a = m[0].result;
		m[1].a = m[1].result;
		m[2].a = m[2].result;
	}
	if (a == 2) {
		m[0].b = m[0].result;
		m[1].b = m[1].result;
		m[2].b = m[2].result;
	}
	if (a == 3) {
		m[0].c = m[0].result;
		m[1].c = m[1].result;
		m[2].c = m[2].result;
	}
	double rs = (m[0].a*m[1].b*m[2].c) + (m[0].b*m[1].c*m[2].a) + (m[0].c*m[1].a*m[2].b)
		- (m[0].c*m[1].b*m[2].a) - (m[0].a*m[1].c*m[2].b) - (m[0].b*m[1].a*m[2].c);
	return rs;
}
void kramer(wrt mp[3]) {
	double delta=kramer_delta(mp, 0);
	double delta1 = kramer_delta(mp, 1);
	double delta2 = kramer_delta(mp, 2);
	double delta3 = kramer_delta(mp, 3);
	cout << endl << "Kramer";
	cout << endl << "a=" << delta1 / delta;
	cout << endl << "b=" << delta2 / delta;
	cout << endl << "c=" << delta3 / delta;
}

void gaus(wrt mp[3]) {
	wrt m[3] = { mp[0], mp[1], mp[2] };
	m[0]=m[0] / m[0].a;
	m[1] = m[1] - (m[0] * m[1].a);
	m[2] = m[2] - (m[0] * m[2].a);
	m[1] = m[1] / m[1].b;
	m[0] = m[0] - (m[1] * m[0].b);
	m[2] = m[2] - (m[1] * m[2].b);
	m[2] = m[2] / m[2].c;
	m[0] = m[0] - (m[2] * m[0].c);
	m[1] = m[1] - (m[2] * m[1].c);
	cout << endl << "Gaus";
	cout << endl << "a=" << m[0].result;
	cout << endl << "b=" << m[1].result;
	cout << endl << "c=" << m[2].result;

}

void lu(wrt mp[3]) {
	wrt b[3];
	for (int i = 0; i < 3; i++) {
		b[i].a = mp[i].a;
	}
	wrt c[3];
	c[0].a = mp[0].a / mp[0].a;
	c[0].b = mp[0].b / mp[0].a;
	c[0].c = mp[0].c / mp[0].a;
	b[1].b = mp[1].b - c[0].a*c[0].b;
	c[1].b = (mp[2].c + c[0].c) / b[1].b;
	c[1].c = (mp[2].b + c[0].b) / b[1].b;
	b[2].b = mp[2].b - (b[2].a*c[0].b);
	b[2].c = mp[2].c - ((b[2].a*c[0].c) + (b[2].b*c[1].c));
	c[2].c = b[2].c / b[2].c;
	double y1, y2, y3, au, bu, cu;
	y1 = mp[0].result / b[0].a;
	y2 = (mp[1].result - b[1].a*y1) / b[1].b;
	y3 = (mp[2].result - b[2].a*y1 - b[2].b*y2) / b[2].c;

	cu= y3;
	bu= y2 - (c[1].c*y3);
	au= y1 - ((c[0].b*bu) + (c[0].c*y3));
	cout << endl << "Method LU" << endl;
	cout << "a=" << au<<endl;
	cout << "b=" << bu << endl;
	cout << "c=" << cu << endl;
	
	}
int main() {
	wrt ex[3];
	ex[0].add(3, 2, 1, 360);
	ex[1].add(1, 6, 2, 300);
	ex[2].add(4, 1, 5, 675);
	ex[0].print();
	ex[1].print();
	ex[2].print();
	kramer(ex);
	gaus(ex);
	lu(ex);
}

