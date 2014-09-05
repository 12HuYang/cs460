#include "ext2.h"

typedef struct ext2_group_desc GD;
typedef struct ext2_inode INODE;
typedef struct ext2_dir_entry_2 DIR;

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned long u32;

#define BLK 1024

GD *gp;
INODE *ip;
DIR *dp;

int prints(char *s)
{
    while(*s) { putc(*s++);}
    return 1;
}

int gets(char s[])
{
  while((*s = getc()) != '\r') { putc(*s++); }
  *s = 0;
  prints("\n\r");
  return 1;
}

u16 get_block(int blk, char buf[])
{
    //convert blk to (cyl, head, sector)
    blk *= 2;
    readfd(blk/36, (blk%36)/18, blk %18, buf);
    return 1;
}

int main() 
{
    u16 i, iblk;
    char buf1[BLK], buf2[BLK];

    prints("booter start\n\r");

    /* read blk#2 to get group descriptor 0 */
    getblk((u16)2, buf1);
    gp = (GD *)buf1;
    iblk = (u16)gp->bg_inode_table; // typecase u32 to u16
    prints("inode_block="); putc(iblk+'0'); getc();

    // 1. Read first indoe block into buf1[]

    //2. Let ip point to root INODE (inode #2)

    //3. For each DIRECT block of / do:
        // Read data block into buf2[];
        // Step through the data block to print the names of dir entries

    //4. prints("\n\rAll done\n\r");
}
