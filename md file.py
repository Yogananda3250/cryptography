import hashlib

def generate_digest(message, algorithm='sha256'):
    # Convert message to bytes
    message_bytes = message.encode('utf-8')

    # Create hash object based on algorithm
    if algorithm == 'md5':
        hash_obj = hashlib.md5()
    elif algorithm == 'sha1':
        hash_obj = hashlib.sha1()
    elif algorithm == 'sha256':
        hash_obj = hashlib.sha256()
    else:
        raise ValueError("Unsupported algorithm. Use 'md5', 'sha1', or 'sha256'.")

    # Update hash object with message bytes
    hash_obj.update(message_bytes)

    # Return the hexadecimal digest
    return hash_obj.hexdigest()

# Example usage
message = "Hello, world!"
digest = generate_digest(message, 'sha256')
print(f"SHA-256 Digest: {digest}")
