#include <bits/stdc++.h>
using namespace std;
#define eps 0.000001
#define N 10000
double volp;
double n,s;
double r[N], x[N], y[N], z[N], vols[N], sumv;

double find (double val) {
	double ret = 10000*val;
	for (int i = 0; i < n; i++) {
		double le = z[i] - r[i];
		double re = z[i] + r[i];
		if (val >= re) {
			ret -= vols[i];
		}
		else if (val >= le) {
			double v = (val-z[i]+r[i]);
			double t = r[i]*r[i]*v;
			t -= (r[i]*r[i]*r[i] - (z[i]-val)*(z[i]-val)*(z[i]-val))/3; 
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


int main () {
	scanf("%lf %lf", &n, &s);
	for (int i = 0; i < n; i++) {
		scanf("%lf %lf %lf %lf",&r[i],&x[i],&y[i],&z[i]);
		r[i] /= 1000;
		x[i] /= 1000;
		y[i] /= 1000;
		z[i] /= 1000;
		vols[i] = (4*M_PI*r[i]*r[i]*r[i])/3;
		sumv += vols[i];
	}
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