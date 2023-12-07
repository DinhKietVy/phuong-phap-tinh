#include<iostream>
#include<cmath>
#include<vector>

using namespace std;

int main() {
    int n;
    vector<double> x,y,ty_hieu1,ty_hieu2,pt;
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
    for(int i=0;i<n-1;i++) {
        ty_hieu1.push_back((y[i+1]-y[i])/(x[i+1]-x[i]));
    }
    pt.push_back(ty_hieu1[0]);
    cout << "ty hieu cap 1: ";
    for(int i=0;i<ty_hieu1.size();i++) {
        cout << ty_hieu1[i] << " ";
    }
    cout << endl;
    int count = 2;
    while(count<n) {
        ty_hieu2.clear();
        for(int i=0;i<ty_hieu1.size();i++) {
            ty_hieu2.push_back(ty_hieu1[i]);
        }
        ty_hieu1.clear();
        for(int i=0;i<ty_hieu2.size()-1;i++) {
            ty_hieu1.push_back((ty_hieu2[i+1]-ty_hieu2[i])/(x[i+count]-x[i]));
        }
        pt.push_back(ty_hieu1[0]);
        cout << "ty hieu cap " << count << ": ";
        for(int i=0;i<ty_hieu1.size();i++) {
        cout << ty_hieu1[i] << " ";
    }
    cout << endl;
        count++;
    }
    cout << "nhap gia tri gan dung: ";
    cin >> x_gandung;
    no=y[0];
    int j=1;
    for(int i=0;i<pt.size();i++) {
        double temp=1;
        count = 0;
        while(count < j) {
            temp*=(x_gandung-x[count]);
            count++;
        }
        j++;
        no+=temp*pt[i];
    }
    cout << "nghiem: " << no;
}