#pragma once

#include <jni.h>

namespace helper {

    class JavaString {
    public:
        JavaString(JNIEnv *env, jstring object);

        virtual ~JavaString();

        const char *getValue() const;

    private:
        JavaString(const JavaString &);

        JavaString &operator=(const JavaString &);

        JNIEnv *env;
        jstring object;
        const char *value;
    };

}
