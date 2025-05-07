from Crypto.Cipher import Blowfish
from Crypto.Util.Padding import pad, unpad

def encrypt(msg, key):
    cipher = Blowfish.new(key.encode(), Blowfish.MODE_ECB)
    return cipher.encrypt(pad(msg.encode(), Blowfish.block_size)).hex()

def decrypt(ciphertext, key):
    cipher = Blowfish.new(key.encode(), Blowfish.MODE_ECB)
    raw = cipher.decrypt(bytes.fromhex(ciphertext))
    return unpad(raw, Blowfish.block_size).decode()

def main():
    choice = input("1 = Encrypt, 2 = Decrypt: ")
    key = input("Key (4–56 chars): ")

    if not (4 <= len(key) <= 56):
        print("Key must be 4 to 56 characters long.")
        return

    if choice == '1':
        msg = input("Message: ")
        print("Encrypted:", encrypt(msg, key))
    elif choice == '2':
        ct = input("Ciphertext (hex): ")
        print("Decrypted:", decrypt(ct, key))
    else:
        print("Invalid choice.")

if __name__ == "__main__":
    main()
