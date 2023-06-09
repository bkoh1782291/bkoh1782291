import binascii

# convert string to integer using
def string_to_int(string):
    return int.from_bytes(binascii.a2b_qp(string),byteorder='big')

# convert into back to string
def int_to_string(number):
    bin = number.to_bytes((number.bit_length() + 7) // 8, byteorder='big')
    return binascii.b2a_qp(bin).decode("utf-8")
