//
// Created by Dell on 2018-6-28.
//

#ifndef MARVEL_SYS_H
#define MARVEL_SYS_H

#ifdef __linux

#include <dlfcn.h>
#define MARVEL_TYPE 1
#define MARVEL_LIB "/usr/lib64/srj1604DevAPI.so"
typedef void* M_HANDLER;

#else
#include <windows.h>
#define MARVEL_TYPE 0
#define MARVEL_LIB "srj1604DevAPI.dll"
typedef HINSTANCE M_HANDLER;

#endif //
//open device
typedef int(*OPEN_PTR)(void **);
//close device
typedef int(*CLOSE_PTR)(void *);
//session open
typedef int(*SESSION_OPEN_PTR)(void*, void**);
//session close
typedef int(*SESSION_CLOSE_PTR)(void*);

//private key access right
typedef int(*GPKAR_PTR)(void*, unsigned int, unsigned char*, unsigned int);
typedef int(*RPKAR_PTR)(void*, unsigned int);


#define MARVEL_CPS "12345678"

//2048 RSA
#define RSAref_MAX_BITS    2048
#define RSAref_MAX_LEN     ((RSAref_MAX_BITS + 7) / 8)
#define RSAref_MAX_PBITS   ((RSAref_MAX_BITS + 1) / 2)
#define RSAref_MAX_PLEN    ((RSAref_MAX_PBITS + 7)/ 8)
typedef struct RSArefPublicKey_st
{
    unsigned int  bits;
    unsigned char m[RSAref_MAX_LEN];
    unsigned char e[RSAref_MAX_LEN];
} RSArefPublicKey;

typedef int(*ESPK_PTR)(void*, unsigned int, RSArefPublicKey*);

enum EXPORT_TYPE{SIGN, ENCRYPT};

#endif //MARVEL_SYS_H
