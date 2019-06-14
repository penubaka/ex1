//TRANSMISSION CODE


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#include <net/if.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/ioctl.h>

#include <linux/can.h>
#include <linux/can/raw.h>

int main()
{
        int s,i=0,j;
        int nbytes;
        struct sockaddr_can addr;
        struct can_frame frame;
        struct ifreq ifr;

        const char *ifname = "vcan0";

        if((s = socket(PF_CAN, SOCK_RAW, CAN_RAW)) < 0) {
                perror("Error while opening socket");
                return -1;
        }

        strcpy(ifr.ifr_name, ifname);
        ioctl(s, SIOCGIFINDEX, &ifr);

        addr.can_family  = PF_CAN;
        addr.can_ifindex = ifr.ifr_ifindex;

        printf("%s at index %d\n", ifname, ifr.ifr_ifindex);

        if(bind(s, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
                perror("Error in socket bind");
                return -2;
        }


        frame.can_id=0x123;
        frame.can_dlc = 4;
        for(i=0;i<frame.can_dlc;i++)
        {
 scanf("%d",&j);

        frame.data[i]=j;
}
        nbytes = write(s, &frame, sizeof(struct can_frame));

        printf("Wrote %d bytes\n", nbytes);
        return 0;
}
