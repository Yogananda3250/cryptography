import hashlib

def compute_sha256_hash(message):
    # Convert message to bytes
    message_bytes = message.encode('utf-8')
    
    # Create SHA-256 hash object
    sha256_hash = hashlib.sha256()
    
    # Update the hash object with the message bytes
    sha256_hash.update(message_bytes)
    
    # Return the hexadecimal representation of the hash
    return sha256_hash.hexdigest()

# Example usage
message = "Hello, this is a secure message!"
hash_value = compute_sha256_hash(message)

print(f"SHA-256 Hash: {hash_value}")
