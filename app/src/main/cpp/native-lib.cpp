#include <jni.h>
#include <vector>

extern "C"
JNIEXPORT jbyteArray JNICALL
Java_com_rtedgeviewer_MainActivity_processFrame(
        JNIEnv *env,
        jobject thiz,
        jbyteArray input,
        jint width,
        jint height) {

    // Get input data
    jsize len = env->GetArrayLength(input);
    jbyte *inData = env->GetByteArrayElements(input, nullptr);

    // Create output buffer
    jbyteArray output = env->NewByteArray(len);
    jbyte *outData = new jbyte[len];

    // Placeholder: copy input → output (OpenCV will replace this later)
    for (int i = 0; i < len; i++) {
        outData[i] = inData[i];
    }

    // Write output to Java
    env->SetByteArrayRegion(output, 0, len, outData);

    // Cleanup
    env->ReleaseByteArrayElements(input, inData, JNI_ABORT);
    delete[] outData;

    return output;
}
