#Name : Aniruddha Shende
#Roll No : PE04
#Batch : E1
#Panel : E

from decimal import Decimal 
  
def gcd(m,n): 
    if n==0: 
        return m 
    else: 
        return gcd(n,m%n) 

#input variables
print("")
p=int(input("Enter 1st prime number : "))
if p > 1:
    for i in range(2, int(p/2)+1):
        if (p % i) == 0:
            print(p, "is not a prime number")
            quit()

q=int(input("Enter 2nd prime number : "))
if q > 1:
    for i in range(2, int(q/2)+1):
        if (q % i) == 0:
            print(q, "is not a prime number")
            quit()
no = int(input(("Input : ")))

#calculate n
n = (p*q) 

#calculate phiN
phiN = (p-1)*(q-1) 

#calculate K
for k in range(2,phiN): 
    if gcd(k,phiN)== 1: 
        break
  
for i in range(1,10): 
    x = 1 + i*phiN 
    if x % k == 0: 
        d = int(x/k) 
        break

local_cipher = Decimal(0) 
local_cipher =pow(no,k) 
ct = local_cipher % n 

decrypt_t = Decimal(0) 
decrypt_t= pow(ct,d) 
dt = decrypt_t % n 

print('e = '+str(k))
print('d = '+str(d)) 
print('Cipher text = '+str(ct))
print('Decrypted text = '+str(dt))
