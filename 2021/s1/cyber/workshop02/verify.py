p = int("00DD454679C3CA4C77",16)
q = int("00C611776FD9A7A249", 16)
n = int("00AB32AD57BC713D952BE8D30099B41BEF", 16)
e = int("010001",16)
d = int("76B72FA9358DB94B835AF9B0F4C0D721", 16)

# Verify n = p*q
print "[n]:" + str(n) + " [p*q]: " + str(p*q)

# verify e*d mod{(p-1)*(q-1)} = 1
print "[e*d mod{(p-1)*(q-1)}]: " + str((e*d)%((p-1)*(q-1)))
