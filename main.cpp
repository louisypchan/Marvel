#include <iostream>
#include "vendor/cipher.h"

#include <openssl/rsa.h>
#include <openssl/evp.h>

void PrintHex(unsigned char *str, unsigned int len) {
    int i = 0;
    for (i = 0; i < len; i++) {
        if (i % 4 == 0) {
            printf("0x");
        }
        printf("%02x", str[i]);
        if (i % 4 == 3) {
            printf(" ");
        }
        if (i % 16 == 15) {
            printf("\n");
        }
    }
    printf("\n");
}

int main() {

    cipher c;

    c.init();

    c.open();

    c.apply(1);

    //
    RSArefPublicKey publicKey = c.exportPublicKey(1, SIGN);

    c.release(1);
    BIGNUM *n = BN_new();
    BIGNUM *e = BN_new();
    BN_bin2bn(publicKey.m, RSAref_MAX_LEN, n);
    BN_bin2bn(publicKey.e, RSAref_MAX_LEN, e);
    RSA* rsa = RSA_new();
    RSA_set0_key(rsa, n, e, NULL);

    EVP_PKEY *evpKey = EVP_PKEY_new();
    EVP_PKEY_set1_RSA(evpKey, rsa);



    std::cout<< evpKey << std::endl;

    return 0;

}