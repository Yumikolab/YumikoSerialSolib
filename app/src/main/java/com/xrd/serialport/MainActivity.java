package com.xrd.serialport;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Context;
import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.TextView;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStream;

public class MainActivity extends AppCompatActivity {

    // Used to load the 'native-lib' library on application startup.
    static {
        System.loadLibrary("xrd-seriport");
    }

    private InputStream mInputStream;
    private TextView tv;
    private OutputStream outputStream;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        tv = findViewById(R.id.sample_text);
//        try {
//            SerialPort ttyS3 = new SerialPort("/dev/ttyS3", 9600);
//             mInputStream = ttyS3.getInputStream();
//            new ReadThread().start();
//        } catch (IOException e) {
//            e.printStackTrace();
//        }
    }

    /**
     * A native method that is implemented by the 'native-lib' native library,
     * which is packaged with this application.
     */


    public class ReadThread extends Thread {
        @Override
        public void run() {
            super.run();
//            while (this.flag) {
            Log.d("pengyuanlong", "UpsFragment ReadThread000: " + Thread.currentThread().getName());
            final byte[] bytes = new byte[1024];
            while (!isInterrupted()) {
                StringBuilder content = new StringBuilder();
                if (mInputStream == null) return;
//                InputStreamReader in = new InputStreamReader(mInputStream);
//                BufferedReader reader = new BufferedReader(in);
                try {
                    String line = "";
                    final int read = mInputStream.read(bytes);
                    Log.d("pengyuanlong", "UpsFragment ReadThread111: " + Thread.currentThread().getName());
                    if (read > 0) {
                        tv.post(new Runnable() {
                            @Override
                            public void run() {
                                tv.setText(DataUtils.bytes2HexStr(bytes,0,read));
                            }
                        });
                    }
                } catch (IOException e) {
                    e.printStackTrace();
                    Log.e("pengyuanlong", "UpsFragment IOException return: ");
                    return;
                }
            }
//            }
        }

    }
}
