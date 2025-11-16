#include <jni.h>
#include <opencv2/opencv.hpp>

using namespace cv;

extern "C"
JNIEXPORT jbyteArray JNICALL
Java_com_rtedgeviewer_MainActivity_processFrame(
        JNIEnv *env,
        jobject thiz,
        jbyteArray input,
        jint width,
        jint height) {

    // Length of input RGBA buffer
    jsize len = env->GetArrayLength(input);

    // Get input bytes
    jbyte *inputBytes = env->GetByteArrayElements(input, nullptr);

    // Wrap input into cv::Mat (RGBA)
    Mat rgba(height, width, CV_8UC4, (unsigned char *)inputBytes);

    // Convert RGBA → Gray
    Mat gray;
    cvtColor(rgba, gray, COLOR_RGBA2GRAY);

    // Apply Canny edge detection
    Mat edges;
    Canny(gray, edges, 80, 180);   // Tune thresholds if required

    // Convert Gray edges → RGBA so Android can display
    Mat outRGBA;
    cvtColor(edges, outRGBA, COLOR_GRAY2RGBA);

    // Prepare output byte array
    jbyteArray output = env->NewByteArray(len);
    env->SetByteArrayRegion(
            output,
            0,
            len,
            reinterpret_cast<jbyte *>(outRGBA.data)
    );

    // Release
    env->ReleaseByteArrayElements(input, inputBytes, JNI_ABORT);

    return output;
}
