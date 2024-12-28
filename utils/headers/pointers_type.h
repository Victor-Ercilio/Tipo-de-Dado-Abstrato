#ifndef POINTERS_TYPE_H
#define  POINTERS_TYPE_H

/* Ponteiros de funções */
typedef void PtrFuncAllVoid(void);

/* Ponteiros de tipo de dados */
typedef int* PtrInt;
typedef int* const PtrIntConstPtr;
typedef const int* PtrIntConstData;
typedef const int* const PtrIntFrozen;

typedef char* PtrChar;
typedef char* const PtrCharConstPtr;
typedef const char* PtrCharConstData;
typedef const char* const PtrCharFrozen;

#endif
