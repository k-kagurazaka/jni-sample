#include "SomeNativeClass.hpp"

#include <stdexcept>

SomeNativeClass::SomeNativeClass() { }

SomeNativeClass::~SomeNativeClass() { }

int SomeNativeClass::getId() const {
#if defined(_MSC_VER)
    return 10;
#elif defined(ANDROID)
    return 20;
#else
    return 100;
#endif
}


int SomeNativeClass::getLength(const char *text) const {
    return static_cast<int>(strlen(text));
}

void SomeNativeClass::doubleArray(unsigned char *array, unsigned int length) const {
    for (unsigned int i = 0; i < length; ++i) {
        array[i] = array[i] + array[i];
    }
}

void SomeNativeClass::throwException() {
    throw std::runtime_error("SomeNativeClass::throwException was called!");
}
