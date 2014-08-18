package scd.com.imx6packetcapture;

import android.content.Context;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.BaseAdapter;
import android.widget.LinearLayout;
import android.widget.RelativeLayout;
import android.widget.TextView;

import java.util.ArrayList;

/**
 * Created by sdickson on 8/18/14.
 */
public class PktListAdapter extends BaseAdapter
{
    Context context;
    LayoutInflater inflater;
    public ArrayList<Packet> packets;

    public PktListAdapter(Context context, ArrayList<Packet> packets)
    {
        this.context = context;
        this.packets = packets;
    }

    public int getCount()
    {
        return packets.size();
    }

    public Object getItem(int position)
    {
        return packets.get(position);
    }

    public long getItemId(int position)
    {
        return position;
    }

    public View getView(int position, View convertView, ViewGroup parent)
    {
        inflater = (LayoutInflater) context.getSystemService(Context.LAYOUT_INFLATER_SERVICE);
        View itemView = inflater.inflate(R.layout.pkt_list_row, parent, false);
        LinearLayout row = (LinearLayout) itemView.findViewById(R.id.pkt_row);
        TextView num = (TextView) itemView.findViewById(R.id.packet_num);
        TextView type = (TextView) itemView.findViewById(R.id.packet_type);

        Packet item = (Packet) getItem(position);
        int id = 0;

        switch(item.type)
        {
            case ARP:
                id = context.getResources().getIdentifier("scd.com.imx6packetcapture:drawable/rect_blue", null, null);
                type.setText("Packet Type: ARP");
                break;
            case IPV4:
                id = context.getResources().getIdentifier("scd.com.imx6packetcapture:drawable/rect_red", null, null);
                type.setText("Packet Type: IPv4");
                break;
            case IPv6:
                id = context.getResources().getIdentifier("scd.com.imx6packetcapture:drawable/rect_green", null, null);
                type.setText("Packet Type: IPv6");
                break;
            case VLAN:
                id = context.getResources().getIdentifier("scd.com.imx6packetcapture:drawable/rect_purple", null, null);
                type.setText("Packet Type: VLAN Frame");
                break;
            default:
                id = context.getResources().getIdentifier("scd.com.imx6packetcapture:drawable/rect_gray", null, null);
                type.setText("Packet Type: Other");
                break;
        }

        row.setBackgroundResource(id);
        num.setText("(" + item.num + ")");

        return itemView;
    }
}
