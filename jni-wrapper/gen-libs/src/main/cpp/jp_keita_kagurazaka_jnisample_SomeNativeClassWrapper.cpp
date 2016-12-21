#include "jp_keita_kagurazaka_jnisample_SomeNativeClassWrapper.h"

#include <stdexcept>
#include <SomeNativeClass.hpp>

#define CONVERT_EXCEPTION(statement) \
    try { \
        statement; \
    } catch (std::exception &e) { \
        throwRuntimeException(env, e.what()); \
    } catch (...) { \
        throwRuntimeException(env, "Unknown exception thrown!"); \
    }

static void throwRuntimeException(JNIEnv *env, const char *what) {
    jclass classj = env->FindClass("jp/keita/kagurazaka/jnisample/NativeException");
    if (classj == NULL) {
        return;
    }

    env->ThrowNew(classj, what);
    env->DeleteLocalRef(classj);
}

static SomeNativeClass *getSomeNativeClass(jlong nativePtr) {
    return reinterpret_cast<SomeNativeClass *>(nativePtr);
}

extern "C" {

JNIEXPORT jlong JNICALL Java_jp_keita_kagurazaka_jnisample_SomeNativeClassWrapper_nativeCreate
        (JNIEnv *, jclass) {
    return reinterpret_cast<jlong>(new SomeNativeClass);
}

JNIEXPORT void JNICALL Java_jp_keita_kagurazaka_jnisample_SomeNativeClassWrapper_nativeDestroy
        (JNIEnv *, jclass, jlong nativePtr) {
    delete getSomeNativeClass(nativePtr);
}

JNIEXPORT jint JNICALL Java_jp_keita_kagurazaka_jnisample_SomeNativeClassWrapper_nativeCalculate
        (JNIEnv *, jclass, jlong nativePtr) {
    return static_cast<jint>(getSomeNativeClass(nativePtr)->calculate());
}

JNIEXPORT void JNICALL Java_jp_keita_kagurazaka_jnisample_SomeNativeClassWrapper_nativeThrowException
        (JNIEnv *env, jclass, jlong nativePtr) {
    CONVERT_EXCEPTION({
		getSomeNativeClass(nativePtr)->throwException();
    });
}

}
