package scd.com.imx6packetcapture;

/**
 * Created by sdickson on 8/18/14.
 */
public class Packet
{
    enum pkt_type{ ARP, IPV4, IPv6, VLAN, OTHER }

    public Packet(pkt_type type, int num)
    {
        this.type = type;
        this.num = num;
    }

    pkt_type type;
    int num;
}
