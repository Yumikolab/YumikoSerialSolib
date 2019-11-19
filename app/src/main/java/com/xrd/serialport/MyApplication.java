package com.xrd.serialport;

import android.app.Application;
import android.content.Context;
import android.content.SharedPreferences;
import android.content.res.Configuration;
import android.util.Log;



import java.io.File;
import java.io.IOException;
import java.security.InvalidParameterException;

/**
 * Creatd by pengyl
 * on 2018/10/23
 */
public class MyApplication extends Application {
    private static Context context;


    @Override
    public void onCreate() {
        super.onCreate();
        Log.d("pengyuanlong", "MyApplication onCreate: ");
        context = getApplicationContext();

//        ActivityManager activityManager = (ActivityManager) getSystemService(ACTIVITY_SERVICE);
//        //最大分配内存
//        int memory = activityManager.getMemoryClass();
//        System.out.println("memory: " + memory);
//        //最大分配内存获取方法2
//        float maxMemory = (float) (Runtime.getRuntime().maxMemory() * 1.0 / (1024 * 1024));
//        //当前分配的总内存
//        float totalMemory = (float) (Runtime.getRuntime().totalMemory() * 1.0 / (1024 * 1024));
//        //剩余内存
//        float freeMemory = (float) (Runtime.getRuntime().freeMemory() * 1.0 / (1024 * 1024));
//        System.out.println("maxMemory: " + maxMemory);//192.0
//        System.out.println("totalMemory: " + totalMemory);//2.220253
//        System.out.println("freeMemory: " + freeMemory);//0.08934021


    }


    public static Context getContext() {
        return context;
    }




    /**
     * 在onCreat()之前调用
     *
     * @param base
     */


    /**
     * 当系统更改语言时，会自动调用
     *
     * @param newConfig
     */
    @Override
    public void onConfigurationChanged(Configuration newConfig) {
        super.onConfigurationChanged(newConfig);
    }


    public SerialPortFinder mSerialPortFinder = new SerialPortFinder();
    private SerialPort mSerialPort = null;

    public SerialPort getSerialPort(String ttys) throws SecurityException, IOException, InvalidParameterException {
//        if (mSerialPort == null) {
        /* Read serial port parameters */
//        String[] allDevicesPath = mSerialPortFinder.getAllDevicesPath();
//        for (String s : allDevicesPath) {
//            Log.d("getSerialPort", "getSerialPort: " + s);
//        }
        SharedPreferences sp = getSharedPreferences("android.serialport.sample_preferences", MODE_PRIVATE);
        String path = ttys;
        int baudrate = 9600;


        /* Check parameters */
        if ((path.length() == 0) || (baudrate == -1)) {
            throw new InvalidParameterException();
        }

        /* Open the serial port */
        mSerialPort = new SerialPort(new File(path), baudrate);
//        }
        return mSerialPort;
    }

    public void closeSerialPort() {
        if (mSerialPort != null) {
            mSerialPort.close();
            mSerialPort = null;
        }
    }


}
