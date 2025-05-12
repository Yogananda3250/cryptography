import random

def is_prime(n):
    if n <= 1:
        return False
    for i in range(2, int(n**0.5) + 1):
        if n % i == 0:
            return False
    return True

def generate_keys():
    p = int(input("Enter a prime number (p): "))
    while not is_prime(p):
        p = int(input("Not a prime. Enter a prime number (p): "))

    g = int(input("Enter generator (g < p): "))
    x = random.randint(1, p-2)  
    y = pow(g, x, p)            
    print(f"Public Key: (p={p}, g={g}, y={y})")
    print(f"Private Key (keep secret): x={x}")
    return p, g, y, x

def encrypt(p, g, y):
    m = int(input("Enter message (as integer): "))
    k = random.randint(1, p-2)
    a = pow(g, k, p)
    b = (m * pow(y, k, p)) % p
    print(f"Encrypted message: a={a}, b={b}")

def decrypt(p, x):
    a = int(input("Enter 'a' from ciphertext: "))
    b = int(input("Enter 'b' from ciphertext: "))
    s = pow(a, x, p)
    m = (b * pow(s, -1, p)) % p
    print(f"Decrypted message: {m}")

# Main interface
choice = input("Choose (E)ncrypt or (D)ecrypt: ").strip().upper()

if choice == 'E':
    p, g, y, x = generate_keys()
    encrypt(p, g, y)
elif choice == 'D':
    p = int(input("Enter prime p: "))
    x = int(input("Enter private key x: "))
    decrypt(p, x)
else:
    print("Invalid choice.")
