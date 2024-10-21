//Ahmed Emad

/* Define base addressies for peripherals */
/*
#define SYSCTL_BASE         0x400FE000
#define GPIO_BASE           0X40025000
*/
/* Define offset for peripherals */
/*
#define SYSCTL_ECGC2_OFFSET        0X108

#define GPIO_PORTF_DIR_OFFSET    0X400
#define GPIO_PORTF_DEN_OFFSET    0X51C
#define GPIO_PORTF_DATA_OFFSET   0X3FC
*/

#define SYSCTL_RCGC2_R (*((volatile unsigned long*) (0x400FE108)))
#define GPIO_PORTF_DEN_R (*((volatile unsigned long*) (0X4002551C)))
#define GPIO_PORTF_DIR_R (*((volatile unsigned long*) (0X40025400)))
#define GPIO_PORTF_DATA_R (*((volatile unsigned long*) (0X400253FC)))

volatile int counter = 0;
void InitalizeGPIOPortF()
{
    /* Enable Port F by poviding clock to it */
    SYSCTL_RCGC2_R |= 0x00000020;
    /* wait for setting to complete */
    for(counter=0;counter<200;counter++);
    /* Enable pin 3 in port F to control it */
    GPIO_PORTF_DEN_R |= 1<<3;
    /* Set Direction of pin 3 in port F to output */
    GPIO_PORTF_DIR_R |= 1<<3;
    /* Set Data of PF3 to low as initial value*/
    GPIO_PORTF_DATA_R &= ~(1<<3);
}

int main()
{
    InitalizeGPIOPortF();
    while(1)
    {
        GPIO_PORTF_DATA_R |= (1<<3);
        for(counter=0;counter<200000;counter++);
        GPIO_PORTF_DATA_R &= ~(1<<3);
        for(counter=0;counter<200000;counter++);
    }
    
    return 0;
}