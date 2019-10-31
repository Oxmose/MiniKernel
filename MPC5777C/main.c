#include "processor.h"
#include "output.h"

#define RSTVEC_VLE 1
#define RSTVEC_RESET 0x2
#define RSTVEC_RST_MASK 0xFFFFFFFC

#define SIU_BASE_ADDR     0xC3F90000
#define RST_VECTCORE1_OFF 0x9B0

void main(void) 
{
    int32_t pid = mfspr(286);
    uint32_t* rst_vect_c1 = (uint32_t*)(SIU_BASE_ADDR + RST_VECTCORE1_OFF);
    if(pid == 0)
    {
        output_str("Core 0 started, launching Core 1\n", SERIAL);
        *rst_vect_c1 = ((uint32_t)&main & RSTVEC_RST_MASK) | RSTVEC_VLE;
        while(1);
    }
    else 
    {
        output_str("Core 1 started\n", SERIAL);
        while(1);
    }
}