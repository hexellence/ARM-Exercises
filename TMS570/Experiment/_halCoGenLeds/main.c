#include "HL_gio.h"
#include "HL_adc.h"

adcData_t  data[16];

int main(void)
{
/* USER CODE BEGIN (3) */
    uint32 switchA = 0;
    uint32 ch_count = 0;

/* USER CODE END */
    gioInit();

    adcInit();
    adcStartConversion(adcREG1,adcGROUP1);


    while(1)
    {
        while(adcIsConversionComplete(adcREG1,adcGROUP1)==0);
        ch_count = adcGetData(adcREG1, adcGROUP1, data);

        switchA = gioGetBit(gioPORTB, 4);
        gioSetBit(gioPORTB, 7, switchA);
        switchA = (switchA == 1) ? 0 : 1;
        gioSetBit(gioPORTB, 6, switchA);
    }
    return 0;
}

