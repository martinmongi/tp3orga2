/* ** por compatibilidad se omiten tildes **
================================================================================
 TRABAJO PRACTICO 3 - System Programming - ORGANIZACION DE COMPUTADOR II - FCEN
================================================================================
  definicion de la tabla de descriptores globales
*/

#include "gdt.h"

gdt_entry gdt[GDT_COUNT] = {
    /* Descriptor nulo*/
    /* Offset = 0x00 */
    [GDT_IDX_NULL_DESC] = (gdt_entry) {
        (unsigned short)    0x0000,         /* limit[0:15]  */
        (unsigned short)    0x0000,         /* base[0:15]   */
        (unsigned char)     0x00,           /* base[23:16]  */
        (unsigned char)     0x00,           /* type         */
        (unsigned char)     0x00,           /* s            */
        (unsigned char)     0x00,           /* dpl          */
        (unsigned char)     0x00,           /* p            */
        (unsigned char)     0x00,           /* limit[16:19] */
        (unsigned char)     0x00,           /* avl          */
        (unsigned char)     0x00,           /* l            */
        (unsigned char)     0x00,           /* db           */
        (unsigned char)     0x00,           /* g            */
        (unsigned char)     0x00,           /* base[31:24]  */
    },

    [9] = (gdt_entry) { //(codigo de kernel)
        (unsigned short)    0xDCFF,         /* limit[0:15]  */
        (unsigned short)    0x0000,         /* base[0:15]   */
        (unsigned char)     0x00,           /* base[23:16]  */
        (unsigned char)     0xA,           /* type         */
        (unsigned char)     0x1,           /* s            */
        (unsigned char)     0x0,           /* dpl          */
        (unsigned char)     0x00,           /* p            */
        (unsigned char)     0x2,           /* limit[16:19] */
        (unsigned char)     0x00,           /* avl          */
        (unsigned char)     0x00,           /* l            */
        (unsigned char)     0x1,           /* db           */
        (unsigned char)     0x1,           /* g            */
        (unsigned char)     0x00,           /* base[31:24]  */
    },

    [10] = (gdt_entry) { //(codigo de usuario)
        (unsigned short)    0xDCFF,         /* limit[0:15]  */
        (unsigned short)    0x0000,         /* base[0:15]   */
        (unsigned char)     0x00,           /* base[23:16]  */
        (unsigned char)     0xA,           /* type         */
        (unsigned char)     0x1,           /* s            */
        (unsigned char)     0x3,            /* dpl          */
        (unsigned char)     0x00,           /* p            */
        (unsigned char)     0x2,           /* limit[16:19] */
        (unsigned char)     0x00,           /* avl          */
        (unsigned char)     0x00,           /* l            */
        (unsigned char)     0x1,           /* db           */
        (unsigned char)     0x1,           /* g            */
        (unsigned char)     0x00,           /* base[31:24]  */
    },

    [11] = (gdt_entry) { //(dato de kernel y pila del kernel)
        (unsigned short)    0xDCFF,         /* limit[0:15]  */
        (unsigned short)    0x0000,         /* base[0:15]   */
        (unsigned char)     0x00,           /* base[23:16]  */
        (unsigned char)     0x2,           /* type         */
        (unsigned char)     0x1,           /* s            */
        (unsigned char)     0x0,            /* dpl          */
        (unsigned char)     0x00,           /* p            */
        (unsigned char)     0x2,           /* limit[16:19] */
        (unsigned char)     0x00,           /* avl          */
        (unsigned char)     0x00,           /* l            */
        (unsigned char)     0x1,           /* db           */
        (unsigned char)     0x1,           /* g            */
        (unsigned char)     0x00,           /* base[31:24]  */
    },

    [12] = (gdt_entry) { //(dato de usuario)
        (unsigned short)    0xDCFF,         /* limit[0:15]  */
        (unsigned short)    0x0000,         /* base[0:15]   */
        (unsigned char)     0x00,           /* base[23:16]  */
        (unsigned char)     0x2,           /* type         */
        (unsigned char)     0x1,           /* s            */
        (unsigned char)     0x3,            /* dpl          */
        (unsigned char)     0x00,           /* p            */
        (unsigned char)     0x2,           /* limit[16:19] */
        (unsigned char)     0x00,           /* avl          */
        (unsigned char)     0x00,           /* l            */
        (unsigned char)     0x1,           /* db           */
        (unsigned char)     0x1,           /* g            */
        (unsigned char)     0x00,           /* base[31:24]  */
    },

    // [13] = (gdt_entry) { //(area de la pantalla 1c)
    //     (unsigned short)    0x1F40,         /* limit[0:15]  */
    //     (unsigned short)    0x0000,         /* base[0:15]   */
    //     (unsigned char)     0x00,           /* base[23:16]  */
    //     (unsigned char)     0x2,           /* type         */
    //     (unsigned char)     0x1,           /* s            */
    //     (unsigned char)     0x0,            /* dpl          */
    //     (unsigned char)     0x00,           /* p            */
    //     (unsigned char)     0x0,           /* limit[16:19] */
    //     (unsigned char)     0x00,           /* avl          */
    //     (unsigned char)     0x00,           /* l            */
    //     (unsigned char)     0x1,           /* db           */
    //     (unsigned char)     0x0,           /* g            */
    //     (unsigned char)     0x00,           /* base[31:24]  */
    // } 

};

gdt_descriptor GDT_DESC = {
    sizeof(gdt) - 1,
    (unsigned int) &gdt
};
