#include<iostream>
#include<cmath>
#include<vector>

using namespace std;

double noi_suy_lagrange(int i,vector<double> x,vector<double> y,double x_gandung,int n) {
    int count=0;
    double no=0;
    while(count<n) {
        if(count!=i) {
            no=(x_gandung-x[count])/(x[i]-x[count]);
            break;
        }
        count++;
    }
    for(int j=0;j<n;j++) {
        if(j!=i && j!= count) {
            no*=(x_gandung-x[j])/(x[i]-x[j]);
        }
    }
    return no;
}

int main() {
    int n;
    vector<double> x,y;
    double k,no,x_gandung;
    cout << "nhap so nut noi suy: ";
    cin >> n;
    cout << "nhap cac gia tri cua x: ";
    for(int i=0;i<n;i++) {
        cin >> k;
        x.push_back(k);
    }
    cout << "nhap cac gia tri cua y: ";
    for(int i=0;i<n;i++) {
        cin >> k;
        y.push_back(k);
    }
    cout << "nhap gia tri gan dung: ";
    cin >> x_gandung;
    for(int i=0;i<n;i++) {
        no+=noi_suy_lagrange(i,x,y,x_gandung,n)*y[i];
    }
    cout << "nghiem: " << no;
}