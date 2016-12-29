#include "JavaByteArray.hpp"

#include <string>

namespace helper {

    JavaByteArray::JavaByteArray(JNIEnv *env, jbyteArray object)
            : env(env), object(object), value(NULL) {
        if (env != NULL && object != NULL) {
            length = static_cast<unsigned int>(env->GetArrayLength(object));
            value = reinterpret_cast<unsigned char *>(env->GetByteArrayElements(object, NULL));
        }
    }

    JavaByteArray::~JavaByteArray() {
        if (env != NULL && object != NULL && value != NULL) {
            env->ReleaseByteArrayElements(object, reinterpret_cast<jbyte *>(value), 0);
        }

        env = NULL;
        object = NULL;
        value = NULL;
    }

    unsigned char *JavaByteArray::getValue() const {
        return value;
    }

    unsigned int JavaByteArray::getLength() const {
        return length;
    }

}
