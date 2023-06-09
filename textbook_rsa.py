#!/usr/bin/env python3

import time
import string

import os
import os.path
import filecmp

from Crypto.PublicKey import RSA

pkfile = 'rsa_key.pub'
skfile = 'rsa_key'

def rsa_keygen():
	key = RSA.generate(4096);

	with open(skfile,'wb') as f:
		f.write(key.exportKey('PEM'))

	pk = key.publickey()

	with open(pkfile, 'wb') as f:
		f.write(pk.exportKey('PEM'))

def rsa_encrypt(fname):
	with open(pkfile, 'rb') as f:
		sk = RSA.importKey(f.read(), 'PEM');
	
	with open(fname, 'r') as f:
		pt = f.read()
		if len(pt) > 128:
			pt = pt[:128]
		pt = pt.encode('ascii')

	ct = sk.encrypt(pt, 0)[0]

	with open(fname+'.enc', 'wb') as f:
		f.write(ct)

def rsa_decrypt(fname):
	with open(skfile, 'rb') as f:
		sk = RSA.importKey(f.read(), 'PEM');
	
	with open(fname+'.enc', 'rb') as f:
		ct = f.read()
	
	pt = sk.decrypt(ct).decode('ascii')
	with open(fname+'.dec', 'w') as f:
		f.write(pt)
	

fname = 'ex3'
rsa_keygen()
rsa_encrypt(fname)
rsa_decrypt(fname)


