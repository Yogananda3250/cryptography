def reverse_key_order(subkeys):
    return subkeys[::-1]

def initial_permutation(block):
    return block

def final_permutation(block):
    return block

def des_round(data, subkey):
    return data

def des_encrypt(plaintext, subkeys):
    block = initial_permutation(plaintext)
    for subkey in subkeys:
        block = des_round(block, subkey)
    return final_permutation(block)

def des_decrypt(ciphertext, subkeys):
    subkeys = reverse_key_order(subkeys)
    block = initial_permutation(ciphertext)
    for subkey in subkeys:
        block = des_round(block, subkey)
    return final_permutation(block)

def main():
    choice = input("Enter 1 to Encrypt or 2 to Decrypt: ")
    plaintext = input("Enter plaintext (hex string, e.g., 0123456789ABCDEF): ")
    subkeys = ["K1", "K2", "K3", "K4", "K5", "K6", "K7", "K8", "K9", "K10", "K11", "K12", "K13", "K14", "K15", "K16"]
    if choice == '1':
        print(f"Encrypted Ciphertext: {des_encrypt(plaintext, subkeys)}")
    elif choice == '2':
        print(f"Decrypted Plaintext: {des_decrypt(plaintext, subkeys)}")
    else:
        print("Invalid choice.")

if __name__ == "__main__":
    main()


