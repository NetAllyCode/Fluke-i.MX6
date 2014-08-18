package scd.com.imx6packetcapture;

import android.bluetooth.BluetoothDevice;
import android.bluetooth.BluetoothSocket;
import android.content.Context;

import java.io.DataOutputStream;
import java.util.Random;
import java.util.UUID;

/**
 * Created by sdickson on 8/18/14.
 */
public class BluetoothConnectThread extends Thread {
    BluetoothSocket s;
    Context context;

    public BluetoothConnectThread(BluetoothDevice device, Context context) {
        this.context = context;

        try {
            s = device.createInsecureRfcommSocketToServiceRecord(UUID.fromString(MainActivity.UUID));

        } catch (Exception e) {
            e.printStackTrace();
        }
    }


    public void run() {
        try
        {
            s.connect();
        } catch (Exception e)
        {
            e.printStackTrace();
        }
    }
}
