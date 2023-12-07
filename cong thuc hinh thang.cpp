#include<iostream>
#include<cmath>
#include<vector>

using namespace std;

double dao_ham2(vector<double> pt,int n,double a) {
	double fdh;
	int k=0;
	for(int i=n;i>=2;i--) {
		if(i==2) fdh += 2*pt[k];
		else if (i!=2) fdh += i*(i-1)*pt[k]*pow(a,i-2);
		k++;
	}
	return fdh;
}

double tim_max(double a,double b, int bac,vector<double> pt) {
    double max,x,temp;
    x=a;
    while(x<b) {
        temp=dao_ham2(pt,bac,x);
        if(max<temp) {
            max = temp;
        }
        x+=0.01;
    }
    temp=dao_ham2(pt,bac,b);
    if(max<temp) {
        max = temp;
    }
    return max;
}

double tinh_fx(double x, double bien, vector<double> pt, int bac) {
    double fx=0;
	int k=0;
    for(int i=bac;i>=1;i--) {
        fx += pt[k] * pow(x,i);
        k++;
    }
    fx+=bien;
    return fx;
}

int main() {
    int bac;
    double n,bien,temp,h,a,b,x,dap_an,max,sai_so;
    vector<double> pt,bang;
    cout << "nhap bac cua pt: ";
    cin >> bac;
    cout << "nhap he so phuong trinh: ";
    for(int i=0;i<bac;i++) {
        cin >> temp;
        pt.push_back(temp);
    }
    cout << "nhap he so con lai: ";
    cin >> bien;
    cout << "nhap can tich phan: ";
    cin >> a >> b;
    cout << "nhap so doan duoc chia: ";
    cin >> n;
    h=(b-a)/n;
    x=a;
    while(x<b) {
        bang.push_back(tinh_fx(x,bien,pt,bac));
        x+=h;
    }
        bang.push_back(tinh_fx(x,bien,pt,bac));
    temp=a;
    cout << "x\ty" << endl;
    for(int i=0;i<bang.size();i++) {
        cout << temp << "\t" << bang[i] << endl;
        temp+=h;
    }
    dap_an = ((bang[0]+bang[bang.size()-1])/2);
    for(int i=1;i<bang.size()-1;i++) {
        dap_an+=bang[i];
    }
    max=tim_max(a,b,bac,pt);
    dap_an*=h;
    sai_so=(max*(b-a)*pow(h,2))/12;
    cout << "dap an: " << dap_an << endl;
    cout << "sai so: " << sai_so;
}
