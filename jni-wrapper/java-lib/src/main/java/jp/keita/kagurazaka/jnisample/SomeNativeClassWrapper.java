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

    public int calculate() {
        requireNotClosed();
        return nativeCalculate(nativePtr);
    }

    public void throwException() {
        requireNotClosed();
        nativeThrowException(nativePtr);
    }

    @Override
    public void close() {
        requireNotClosed();
        nativeDestroy(nativePtr);
    }

    private void requireNotClosed() {
        if (nativePtr == 0) {
            throw new UnsupportedOperationException("SomeNativeClassWrapper was already closed.");
        }
    }

    private static native long nativeCreate();

    private static native void nativeDestroy(long nativePtr);

    private static native int nativeCalculate(long nativePtr);

    private static native void nativeThrowException(long nativePtr);
}
