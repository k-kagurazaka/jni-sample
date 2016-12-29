#include "jp_keita_kagurazaka_jnisample_SomeNativeClassWrapper.h"

#include <stdexcept>
#include <SomeNativeClass.hpp>

#include "helper/JavaByteArray.hpp"
#include "helper/JavaString.hpp"

using namespace helper;

#define CONVERT_EXCEPTION(env, statement) \
    try { \
        statement; \
    } catch (std::bad_alloc&) {\
        throwRuntimeException(env, "Failed to allocate memory."); \
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
        (JNIEnv *env, jclass) {
    CONVERT_EXCEPTION(env, {
        return reinterpret_cast<jlong>(new SomeNativeClass);
    });
    return NULL;
}

JNIEXPORT void JNICALL Java_jp_keita_kagurazaka_jnisample_SomeNativeClassWrapper_nativeDestroy
        (JNIEnv *env, jclass, jlong nativePtr) {
    CONVERT_EXCEPTION(env, {
        delete getSomeNativeClass(nativePtr);
    });
}

JNIEXPORT jint JNICALL Java_jp_keita_kagurazaka_jnisample_SomeNativeClassWrapper_nativeGetId
        (JNIEnv *env, jclass, jlong nativePtr) {
    CONVERT_EXCEPTION(env, {
        return static_cast<jint>(getSomeNativeClass(nativePtr)->getId());
    });
    return 0;
}

JNIEXPORT jint JNICALL Java_jp_keita_kagurazaka_jnisample_SomeNativeClassWrapper_nativeGetLength
        (JNIEnv *env, jclass, jlong nativePtr, jstring text) {
    CONVERT_EXCEPTION(env, {
        JavaString str(env, text);
        return static_cast<jint>(getSomeNativeClass(nativePtr)->getLength(str.getValue()));
    });
    return 0;
}

JNIEXPORT void JNICALL Java_jp_keita_kagurazaka_jnisample_SomeNativeClassWrapper_nativeDoubleArray
        (JNIEnv *env, jclass, jlong nativePtr, jbyteArray array) {
    CONVERT_EXCEPTION(env, {
        JavaByteArray byteArray(env, array);
        getSomeNativeClass(nativePtr)->doubleArray(byteArray.getValue(), byteArray.getLength());
    });
}

JNIEXPORT void JNICALL Java_jp_keita_kagurazaka_jnisample_SomeNativeClassWrapper_nativeThrowException
        (JNIEnv *env, jclass, jlong nativePtr) {
    CONVERT_EXCEPTION(env, {
        getSomeNativeClass(nativePtr)->throwException();
    });
}

}
