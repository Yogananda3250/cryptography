def toy_des(x, k):
    left = (x >> 4) & 0xF
    right = x & 0xF
    return ((right << 4) | (left ^ (right ^ k)))

def triple_des_encrypt(p, k1, k2, k3):
    return toy_des(toy_des(toy_des(p, k1), k2), k3)

def triple_des_decrypt(c, k1, k2, k3):
    return toy_des(toy_des(toy_des(c, k3), k2), k1)

def main():
    choice = input("Enter 1 to Encrypt or 2 to Decrypt: ")
    try:
        p = int(input("Enter data (hex, e.g., AB): "), 16)
        k1 = int(input("Enter key 1 (hex): "), 16)
        k2 = int(input("Enter key 2 (hex): "), 16)
        k3 = int(input("Enter key 3 (hex): "), 16)
    except ValueError:
        print("Invalid input. Please enter valid hexadecimal values.")
        return

    if choice == '1':
        e = triple_des_encrypt(p, k1, k2, k3)
        print(f"Encrypted: 0x{e:02X}")
    elif choice == '2':
        d = triple_des_decrypt(p, k1, k2, k3)
        print(f"Decrypted: 0x{d:02X}")
    else:
        print("Invalid choice. Please enter 1 for encryption or 2 for decryption.")

if __name__ == "__main__":
    main()
