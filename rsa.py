def rsa_encrypt(plaintext, e, n):
    return [pow(ord(char), e, n) for char in plaintext]

def rsa_decrypt(ciphertext, d, n):
    return ''.join([chr(pow(encrypted_char, d, n)) for encrypted_char in ciphertext])

def main():
    n = 2537  # Modulus
    e = 17    # Public exponent
    d = 2753  # Private exponent

    choice = input("Enter 1 to Encrypt or 2 to Decrypt: ")

    if choice == '1':
        message = input("Enter message to encrypt: ")
        ciphertext = rsa_encrypt(message, e, n)
        print("Encrypted:", ciphertext)
    elif choice == '2':
        ciphertext = input("Enter ciphertext (comma-separated integers): ")
        ciphertext = list(map(int, ciphertext.split(',')))
        decrypted_message = rsa_decrypt(ciphertext, d, n)
        print("Decrypted Message:", decrypted_message)
    else:
        print("Invalid choice. Enter 1 for encryption or 2 for decryption.")

if __name__ == "__main__":
    main()
