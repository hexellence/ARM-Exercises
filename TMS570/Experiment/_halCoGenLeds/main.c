#include "HL_gio.h"

int main(void)
{
/* USER CODE BEGIN (3) */
    uint32 switchA = 0;
/* USER CODE END */
    gioInit();
    while(1)
    {
        switchA = gioGetBit(gioPORTB, 4);
        gioSetBit(gioPORTB, 7, switchA);
        switchA = (switchA == 1) ? 0 : 1;
        gioSetBit(gioPORTB, 6, switchA);
    }
    return 0;
}

