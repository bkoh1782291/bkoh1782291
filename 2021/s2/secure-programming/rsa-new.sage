p=random_prime(2^512,None,2^511+2^510)
q=random_prime(2^512,None,2^511+2^510)
n=p*q
phi=(p-1)*(q-1)
e=65537
d=Integer(mod(xgcd(e,phi)[1], phi))

print("p="+hex(p)[2:])
print("q="+hex(q)[2:])
print("n="+hex(n)[2:])
print("e="+hex(e)[2:])
print("d="+hex(d)[2:])
