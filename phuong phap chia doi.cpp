#include<iostream>
#include<cmath>

using namespace std;


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
double sai_so(double a, double b,int count) {
        return (b-a)/(pow(2, count+1));
    }

int main() {
	double a,b,c,d,bien,fa,fb,x,fx,fdh,x1,saiso;
	double saisotest=100000;
	int n;
	int count =0;
	int buoc = 0;
	double pt[50];
	printf("nhap bac phuong trinh: ");
	scanf("%d", &n);
	printf("nhap he so phuong trinh: ");
	for(int i=0;i<n;i++) {
		scanf("%lf", &d);
		pt[i]=d;
	}
	printf("nhap nhap he so con lai: ");
	scanf("%lf", &bien);
	printf("nhap khoang cach ly nghiem: ");
	scanf("%lf%lf",&a,&b);
	if(tinh_fx(a, bien, pt, n)*tinh_fx(b, bien, pt, n)>0 ||  dao_ham1(pt, n, a)<0 && dao_ham1(pt, n, b)>0 || dao_ham1(pt, n, a)>0 && dao_ham1(pt, n, b)<0) {
            printf("khoang cach ly nghiem khong thoa man");
            exit(-1);
        }
		printf("nhap sai so: ");
		scanf("%lf",&saiso);
	fa=tinh_fx(a,bien,pt,n);
    fb=tinh_fx(b,bien,pt,n);
    saisotest = sai_so(a, b,count);
    double a1 =a;
    double b1 =b;
    while(saisotest>saiso) {
    	c = (a+b)/2;
    	double test=bien;
        int k=0;
        for(int i=n;i>=1;i--) {
            test += pt[k] * pow(c,i);
            k++;
        }
    	if(test*tinh_fx(a,bien,pt,n)>0) {
			buoc++;
    		count++;
			printf("buoc %d x = %lf\n", buoc, c);
    		a=c;
		}
		else if(test*tinh_fx(a,bien,pt,n)<0) {
            count++;
			buoc++;
			printf("buoc %d x = %lf\n", buoc, c);
            b=c;
        }
        saisotest=sai_so(a1,b1,count);
	}
	printf("nghiem: %lf\n", c);
    printf("sai so: %lf", saisotest);
}
