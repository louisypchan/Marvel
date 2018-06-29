//
// Created by Dell on 2018-6-28.
//

#ifndef MARVEL_CIPHER_H
#define MARVEL_CIPHER_H
#include "../sys.h"

class cipher {

public:
    cipher();
    ~cipher();

    void init();

    void destroy();

    void open();

    void close();

    //get the right to access the corresponding private key
    //index to indicate which key would like to use
    void apply(unsigned int index);

    void release(unsigned int index);

    RSArefPublicKey exportPublicKey(unsigned int index, EXPORT_TYPE export_type);

    M_HANDLER cipher_handler = NULL;
protected:
    template <typename T, typename... Args>
    void run(T func, const char* name, Args... args);

private:
    void *deviceHandler = NULL;
    void *session = NULL;
};


#endif //MARVEL_CIPHER_H
