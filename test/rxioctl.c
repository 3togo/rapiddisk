/* rxio.c */

/** This file is licensed under GPLv2.
 **
 ** This program is free software; you can redistribute it and/or
 ** modify it under the terms of the GNU General Public License as
 ** published by the Free Software Foundation; either version 2 of the
 ** License, or (at your option) any later version.
 **
 ** This program is distributed in the hope that it will be useful, but
 ** WITHOUT ANY WARRANTY; without even the implied warranty of
 ** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 ** General Public License for more details.
 **
 ** You should have received a copy of the GNU General Public License
 ** along with this program; if not, write to the Free Software
 ** Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307
 ** USA
 **/


#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/ioctl.h>
#include <linux/fs.h>
#include <errno.h>
#include <string.h>
#include <malloc.h>

#define RXD_GET_STATS     0x0529

int main (){
    int fd, max_sectors;

    if((fd = open("/dev/rxd0", O_WRONLY)) < 0){
        printf("%s\n", strerror(errno));
        return errno;
    }

    if(ioctl(fd, RXD_GET_STATS, &max_sectors) == -1){
        printf("%s\n", strerror(errno));
        return errno;
    }else{
        printf("max sectors allocated: %d\n", max_sectors);
    }

    close (fd);

    return 0;
}
