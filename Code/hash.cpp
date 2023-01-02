#include <iostream>
#include <openssl/sha.h>
#include <array>

std::array<unsigned char, 32ULL> hash(const std::string& message) {
    // The message to be hashed
    const char* notHashed = message.c_str();

    // Compute the SHA-256 hash of the message
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, message.data(), message.size());
    SHA256_Final(hash, &sha256);

    // unsigned char[32] -> std::array<unsigned char, 32ULL>
    std::array<unsigned char, 32ULL> result;
    std::copy(hash, hash + 32, result.begin());

    // Print the hash
    for (int i = 0; i < SHA256_DIGEST_LENGTH; i++)
        std::cout << std::hex << (int)hash[i];
    std::cout << std::endl;

    // Returns the hash
    return result;
}
