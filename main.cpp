#include <iostream>
#include "vendor/cipher.h"

int main() {

    cipher c;

    c.init();

    c.open();

    c.apply(1);

    RSArefPublicKey publicKey = c.exportPublicKey(1, SIGN);

    c.release(1);


    std::cout << publicKey.bits << std::endl;

    return 0;
}