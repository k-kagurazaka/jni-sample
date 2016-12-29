package jp.keita.kagurazaka.jnisample;

import java.io.Closeable;

public class SomeNativeClassWrapper implements Closeable {
    static {
        System.loadLibrary("native-lib");
    }

    private long nativePtr = 0;

    public SomeNativeClassWrapper() {
        nativePtr = nativeCreate();
    }

    public int getId() {
        return nativeGetId(getNativePtr());
    }

    public int getLangth(String text) {
        return nativeGetLength(getNativePtr(), text);
    }

    public void doubleArray(byte[] array) {
        nativeDoubleArray(getNativePtr(), array);
    }

    public void throwException() {
        nativeThrowException(getNativePtr());
    }

    @Override
    public void close() {
        nativeDestroy(getNativePtr());
    }

    private void requireNotClosed() {
        if (nativePtr == 0) {
            throw new UnsupportedOperationException("SomeNativeClassWrapper was already closed.");
        }
    }

    private long getNativePtr() {
        requireNotClosed();
        return nativePtr;
    }

    private static native long nativeCreate();

    private static native void nativeDestroy(long nativePtr);

    private static native int nativeGetId(long nativePtr);

    private static native int nativeGetLength(long nativePtr, String text);

    private static native void nativeDoubleArray(long nativePtr, byte[] array);

    private static native void nativeThrowException(long nativePtr);
}
