import numpy as np

def matrix_mod_inverse(matrix, mod):
    det = np.linalg.det(matrix)
    det_inverse = pow(int(round(det)) % mod, -1, mod)
    adjugate = np.linalg.inv(matrix) * det
    return (adjugate % mod) * det_inverse % mod

def encrypt(plaintext, key_matrix):
    return np.dot(key_matrix, plaintext) % 26

def decrypt(ciphertext, key_matrix):
    return np.dot(matrix_mod_inverse(key_matrix, 26), ciphertext) % 26

def main():
    choice = input("Enter 1 to Encrypt or 2 to Decrypt: ")
    key_matrix = np.array([[9, 4], [5, 7]])  # Example key matrix
    
    if choice == '1':
        # Encryption
        plaintext = input("Enter plaintext (comma-separated values, e.g., '0,3'): ")
        plaintext = np.array([int(x) for x in plaintext.split(',')])
        ciphertext = encrypt(plaintext, key_matrix)
        print(f"Encrypted Ciphertext: {ciphertext}")

    elif choice == '2':
        # Decryption
        ciphertext = input("Enter ciphertext (comma-separated values, e.g., '14,21'): ")
        ciphertext = np.array([int(x) for x in ciphertext.split(',')])
        recovered_plaintext = decrypt(ciphertext, key_matrix)
        print(f"Recovered Plaintext: {recovered_plaintext}")

    else:
        print("Invalid choice. Please enter 1 for encryption or 2 for decryption.")

if __name__ == "__main__":
    main()
