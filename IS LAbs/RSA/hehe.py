#RSA algo
#2 prime no. p,q
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

print('Prime numbers are : ',p,q)
all=('a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','54')

# n=p*q
n=p*q

# φ(n)=(p-1)*(q-1) It counts the number of positive integers less than or equal to n that have at least one prime factor in common with n.
def φ(n):
	return (p-1)*(q-1)
T=φ(n)

#generate 2 keys- public and private
#public e , 1<e<φ(n)
e=0
for i in range(T-1,0,-1):
	if T % i:
		e=i
		break
print('e is : ',e)

#private d , d*e%φ(n)=1
for i in range(1,1000):
	if i*e%T==1:
		d=i
		break
print('d is : ',d)

#plain text to cipher text 
pt=input("Enter Plain Text : ")
pt=pt.lower()

#C=M^e mod n
c1=list(pt)
for i in range(len(c1)):
	if c1[i]==' ':
		pass
	else:
		c1[i]=all.index(c1[i])+1

for i in range(len(c1)):
	if c1[i]==' ':
		pass
	else:
		c1[i]=(c1[i]**e)%n
print("Encrypted List : ",c1)

#cipher to plain 
#P=C^d mod n
for i in range(len(c1)):
	if c1[i]==' ':
		pass
	else:
		c1[i]=(c1[i]**d)%n
print("Decrypted List : ",c1)

#converting back to string
for i in range(len(c1)):
	if c1[i]==' ':
		pass
	else:
		c1[i]=all[c1[i]-1]

c2=''
for i in c1:
	c2+=i
print("Decrypted Text : ",c2)










#'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T',"U",'V','W','X','Y','Z')