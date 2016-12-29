#pragma once

#include <jni.h>

namespace helper {

    class JavaByteArray {
    public:
        JavaByteArray(JNIEnv *env, jbyteArray object);

        virtual ~JavaByteArray();

        unsigned char *getValue() const;

        unsigned int getLength() const;

    private:
        JavaByteArray(const JavaByteArray &);

        JavaByteArray &operator=(const JavaByteArray &);

        JNIEnv *env;
        jbyteArray object;
        unsigned char *value;
        unsigned int length;
    };

}
