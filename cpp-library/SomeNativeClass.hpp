#pragma once

#if defined(_MSC_VER)
#if defined(CPPLIBRARY_EXPORTS)
#define CPPLIBRARY_API __declspec(dllexport)
#else
#define CPPLIBRARY_API __declspec(dllimport)
#endif
#else
#define CPPLIBRARY_API
#endif

class CPPLIBRARY_API SomeNativeClass {
public:
	SomeNativeClass();

    virtual ~SomeNativeClass();

    int calculate();

    void throwException();
};
