#include <stdio.h>
#include <stdlib.h>
#include <pcap.h>
#include <sys/types.h>
#include <bluetooth/bluetooth.h>
#include <bluetooth/hci.h>
#include <bluetooth/rfcomm.h>
#include <unistd.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <bluetooth/sdp.h>
#include <bluetooth/sdp_lib.h>

void handle_packet(u_char *args, const struct pcap_pkthdr *header, const u_char *packet);
sdp_session_t *register_service();

#define ETHER_ADDR_LEN 6

struct sniff_ethernet
{
	u_char ether_dhost[ETHER_ADDR_LEN];
	u_char ether_shost[ETHER_ADDR_LEN];
	u_short ether_type;
};

typedef struct packed_int
{
	unsigned char b1;
	unsigned char b2;
	unsigned char b3;
	unsigned char b4;
} packed_int;

typedef union
{
	unsigned int i;
	packed_int b;
} packed;

int cli;
char pktbuf[100];

int main(int argc, char **argv)
{
	struct sockaddr_rc local = {0}, remote = {0};
	char buf[1024];
	int sock, n;
	socklen_t options = sizeof(remote);
	sdp_session_t *session;
	
	//Setup host bluetooth address
	char src_bdaddr[18] = "00:1A:7D:DA:71:13";

	memset(buf, 0, sizeof(buf));
	session = register_service();

	sock = socket(AF_BLUETOOTH, SOCK_STREAM, BTPROTO_RFCOMM);
	local.rc_family = AF_BLUETOOTH;
	str2ba(src_bdaddr, &local.rc_bdaddr);
	local.rc_channel = (uint8_t) 11;
	bind(sock, (struct sockaddr*)&local, sizeof(local));

	listen(sock, 1);

	cli = accept(sock, (struct sockaddr*)&remote, &options);
	ba2str(&remote.rc_bdaddr, buf);
	fprintf(stderr, "Accepted connection from %s\n", buf);

	//set up pcap for capture
	pcap_t *handle;
	char errbuf[PCAP_ERRBUF_SIZE];
	char *pkt;
	char *dev = "eth0";
	struct pcap_pkthdr header;

	handle = pcap_open_live(dev, 64, 1, 500, errbuf);
	
	if(handle == NULL)
	{
		perror("pcap_open_live");
		exit(1);
	}
	
	pcap_loop(handle, -1, handle_packet, NULL);

	
	return 0;
}

//Handle incoming captured packet
void handle_packet(u_char *args, const struct pcap_pkthdr *header, const u_char *packet)
{
	const struct sniff_ethernet *ethernet; 
	ethernet = (struct sniff_ethernet*)(packet);

	char tmp[10];
	switch(ntohs(ethernet->ether_type))
	{
		case 0x0800:
			sprintf(tmp, "%s)\n", "IPv4");
			break;
		case 0x86DD:
			sprintf(tmp, "%s)\n", "IPv6");
			break;
		case 0x0806:
			sprintf(tmp, "%s)\n", "ARP");
			break;
		case 0x8100:
			sprintf(tmp, "%s)\n", "VLAN frame");
			break;
		case 0x0032:
			sprintf(tmp, "%s)\n", "ARP");
			break;
		default:
			sprintf(tmp, "%04x)\n", ntohs(ethernet->ether_type));
			break;
	}

	send(cli, tmp, strlen(tmp), 0);
}

//Register service so Android device can find and connect
sdp_session_t *register_service()
{

    uint32_t svc_uuid_int[] = { 0, 0, 0, 0x3233 };
    uint8_t rfcomm_channel = 11;
    const char *service_name = "i.MX6";
    const char *service_dsc = "i.MX6 Packet Capture";
    const char *service_prov = "Fluke Networks";

    uuid_t root_uuid, l2cap_uuid, rfcomm_uuid, svc_uuid;
    sdp_list_t *l2cap_list = 0, 
               *rfcomm_list = 0,
               *root_list = 0,
               *proto_list = 0, 
               *access_proto_list = 0;
    sdp_data_t *channel = 0, *psm = 0;

    sdp_record_t *record = sdp_record_alloc();

    // set the general service ID
    sdp_uuid128_create( &svc_uuid, &svc_uuid_int );
    sdp_set_service_id( record, svc_uuid );
    sdp_list_t service_class = {NULL, &svc_uuid};
    sdp_set_service_classes( record, &service_class);

    // make the service record publicly browsable
    sdp_uuid16_create(&root_uuid, PUBLIC_BROWSE_GROUP);
    root_list = sdp_list_append(0, &root_uuid);
    sdp_set_browse_groups( record, root_list );

    // set l2cap information
    sdp_uuid16_create(&l2cap_uuid, L2CAP_UUID);
    l2cap_list = sdp_list_append( 0, &l2cap_uuid );
    proto_list = sdp_list_append( 0, l2cap_list );

    // set rfcomm information
    sdp_uuid16_create(&rfcomm_uuid, RFCOMM_UUID);
    channel = sdp_data_alloc(SDP_UINT8, &rfcomm_channel);
    rfcomm_list = sdp_list_append( 0, &rfcomm_uuid );
    sdp_list_append( rfcomm_list, channel );
    sdp_list_append( proto_list, rfcomm_list );

    // attach protocol information to service record
    access_proto_list = sdp_list_append( 0, proto_list );
    sdp_set_access_protos( record, access_proto_list );

    // set the name, provider, and description
    sdp_set_info_attr(record, service_name, service_prov, service_dsc);

    int err = 0;
    sdp_session_t *session = 0;

    // connect to the local SDP server, register the service record, and 
    // disconnect
    session = sdp_connect( BDADDR_ANY, BDADDR_LOCAL, SDP_RETRY_IF_BUSY );
    err = sdp_record_register(session, record, 0);

    // cleanup
    //sdp_data_free( channel );
    sdp_list_free( l2cap_list, 0 );
    sdp_list_free( rfcomm_list, 0 );
    sdp_list_free( root_list, 0 );
    sdp_list_free( access_proto_list, 0 );

    return session;
}
