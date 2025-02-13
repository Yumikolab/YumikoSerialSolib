package com.xrd.serialport;

/**
 * Creatd by Yumiko
 * on 2019/11/14
 */
public class XrdSerialPortUtils {

    public static int READ_RS485 = 0;
    public static int WRITE_RS485 = 1;

    static {
        System.loadLibrary("xrd-seriport");
//        System.loadLibrary("xrd-sunmoon");
    }



    public native static int getSmoke_det();//烟感

    public native static int getWater_det();//水清



    public native static void setRS485ttyS2(int i);

    public native static void setRS485ttyS4(int i);

    public native static void openElectricFanN();

    public native static void closeElectricFanN();

    public native static void openFrontDoor();

    public native static void closeFrontDoor();

    public native static void openBehindDoor();

    public native static void closeBehindDoor();

    public native static int getFrontDoorStatus();

    public native static int getBehindDoorStatus();

    public native static void openBeep();

    public native static void closeBeep();



}
