package scd.com.imx6packetcapture;

import android.app.AlertDialog;
import android.bluetooth.BluetoothAdapter;
import android.bluetooth.BluetoothSocket;
import android.content.Context;
import android.content.DialogInterface;
import android.os.Bundle;
import android.os.Handler;
import android.os.Message;
import android.util.Log;

import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.InputStream;
import java.util.Calendar;

/**
 * Created by sam on 5/23/14.
 */
public class BluetoothHandlerThread extends Thread
{
    BluetoothAdapter adapter;
    BluetoothSocket s;
    InputStream in;
    PktListAdapter list_adapter;
    Handler handler;
    public static final String format = "SSS";

    public BluetoothHandlerThread(BluetoothAdapter adapter, BluetoothSocket s, PktListAdapter list_adapter, Handler handler)
    {
        this.adapter = adapter;
        this.s = s;
        this.handler = handler;
        this.list_adapter = list_adapter;

        try
        {
            in = s.getInputStream();
        }
        catch(Exception e)
        {

        }
    }

    public void run()
    {
        try {
            byte buf[] = new byte[10];

            while ((in.read(buf)) > 0)
            {
                String pkt = new String(buf, "UTF-8");

                if(pkt.contains("IPv4"))
                {
                    MainActivity.values[1]++;
                    list_adapter.packets.get(1).num++;
                }
                else if(pkt.contains("IPv6"))
                {
                    MainActivity.values[2]++;
                    list_adapter.packets.get(2).num++;
                }
                else if(pkt.contains("ARP"))
                {
                    MainActivity.values[0]++;
                    list_adapter.packets.get(0).num++;
                }
                else if(pkt.contains("VLAN frame"))
                {
                    MainActivity.values[3]++;
                    list_adapter.packets.get(3).num++;
                }
                else
                {
                    MainActivity.values[4]++;
                    list_adapter.packets.get(4).num++;
                }

                handler.sendEmptyMessage(0);

            }
        }
        catch(Exception e)
        {
            e.printStackTrace();
        }
    }
}
