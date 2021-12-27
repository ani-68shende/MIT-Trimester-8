#include <stdio.h>
#include <math.h>

double gcd(double x, double y) {
    if(y == 0) return x;
    else return gcd(y, fmod(x, y));
}

int main() {
    double p,q,n,phiN,e = 2;
    printf("Enter the value for p: ");
    scanf("%lf",&p);
    printf("Enter the value for q: ");
    scanf("%lf",&q);
    n = p * q;
    phiN = (p - 1) * (q - 1);
    while (e < phiN) {
        if(gcd(e,phiN) == 1) {
            break;
        }
        else
            e++;
    }
    double  Message, Decrypted_Message;
    printf("Enter the message: ");
    scanf("%lf",&Message);
    double C,d;
    printf("The value of e is: %lf\n",e);
    //d = (double)(2 * phiN + 1) / e;
    for(int i = 0 ; i < 10 ; i++){
        double temp = 1+i*phiN;
        if(fmod(temp,e) == 0.0){
            d = (double)(temp/e);
            break;
        }
    }
    printf("The value of d:  %lf\n",d);
    C = fmod(pow(Message,e),n);
    printf("Encrypted Message is: %lf\n",C);
    Decrypted_Message =(double)(fmod(pow(C,d),n));
    printf("Decrypted Message is: %lf",Decrypted_Message);
    return 0;
}
