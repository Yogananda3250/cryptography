p, a, b = 17, 2, 2
G = (5, 1)

def inv_mod(k): return pow(k, -1, p)

def point_add(P, Q):
    if P == Q:
        l = (3 * P[0]**2 + a) * inv_mod(2 * P[1]) % p
    else:
        l = (Q[1] - P[1]) * inv_mod(Q[0] - P[0]) % p
    x = (l**2 - P[0] - Q[0]) % p
    y = (l * (P[0] - x) - P[1]) % p
    return (x, y)

def scalar_mult(k, P):
    R = None
    for i in bin(k)[2:]:
        if R: R = point_add(R, R)
        if i == '1': R = P if not R else point_add(R, P)
    return R

def main():
    ch = input("1=Encrypt, 2=Decrypt: ")
    priv = int(input("Enter private key: "))
    pub = scalar_mult(priv, G)
    if ch == '1':
        msg = int(input("Message (int < p): "))
        k = 3
        C1 = scalar_mult(k, G)
        C2 = (msg * scalar_mult(k, pub)[0]) % p
        print("Encrypted:", C1, C2)
    else:
        x, y = eval(input("Enter C1 (x,y): "))
        C2 = int(input("Enter C2: "))
        S = scalar_mult(priv, (x, y))
        print("Decrypted:", (C2 * inv_mod(S[0])) % p)

if __name__ == "__main__": main()
