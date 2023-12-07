#include<iostream>
#include<cmath>
#include<vector>

using namespace std;

int main() {
    int n;
    double x,m,bien,no;
    vector<double> pt,hoocne;
    cout << "nhap bac cua phuong trinh: ";
    cin >> n;
    cout << "nhap he so phuong trinh: ";
    for(int i=0;i<n;i++) {
		cin >> m;
        pt.push_back(m);
	}
    cout << "nhap he so con lai: ";
    cin >> bien;
    cout << "tinh gia tri cua phuong trinh tai x = ";
    cin >> x;
    for(int i=0;i<n;i++) {
            hoocne.push_back(pt[i]);
    }
        hoocne.push_back(bien);
    for(int i=0;i<n;i++) {
		cout << pt[i] << "\t";
	}
    cout << bien << endl;
    for(int i=0;i<hoocne.size();i++) {
        no = no*x + hoocne[i];
        cout << no << "\t";
    }
    cout << "\nnghiem: " << no;
}