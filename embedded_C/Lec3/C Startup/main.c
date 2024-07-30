//Ahmed Emad
typedef volatile unsigned int vuint32_t;
#include <stdint.h>
//register address
#define RCC_BASE        0X40021000
#define GPIOA_BASE      0X40010800
#define RCC_APB2ENR     *(volatile uint32_t *)(RCC_BASE+0x18)
#define GPIOA_CRH       *(volatile uint32_t *)(GPIOA_BASE+0x04)
#define GPIOA_ODR       *(volatile uint32_t *)(GPIOA_BASE+0x0C)
//bit fields
#define RCC_IOPAEN      (1<<2)
#define GPIOA13         (1UL<<13)

typedef union {
    vuint32_t all_fields;
    struct{
        vuint32_t reserved:13;
        vuint32_t P_13:1;
    } Pin;
} R_ODR_t;

volatile R_ODR_t* R_ODR = (GPIOA_BASE+0x0C);
unsigned char g_variables[3] = {1,2,3};
unsigned char const const_variables[3] = {1,2,3};
char uninitalized1 = 5;
static char uninitalized2 = 6;
static char uninitalized3;
static char uninitalized4;
char uninitalized5;
char uninitalized6;
int main(void){
	uninitalized1;
	uninitalized2;
	uninitalized3;
	uninitalized4;
	uninitalized5;
	uninitalized6;
    int i;
    RCC_APB2ENR |= RCC_IOPAEN;
    GPIOA_CRH &= 0xFF0FFFFF;
    GPIOA_CRH |= 0x00200000;
    while(1){
        R_ODR->Pin.P_13 = 1;
        for(i=0;i<5000;i++);
        R_ODR->Pin.P_13 = 0;
        for(i=0;i<5000;i++);
    }
}