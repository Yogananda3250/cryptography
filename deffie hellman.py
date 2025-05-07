import random

def diffie_hellman(p, g):
    a, b = random.randint(1, p-1), random.randint(1, p-1)
    A, B = pow(g, a, p), pow(g, b, p)
    return pow(B, a, p), A, B

def encrypt_decrypt(msg, key):
    return ''.join(chr(ord(c) ^ key) for c in msg)

def main():
    p, g = 23, 5
    shared_key, A, B = diffie_hellman(p, g)
    print(f"Public Parameters: p={p}, g={g}\nAlice's Public Key: {A}\nBob's Public Key: {B}")
    print(f"Shared Secret Key: {shared_key}")
    
    choice = input("Enter 1 to Encrypt or 2 to Decrypt: ")
    if choice == '1':
        msg = input("Enter message to encrypt: ")
        print(f"Encrypted: {encrypt_decrypt(msg, shared_key)}")
    elif choice == '2':
        msg = input("Enter message to decrypt: ")
        print(f"Decrypted: {encrypt_decrypt(msg, shared_key)}")
    else:
        print("Invalid choice.")

if __name__ == "__main__":
    main()
