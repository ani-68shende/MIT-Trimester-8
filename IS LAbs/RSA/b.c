#include <stdio.h>
#include <math.h>

int gcd(int x, int y) {
    if(y == 0) return x;
    else return gcd(y, fmod(x, y));
}

int main() {
    int p,q,n,phiN,e = 2;
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
    int  Message;double Decrypted_Message;
    printf("Enter the message: ");
    scanf("%lf",&Message);
    int C,d;
    printf("The value of e is: %lf\n",e);
    d = (int)(2 * phiN + 1) / e;
    printf("The value of d:  %lf\n",d);
    C = fmod(pow(Message,e),n);
    printf("Encrypted Message is: %lf\n",C);
    Decrypted_Message = pow(C,d)%n;
    printf("Decrypted Message is: %lf",Decrypted_Message);
    return 0;
}
