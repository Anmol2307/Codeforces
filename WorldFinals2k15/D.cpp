#include <bits/stdc++.h>
using namespace std;
#define eps 0.000001
#define N 10000
double volp;
double n,s;
vector<pair<double,double> > pa;
double x, y, vols[N], sumv;

double find (double val) {
	double ret = 10000*val;
	for (int i = 0; i < n; i++) {
		if (val < (pa[i].second-pa[i].first)) break;
		double le = pa[i].second - pa[i].first;
		double re = pa[i].second + pa[i].first;
		if (val >= re) {
			ret -= vols[i];
		}
		else if (val >= le) {
			double rad = pa[i].first;
			double zz = pa[i].second - val;
			double v = (rad-zz);
			double t = rad*rad*v;
			t -= (rad*rad*rad - zz*zz*zz)/3; 
			t *= M_PI;
			// printf("%lf %lf\n",ret,t);
			ret -= t;
		}
	}
	return ret;
}

double findvol (double l, double r) {
	// printf("%lf %lf\n",find(l), find(r));
	return find(r) - find(l);
}

double binary_search(double low) {
	double high = 100;
	double target = volp;
	while (1) {
		double mid = low + (high-low)/2;
		double tmp = findvol(low,mid);
		// printf("%lf %lf %lf %lf %lf\n",tmp,target,low,mid,high);
		// exit(0);
		if (abs(tmp-target) < eps) {
			return mid;
		}
		else if (tmp > target) {
			high = mid;
		}
		else if (tmp < target) {
			low = mid;
			target -= tmp;
		}
	}
}

bool pairCompare(const pair<double, double>& firstElem, const pair<double, double>& secondElem) {
  return (secondElem.second - secondElem.first) > (firstElem.second - firstElem.first);
}


int main () {
	scanf("%lf %lf", &n, &s);
	for (int i = 0; i < n; i++) {
		pair<double,double> p;
		scanf("%lf %lf %lf %lf",&p.first,&x,&y,&p.second);
		p.first /= 1000;
		p.second /= 1000;
		double rad = p.first;
		vols[i] = (4*M_PI*rad*rad*rad)/3;
		sumv += vols[i];
		pa.push_back(p);
	}
	sort(pa.begin(),pa.end(),pairCompare);
	volp = (1000000 - sumv)/s;
	// printf("%lf %lf\n",volp,M_PI);
	// printf("%lf\n",findvol(0,14.611103142));
	// exit(0);
	double low = 0;
	double end;
	for (int i = 0; i < s; i++) {
		end = binary_search(low);
		printf("%.9lf\n",end-low);
		// exit(0);
		low = end;
	}
}