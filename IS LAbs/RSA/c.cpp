#include <bits/stdc++.h>
using namespace std;

int main()
{
    double p, q, n, phiN, e = 2;
    printf("Enter the value for p: ");
    scanf("%lf", &p);
    printf("Enter the value for q: ");
    scanf("%lf", &q);
    n = p * q;
    phiN = (p - 1) * (q - 1);
    e = phiN;
    while (e > 1)
    {
        if (__gcd(e, phiN) == 1)
        {
            break;
        }
        else
            e--;
    }
    double Message;
    double Decrypted_Message;
    printf("Enter the message: ");
    scanf("%lf", &Message);
    double C, d;
    printf("The value of e is: %lf\n", e);
    d = (double)(2 * phiN + 1) / e;
    printf("The value of d:  %lf\n", d);
    C = fmod(pow(Message, e), n);
    printf("Encrypted Message is: %lf\n", C);
    Decrypted_Message = fmod(pow(C, d), n);
    printf("Decrypted Message is: %lf", Decrypted_Message);
    return 0;
}
