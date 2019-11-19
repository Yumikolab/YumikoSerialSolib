#include <jni.h>
#include <string>
#include "gpioI.cpp"


extern "C" JNIEXPORT jstring JNICALL
Java_com_xrd_serialport_MainActivity_stringFromJNI(
        JNIEnv *env,
        jobject /* this */) {
    std::string hello = "Hello from C++";
    return env->NewStringUTF(hello.c_str());
}
extern "C"
JNIEXPORT jint JNICALL
Java_com_xrd_serialport_XrdSerialPortUtils_getSmoke_1det(JNIEnv *env, jclass clazz) {
    return getSmokeDet();
    // TODO: implement getSmoke_det()
}

extern "C"
JNIEXPORT jint JNICALL
Java_com_xrd_serialport_XrdSerialPortUtils_getWater_1det(JNIEnv *env, jclass clazz) {
    // TODO: implement getWater_det()
    return getWaterDet();
}

extern "C"
JNIEXPORT void JNICALL
Java_com_xrd_serialport_XrdSerialPortUtils_setRS485ttyS2(JNIEnv *env, jclass clazz, jint i) {
    // TODO: implement setRS485ttyS2()
    setRS485_sttyS2(i);
}
extern "C"
JNIEXPORT void JNICALL
Java_com_xrd_serialport_XrdSerialPortUtils_setRS485ttyS4(JNIEnv *env, jclass clazz, jint i) {
    // TODO: implement setRS485ttyS4()
    setRS485_sttyS4(i);
}
extern "C"
JNIEXPORT void JNICALL
Java_com_xrd_serialport_XrdSerialPortUtils_openElectricFanN(JNIEnv *env, jclass clazz) {
    // TODO: implement openElectricFanN()
    openElectricFan();
}
extern "C"
JNIEXPORT void JNICALL
Java_com_xrd_serialport_XrdSerialPortUtils_closeElectricFanN(JNIEnv *env, jclass clazz) {
    // TODO: implement closeElectricFanN()
    closeElectricFan();
}
extern "C"
JNIEXPORT void JNICALL
Java_com_xrd_serialport_XrdSerialPortUtils_openFrontDoor(JNIEnv *env, jclass clazz) {
    // TODO: implement openFrontDoor()
    openFrontDoor();
}
extern "C"
JNIEXPORT void JNICALL
Java_com_xrd_serialport_XrdSerialPortUtils_closeFrontDoor(JNIEnv *env, jclass clazz) {
    // TODO: implement closeFrontDoor()
    closeFrontDoor();
}extern "C"
JNIEXPORT void JNICALL
Java_com_xrd_serialport_XrdSerialPortUtils_openBehindDoor(JNIEnv *env, jclass clazz) {
    // TODO: implement openBehindDoor()
    openBehindDoor();
}extern "C"
JNIEXPORT void JNICALL
Java_com_xrd_serialport_XrdSerialPortUtils_closeBehindDoor(JNIEnv *env, jclass clazz) {
    // TODO: implement closeBehindDoor()
    closeBehindDoor();
}extern "C"
JNIEXPORT jint JNICALL
Java_com_xrd_serialport_XrdSerialPortUtils_getFrontDoorStatus(JNIEnv *env, jclass clazz) {
    // TODO: implement getFrontDoorStatus()
    return getFrontDoorStatus();
}extern "C"
JNIEXPORT jint JNICALL
Java_com_xrd_serialport_XrdSerialPortUtils_getBehindDoorStatus(JNIEnv *env, jclass clazz) {
    // TODO: implement getBehindDoorStatus()
    return getBehindDoorStatus();
}extern "C"
JNIEXPORT void JNICALL
Java_com_xrd_serialport_XrdSerialPortUtils_openBeep(JNIEnv *env, jclass clazz) {
    // TODO: implement openBeep()
    openBeep();
}

extern "C"
JNIEXPORT void JNICALL Java_com_xrd_serialport_XrdSerialPortUtils_closeBeep(JNIEnv *env, jclass clazz) {
    // TODO: implement closeBeep()
    closeBeep();
}

