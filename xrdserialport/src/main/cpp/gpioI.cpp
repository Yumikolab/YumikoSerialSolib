//
// Created by Administrator on 2018/11/20.
//
#include <jni.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <zconf.h>
#include <android/log.h>
#include <iostream>

#define  LOGE(...)  __android_log_print(ANDROID_LOG_ERROR,"JNI",__VA_ARGS__);

#define FAN_IOCTL_SET_OFF                                  0
#define FAN_IOCTL_SET_ON                                   1

#define UART4_IOCTL_SET_OFF                             0
#define UART4_IOCTL_SET_ON                              1

#define UART2_IOCTL_SET_OFF                             0
#define URAT2_IOCTL_SET_ON                              1

#define DOOR1_IOCTL_SET_OFF                            1
#define DOOR1_IOCTL_SET_ON                             0

#define DOOR2_IOCTL_SET_OFF                            1
#define DOOR2_IOCTL_SET_ON                                0

#define FAN_IOCTL_SET              1
#define WATER_DETECT_STATE                              3
#define SMOKE_DETECT_STATE        4
#define UART4_485_IOCTL_SET        5
#define UART2_485_IOCTL_SET        6
#define DOOR1_IOCTL_SET        7
#define DOOR1_DETECT_STATE        8
#define DOOR2_IOCTL_SET            9
#define DOOR2_DETECT_STATE        10


#define BEEP_IOCTL_SET_OFF            0
#define BEEP_IOCTL_SET_ON        1

#define BEEP_IOCTL_SET            11
//1輸出高   0輸出低
int getSmokeDet() {
    int led1 = ::open("/dev/sunxi-gpio", O_WRONLY);
    if (led1 < 0) {
        LOGE("pengyuanlong", "getSmokeDet fail ");
    }
    int smoke_det = ::ioctl(led1, SMOKE_DETECT_STATE, 0);//1 无烟(高电平)  0有烟
    ::close(led1);
    return smoke_det;
}

int getWaterDet() {
    int led1 = ::open("/dev/sunxi-gpio", O_WRONLY);
    if (led1 < 0) {
        LOGE("pengyuanlong", "getWaterDet fail ");
    }
    int water_det = ::ioctl(led1, WATER_DETECT_STATE, 0);
    ::close(led1);
    return water_det;
}

//    ::ioctl(led1, UART4_485_IOCTL_SET, UART4_IOCTL_SET_ON);   对RS485/ttsy4设置
//    ::ioctl(led1, UART4_485_IOCTL_SET, UART4_IOCTL_SET_OFF);
void setRS485_sttyS2(int i) {//对串口485 sttyS2进行读或写设置
    int led1 = ::open("/dev/sunxi-gpio", O_WRONLY);
    if (i == 1) {//写
        ::ioctl(led1, UART2_485_IOCTL_SET, URAT2_IOCTL_SET_ON);
    } else if (i == 0) {
        ::ioctl(led1, UART2_485_IOCTL_SET, UART2_IOCTL_SET_OFF);
    }
    ::close(led1);
}

void setRS485_sttyS4(int i) {//对串口485 sttyS4进行读或写设置
    int led1 = ::open("/dev/sunxi-gpio", O_WRONLY);
    if (i == 1) {//写
        ::ioctl(led1, UART4_485_IOCTL_SET, UART4_IOCTL_SET_ON);
    } else if (i == 0) {
        ::ioctl(led1, UART4_485_IOCTL_SET, UART4_IOCTL_SET_OFF);
    }
    ::close(led1);
}

void openElectricFan() {
    int led1 = ::open("/dev/sunxi-gpio", O_WRONLY);
    if (led1 < 0) {
        LOGE("pengyuanlong", "getSmokeDet fail ");
    }
    ::ioctl(led1, FAN_IOCTL_SET, FAN_IOCTL_SET_ON);
    ::close(led1);
}

void closeElectricFan() {
    int led1 = ::open("/dev/sunxi-gpio", O_WRONLY);
    if (led1 < 0) {
        LOGE("pengyuanlong", "getSmokeDet fail ");
    }
    ::ioctl(led1, FAN_IOCTL_SET, FAN_IOCTL_SET_OFF);//电风扇
    ::close(led1);
}

int getFrontDoorStatus() {
    int led1 = ::open("/dev/sunxi-gpio", O_WRONLY);
    if (led1 < 0) {
        LOGE("pengyuanlong", "getFrontDoorStatus fail ");
    }

    int door1_det = ::ioctl(led1, DOOR1_DETECT_STATE, 0);
    ::close(led1);
    return door1_det;
}

int getBehindDoorStatus() {

    int led1 = ::open("/dev/sunxi-gpio", O_WRONLY);
    if (led1 < 0) {
        LOGE("pengyuanlong", "getBehindDoorStatus fail ");

    }
    int door2_det = ::ioctl(led1, DOOR2_DETECT_STATE, 0);

    ::close(led1);
    return door2_det;
}

void openFrontDoor() {
    int led1 = ::open("/dev/sunxi-gpio", O_WRONLY);
    if (led1 < 0) {
        LOGE("pengyuanlong", "openFrontDoor fail ");
        return;
    }
    ::ioctl(led1, DOOR1_IOCTL_SET, DOOR1_IOCTL_SET_ON);//前门禁开
    ::close(led1);

}

void closeFrontDoor() {
    int led1 = ::open("/dev/sunxi-gpio", O_WRONLY);

    if (led1 < 0) {
        LOGE("pengyuanlong", "closeFrontDoor fail ");
        return;
    }
    ::ioctl(led1, DOOR1_IOCTL_SET, DOOR1_IOCTL_SET_OFF);//前门禁关
    ::close(led1);


}

void openBehindDoor() {
    int led1 = ::open("/dev/sunxi-gpio", O_WRONLY);
    if (led1 < 0) {
        LOGE("pengyuanlong", "openBehindDoor fail ");
        return;
    }
    ::ioctl(led1, DOOR2_IOCTL_SET, DOOR2_IOCTL_SET_ON);//后门禁开
    ::close(led1);

}

void closeBehindDoor() {
    int led1 = ::open("/dev/sunxi-gpio", O_WRONLY);
    if (led1 < 0) {
        LOGE("pengyuanlong", "closeBehindDoor fail ");
    }
    ::ioctl(led1, DOOR2_IOCTL_SET, DOOR2_IOCTL_SET_OFF);//后门禁关
    ::close(led1);

}

void openBeep() {

    int led1 = ::open("/dev/sunxi-gpio", O_WRONLY);
    if (led1 < 0) {
        LOGE("pengyuanlong", "closeFrontDoor fail ");
        return;
    }

    ::ioctl(led1, BEEP_IOCTL_SET, BEEP_IOCTL_SET_ON);


    ::close(led1);
}

void closeBeep() {

    int led1 = ::open("/dev/sunxi-gpio", O_WRONLY);
    if (led1 < 0) {
        LOGE("pengyuanlong", "closeFrontDoor fail ");
        return;
    }

    ::ioctl(led1, BEEP_IOCTL_SET, BEEP_IOCTL_SET_OFF);
    ::close(led1);

}


