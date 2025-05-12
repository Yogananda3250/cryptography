#include <Crypto.h>
#include <SHA256.h>
#include <HMAC.h>

void setup() {
  Serial.begin(9600);
  while (!Serial);

  const char* key = "secret_key";
  const char* message = "This is a secret message";

  // Convert to byte arrays
  byte hmacResult[32]; // SHA-256 output size = 32 bytes
  HMAC<SHA256> hmac;
  hmac.reset((const byte*)key, strlen(key));
  hmac.update((const byte*)message, strlen(message));
  hmac.finalize(hmacResult, sizeof(hmacResult));

  Serial.print("HMAC (SHA-256): ");
  for (int i = 0; i < sizeof(hmacResult); i++) {
    if (hmacResult[i] < 0x10) Serial.print("0");
    Serial.print(hmacResult[i], HEX);
  }
  Serial.println();
}

void loop() {
  // Nothing in loop
}

