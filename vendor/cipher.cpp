//
// Created by Dell on 2018-6-28.
//
#include <iostream>
#include <string>
#include "cipher.h"


cipher::cipher(){
#ifdef __linux
    cipher_handler = dlopen(MARVEL_LIB, RTLD_LAZY);
    char* szError = dlerror();
    if(szError != NULL){
        dlclose(cipher_handler);
        throw "ERROR, Message(" + szError + ").\n";
    }
#else
    cipher_handler = LoadLibrary(MARVEL_LIB);
#endif
    if(cipher_handler != NULL){
        std::cout << "cheer up" << std::endl;
    }else{
        FreeLibrary(cipher_handler);
        throw "init failed";
    }
}

cipher::~cipher() {
    if(deviceHandler != NULL){
        destroy();
    }
    if(cipher_handler != NULL) {
        std::cout << "destory..." << std::endl;
#ifdef __linux
        dlclose(cipher_handler);
#else
        FreeLibrary(cipher_handler);
#endif
    }
}

//init
void cipher::init() {
    OPEN_PTR func = NULL;
    run(func, "SDF_OpenDevice", &deviceHandler);
}



//destroy
void cipher::destroy() {
    close();
    CLOSE_PTR func = NULL;
    //run(&func, "SDF_CloseDevice", args...);
    run(func, "SDF_CloseDevice", deviceHandler);
}

void cipher::open() {
    if(deviceHandler == NULL) throw "Please make sure init phase successful";
    SESSION_OPEN_PTR func = NULL;
    run(func, "SDF_OpenSession", deviceHandler, &session);
}



void cipher::close() {
    if(session != nullptr){
        SESSION_CLOSE_PTR func = NULL;
        run(func, "SDF_CloseSession", session);
    }
}

template<typename T, typename... Args>
void cipher::run(T func, const char *name, Args... args) {
#ifdef __linux

#else
    func = (T)GetProcAddress(cipher_handler, name);
    int code = 0;
    if(func != NULL){
        code = func(args...);
    }
    if(code != 0){
        std::cout << name << ": " << std::hex << code << std::endl;
    }
#endif
}

//
void cipher::apply(unsigned int index) {
    GPKAR_PTR func = NULL;
    run(func, "SDF_GetPrivateKeyAccessRight", session, index, (unsigned char*)MARVEL_CPS, 8);
}

void cipher::release(unsigned int index) {
    RPKAR_PTR func = NULL;
    run(func, "SDF_ReleasePrivateKeyAccessRight", session, index);
}

RSArefPublicKey cipher::exportPublicKey(unsigned int index, EXPORT_TYPE export_type) {
    RSArefPublicKey publicKey;
    ESPK_PTR func = NULL;
    std::string m = export_type == SIGN ? "SDF_ExportSignPublicKey_RSA" : "SDF_ExportEncPublicKey_RSA";
    run(func, m.c_str(), session, 1, &publicKey);
    return publicKey;
}
