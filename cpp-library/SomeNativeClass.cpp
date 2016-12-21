#include "SomeNativeClass.hpp"

#include <stdexcept>

SomeNativeClass::SomeNativeClass() { }

SomeNativeClass::~SomeNativeClass() { }

int SomeNativeClass::calculate() {
#if defined(_MSC_VER)
    return 10;
#elif defined(ANDROID)
    return 20;
#else
    return 100;
#endif
}

void SomeNativeClass::throwException() {
    throw std::runtime_error("SomeNativeClass::throwException was called!");
}
