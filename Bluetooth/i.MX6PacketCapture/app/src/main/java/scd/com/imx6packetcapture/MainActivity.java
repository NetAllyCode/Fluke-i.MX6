package scd.com.imx6packetcapture;

import android.app.Activity;
import android.bluetooth.BluetoothAdapter;
import android.bluetooth.BluetoothDevice;
import android.bluetooth.BluetoothSocket;
import android.content.BroadcastReceiver;
import android.content.Context;
import android.content.Intent;
import android.content.IntentFilter;
import android.graphics.Canvas;
import android.graphics.Color;
import android.graphics.Paint;
import android.graphics.RectF;
import android.os.Bundle;
import android.os.Handler;
import android.os.Message;
import android.util.Log;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.widget.LinearLayout;
import android.widget.ListView;

import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.net.Socket;
import java.util.ArrayList;
import java.util.Random;
import java.util.UUID;


public class MainActivity extends Activity
{

    BluetoothAdapter adapter;
    Context context;
    PktListAdapter list_adapter;
    ArrayList<Packet> packets;
    ListView pktList;
    MyGraphview graphview;
    LinearLayout chart;
    public static float values[] = {0,0,0,0,0};

    public static final String UUID = "00000000-0000-0000-0000-000033320000"; //Change to device-specific UUID
    public static final String REMOTE_MAC = “00:1A:7D:DA:71:13”; //Change to device-specific hardware address
    public static final String NAME = "SCD_SERVER";

    public final Handler handler = new Handler(){
        public void handleMessage(Message msg)
        {
            list_adapter.notifyDataSetChanged();
            graphview.setValues(calculateData(values));
            graphview.invalidate();

        }
    };


    @Override
    protected void onCreate(Bundle savedInstanceState)
    {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        packets = new ArrayList<Packet>();
        packets.add(new Packet(Packet.pkt_type.ARP, 0));
        packets.add(new Packet(Packet.pkt_type.IPV4, 0));
        packets.add(new Packet(Packet.pkt_type.IPv6, 0));
        packets.add(new Packet(Packet.pkt_type.VLAN, 0));
        packets.add(new Packet(Packet.pkt_type.OTHER, 0));

        pktList = (ListView) findViewById(R.id.pktList);
        chart = (LinearLayout) findViewById(R.id.chart);
        list_adapter = new PktListAdapter(this, packets);
        pktList.setAdapter(list_adapter);

        graphview = new MyGraphview(this, calculateData(values));
        chart.addView(graphview);


        context = this;
        adapter = BluetoothAdapter.getDefaultAdapter();
        try
        {
            BluetoothDevice device = adapter.getRemoteDevice(REMOTE_MAC);
            BluetoothSocket socket = device.createInsecureRfcommSocketToServiceRecord(java.util.UUID.fromString(UUID));
            adapter.cancelDiscovery();
            socket.connect();

            OutputStream tmpOut = null;
            tmpOut = socket.getOutputStream();

            new BluetoothHandlerThread(adapter, socket, list_adapter, handler).start();

        } catch (IOException e) {
            // TODO Auto-generated catch block
            e.printStackTrace();
        }
    }

    private float[] calculateData(float[] data)
    {
        float pi[] = new float[data.length];

        float total = 0;
        for (int i = 0; i < data.length; i++) {
            total += data[i];
        }
        for (int i = 0; i < data.length; i++) {
            pi[i] = 360 * (data[i] / total);
        }

        //Log.d("bt", pi[0] + " " + pi[1] + " " + pi[2] + " " + pi[3] + " " + pi[4] + " ");
        return pi;
    }

    public class MyGraphview extends View {
        private Paint paint = new Paint(Paint.ANTI_ALIAS_FLAG);
        private float[] value_degree;
        RectF rectf = new RectF(300, 300, 760, 760);
        float temp = 0;

        public MyGraphview(Context context, float[] values) {
            super(context);
            value_degree = new float[values.length];
            for (int i = 0; i < values.length; i++) {
                value_degree[i] = values[i];
            }
        }

        public void setValues(float[] values)
        {
            temp = 0;
            value_degree = new float[values.length];
            for (int i = 0; i < values.length; i++) {
                value_degree[i] = values[i];
            }
        }

        protected void onDraw(Canvas canvas) {
            super.onDraw(canvas);

            for (int i = 0; i < value_degree.length; i++)
            {
                Log.d("bt", "i=" + i + ", val=" + value_degree[i]);
                switch(i)
                {
                    case 0:
                        paint.setColor(Color.parseColor("#66CCFF"));
                        canvas.drawArc(rectf, 0, value_degree[i], true, paint);
                        break;
                    case 1:
                        temp += value_degree[i - 1];
                        paint.setColor(Color.parseColor("#EC4B43"));
                        canvas.drawArc(rectf, temp, value_degree[i], true, paint);
                        break;
                    case 2:
                        temp += value_degree[i - 1];
                        paint.setColor(Color.parseColor("#33CC33"));
                        canvas.drawArc(rectf, temp, value_degree[i], true, paint);
                        break;
                    case 3:
                        temp += value_degree[i - 1];
                        paint.setColor(Color.parseColor("#CC99FF"));
                        canvas.drawArc(rectf, temp, value_degree[i], true, paint);
                        break;
                    case 4:
                        temp += value_degree[i - 1];
                        paint.setColor(Color.parseColor("#323C45"));
                        canvas.drawArc(rectf, temp, value_degree[i], true, paint);
                        break;
                }
            }
        }
    }



        @Override
    public boolean onCreateOptionsMenu(Menu menu) {
        // Inflate the menu; this adds items to the action bar if it is present.
        getMenuInflater().inflate(R.menu.main_actvity, menu);
        return true;
    }

    @Override
    public boolean onOptionsItemSelected(MenuItem item) {
        // Handle action bar item clicks here. The action bar will
        // automatically handle clicks on the Home/Up button, so long
        // as you specify a parent activity in AndroidManifest.xml.
        int id = item.getItemId();
        if (id == R.id.action_settings) {
            return true;
        }
        return super.onOptionsItemSelected(item);
    }
}
