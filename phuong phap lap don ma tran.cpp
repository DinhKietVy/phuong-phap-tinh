#include<iostream>
#include<cmath>
#include<vector>

using namespace std;

double chuan_hang(double c[][50],int n) {
    double max, temp;
    for(int i=0;i<n;i++) {
        temp=0;
        for(int j=0;j<n;j++) {
            temp += abs(c[i][j]);
        }
        if(max < temp) {
            max = temp;
        }
    }
    return max;
}

double sai_so(double chuan,vector<double> no,vector<double> temp) {
    double max,tmp;
    for(int i=0;i<no.size();i++) {
        tmp = abs(no[i]-temp[i]);
        if(max<tmp) {
            max=tmp;
        }
    }
    double ss=(chuan*max)/(1-chuan);
    return ss;
}

void vong_lap(vector<double> b,vector<double> no, int n,double c[][50],double saiso,double chuan) {
    double saisotest=1000;
    vector<double> temp;
    int count =1;
    temp.resize(n);
    for(int i=0;i<n;i++) {
        no.push_back(b[i]);
    }
    while(saisotest>saiso) {
        for (int i=0; i<no.size(); i++)  {
            temp[i]=no[i];
        }
        for(int k=0;k<n;k++){
                no[k] = b[k];
            }
        for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            no[i] += c[i][j]*temp[j];
        }
    }
    saisotest = sai_so(chuan,no,temp);
    cout << "buoc: " << count << " ";
    count++;
    for(int i=0;i<n;i++) {
        cout  << no[i] << " ";
    }
    cout << endl;
    }
    cout << "nghiem: ";
    for(int i=0;i<n;i++) {
        cout << no[i] << " ";
    }
    cout << "\nsai so: " << saisotest;
}

int main() {
    double a[50][50],c[50][50],saiso,temp,chuan;
    int n;
    vector<double> b,no;
    cout << "nhap do lon ma tran: ";
    cin >> n;
    cout << "nhap ma tran: " << endl;
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            cin >> a[i][j];
        }
    }
    cout << "nhap beta: ";
    for(int i=0;i<n;i++) {
        cin >> temp;
        b.push_back(temp);
    }
    vector<int> check;
    int count,k;
    double test;
    for(int i=0;i<n;i++) {
        test =0;
        count =1;
        for(int j=0;j<n;j++) {
            if(test < abs(a[i][j])) {
                test=abs(a[i][j]);
                k=count;
            }
            count++;
        }
        check.push_back(k);
    }
    count = 1;
    for(int i=0;i<n;i++) {
            if(check[i] != count) {
                cout << "ma tran chua phai ma tran cheo troi" << endl;
                vector<double> temp,temp1;
    int count =1;
    for(int i=0;i<check.size();i++) {
        if(check[i]==count) {
            for(int j=0;j<n;j++) {
                temp.push_back(a[i][j]);
            }
            count++;
            i=-1;
        }
    }
    count =1;
    for(int i=0;i<check.size();i++) {
        if(check[i]==count) {
            temp1.push_back(b[i]);
            count++;
            i=-1;
        }
    }
    int k=0;
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            a[i][j] = temp[k];
            k++;
        }
    }
    k=0;
    for(int i=0;i<n;i++) {
        b[i] = temp1[k];
        k++;
    }
    cout << "ma tran moi: " << endl;
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    cout << "beta moi: " << endl;
    for(int i=0;i<n;i++) {
        cout << b[i] << endl;
    }
                break;
            }
            count++;
    }
    cout << "nhap sai so: ";
    cin >> saiso;
    count = 0;
    for(int i=0;i<n;i++) {
        b[count]/=(a[i][count]);
        for(int j=0;j<n;j++) {
            if(j==count) {
                c[i][j]=0;
            }
            else {
                (a[i][j])/=(a[i][count]);
                c[i][j]=-a[i][j];
            }
        }
        count++;
    }
    chuan = chuan_hang(c,n);
    if(chuan > 1) {
        cout << "khong thoa man dieu kien hoi tu";
        exit(-1);
    }
    vong_lap(b,no,n,c,saiso,chuan);
}