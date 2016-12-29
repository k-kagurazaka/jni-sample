#include "JavaString.hpp"

#include <string>

namespace helper {

    JavaString::JavaString(JNIEnv *env, jstring object)
            : env(env), object(object), value(NULL) {
        if (env != NULL && object != NULL) {
            value = env->GetStringUTFChars(object, NULL);
        }
    }

    JavaString::~JavaString() {
        if (env != NULL && object != NULL && value != NULL) {
            env->ReleaseStringUTFChars(object, value);
        }

        env = NULL;
        object = NULL;
        value = NULL;
    }

    const char* JavaString::getValue() const {
        return value;
    }
}
