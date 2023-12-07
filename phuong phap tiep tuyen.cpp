#include<iostream>
#include<cmath>

using namespace std;

double dao_ham2(double pt[],int n,double a) {
	double fdh;
	int k=0;
	for(int i=n;i>=2;i--) {
		if(i==2) fdh += 2*pt[k];
		else if (i!=2) fdh += i*(i-1)*pt[k]*pow(a,i-2);
		k++;
	}
	return fdh;
}

double dao_ham1(double pt[],int n,double a) {
	double fdh=0;
	int k=0;
	for(int i=n;i>=1;i--) {
		if(i==1) fdh += pt[k];
		else if (i!=1) fdh += i*pt[k]*pow(a,i-1);
		k++;
	}
	return fdh;
}

double tinh_fx(double x, double bien, double pt[], int n) {
	double fx=0;
	int k=0;
        for(int i=n;i>=1;i--) {
            fx +=pt[k] * pow(x, i);
            k++;
        }
        fx+=bien;
        return fx;
}

double sai_so(double x1, double x2,double bien, double pt[], int n,double a, double b) {
	double ss;
	double m_lon = max(dao_ham1(pt,n,a),dao_ham1(pt,n,b));
	double m_nho = min(dao_ham1(pt,n,a),dao_ham1(pt,n,b));
	if((dao_ham1(pt,n,a)*dao_ham1(pt,n,b)>0) && m_nho >= 0,dao_ham2(pt,n,a)<m_lon) {
		ss = abs(tinh_fx(x2,bien,pt,n))/m_nho;
	}
	else {
		ss = abs(tinh_fx(x2,bien,pt,n))/m_nho;
	}
	return ss;
}

int main() {
	double a,b,c,bien,fa,fb,x,fx,fdh,x1,saiso,chon;
	double saisotest=100000;
	int n;
	double pt[50];
	int count=0;
	printf("nhap bac phuong trinh: ");
	scanf("%d", &n);
	printf("nhap he so phuong trinh: ");
	for(int i=0;i<n;i++) {
		scanf("%lf", &c);
		pt[i]=c;
	}
	printf("nhap he so con lai: ");
	scanf("%lf", &bien);
	printf("nhap khoang cach ly nghiem: ");
	scanf("%lf%lf",&a,&b);
	if(tinh_fx(a, bien, pt, n)*tinh_fx(b, bien, pt, n)>0 ||  dao_ham1(pt, n, a)<0 && dao_ham1(pt, n, b)>0 || dao_ham1(pt, n, a)>0 && dao_ham1(pt, n, b)<0 || a>b) {
            printf("khoang cach ly nghiem khong thoa man");
            exit(-1);
        }
		printf("nhap sai so: ");
		scanf("%lf",&saiso);
	fa=tinh_fx(a,bien,pt,n);
    fb=tinh_fx(b,bien,pt,n);
    if((dao_ham2(pt,n,a)<0 && dao_ham2(pt,n,b)>0) || (dao_ham2(pt,n,a)>0 && dao_ham2(pt,n,b)<0)) {
        	printf("phuong trinh khong lien tuc");
        	exit(-1);
		}
	fdh=dao_ham2(pt,n,a);
        if(fa*fdh>0) {
			x = a;
            while(saiso<saisotest) {
				x1=x;
				x = x - ((tinh_fx(x, bien, pt, n))/(dao_ham1(pt,n,x)));
				count++;
				printf("buoc %d x= %lf\n",count, x);
				saisotest= abs(sai_so(x1,x,bien,pt,n,a,b));
			}
        }
        else if(fb*fdh>0) {
            x = b;
            while(saiso<saisotest) {
				x1=x;
				x = x - ((tinh_fx(x, bien, pt, n))/(dao_ham1(pt,n,x)));
				count++;
				printf("buoc %d x= %lf\n",count, x);
				saisotest= abs(sai_so(x1,x,bien,pt,n,a,b));
			}
    }
    printf("nghiem: %lf\n", x);
    printf("sai so: %lf", saisotest);
}
