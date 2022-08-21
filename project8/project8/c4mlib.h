
// build info: 
//   version  : 3.1.0
//   time     : 07/02/2019 11:10:29
//   device   : asam128
//   platform : avr
//   mcu      : atmega128
//   fcpu     : 11059200

// developed by MVMC-lab

// you can get lastest version at https://gitlab.com/MVMC-lab/c4mlib/c4mlib/tags

#ifndef C4MLIB_H
#define C4MLIB_H


#include <avr/io.h>
#include <util/delay.h>
#include <stdint.h>
#include <stdio.h>


#include "interrupt.cfg"
#include "remo_reg.cfg"

/*-- hardware section start --------------------------------------------------*/
char ACOMP_set(char LSByte, char Mask, char Shift, char Data);
char ACOMP_fpt(char LSByte, char Mask, char Shift, char Data);
char ACOMP_fgt(char LSByte, char Mask, char Shift, void *Data_p);
char ACOMP_put(char LSbyte, char Bytes, void *Data_p);
char ACOMP_get(char LSByte, char Bytes, void *Data_p);

char ADC_set(char LSByte, char Mask, char Shift, char Data);
char ADC_fpt(char LSByte, char Mask, char Shift, char Data);
char ADC_fgt(char LSByte, char Mask, char Shift, void *Data_p);
char ADC_put(char LSbyte, char Bytes, void *Data_p);
char ADC_get(char LSByte, char Bytes, void *Data_p);

void EEPROM_set(int Address, char Bytes, void *Data_p);
void EEPROM_get(int Address, char Bytes, void *Data_p);

char SPI_set(char LSByte, char Mask, char Shift, char Data);
char SPI_fpt(char LSByte, char Mask, char Shift, char Data);
char SPI_fgt(char LSByte, char Mask, char Shift, void *Data_p);
char SPI_put(char LSbyte, char Bytes, void *Data_p);
char SPI_get(char LSByte, char Bytes, void *Data_p);

char TIM_set(char LSByte, char Mask, char Shift, char Data);
char TIM_fpt(char LSByte, char Mask, char Shift, char Data);
char TIM_fgt(char LSByte, char Mask, char Shift, void *Data_p);
char TIM_put(char LSbyte, char Bytes, void *Data_p);
char TIM_get(char LSByte, char Bytes, void *Data_p);

char TWI_set(char LSByte, char Mask, char Shift, char Data);
char TWI_fpt(char LSByte, char Mask, char Shift, char Data);
char TWI_fgt(char LSByte, char Mask, char Shift, void *Data_p);
char TWI_put(char LSbyte, char Bytes, void *Data_p);
char TWI_get(char LSByte, char Bytes, void *Data_p);

char UART_set(char LSByte, char Mask, char Shift, char Data);
char UART_fpt(char LSByte, char Mask, char Shift, char Data);
char UART_fgt(char LSByte, char Mask, char Shift, void *Data_p);
char UART_put(char LSbyte, char Bytes, void *Data_p);
char UART_get(char LSByte, char Bytes, void *Data_p);

char DIO_set(char LSByte, char Mask, char Shift, char Data);
char DIO_fpt(char LSByte, char Mask, char Shift, char Data);
char DIO_fgt(char LSByte, char Mask, char Shift, void *Data_p);
char DIO_put(char LSbyte, char Bytes, void *Data_p);
char DIO_get(char LSByte, char Bytes, void *Data_p);

char EXT_set(char LSByte, char Mask, char Shift, char Data);
char EXT_fpt(char LSByte, char Mask, char Shift, char Data);
char EXT_fgt(char LSByte, char Mask, char Shift, void *Data_p);

#include <avr/interrupt.h>
#undef ISR
#ifdef __cplusplus
#  define ISR(vector, ...)            \
    extern "C" void vector ## _routine (void) __attribute__ ((__INTR_ATTRS)) __VA_ARGS__; \
    void vector ## _routine (void)
#else
#  define ISR(vector, ...)            \
    void vector ## _routine (void) __attribute__ ((__INTR_ATTRS)) __VA_ARGS__; \
    void vector ## _routine (void)
#endif
/*-- hardware section end ----------------------------------------------------*/

/*-- device section start ----------------------------------------------------*/
void ASA_DEVICE_set(void);
/*-- device section end ------------------------------------------------------*/

/*-- stdio section start -----------------------------------------------------*/
void ASA_STDIO_init(void);
/*-- stdio section end -------------------------------------------------------*/

/*-- macro section start -----------------------------------------------------*/
typedef void (*Func_t)(void *);
/*-- macro section end -------------------------------------------------------*/

/*-- asabus section start ----------------------------------------------------*/
void ASABUS_ID_init(void);
void ASABUS_ID_set(char id);

//void ASABUS_UART_init(void);
//void ASABUS_UART_transmit(char data);
//char ASABUS_UART_receive(void);

void ASABUS_SPI_init(void);
char ASABUS_SPI_swap(char data);
/*-- asabus section end ------------------------------------------------------*/

/*-- asahmi section start ----------------------------------------------------*/
// HMI macro
#define HMI_TYPE_I8   0  ///< 資料型態編號 0，int8_t、char                @ingroup hmi_type_macro
#define HMI_TYPE_I16  1  ///< 資料型態編號 1，int16_t、int                @ingroup hmi_type_macro
#define HMI_TYPE_I32  2  ///< 資料型態編號 2，int32_t、long int           @ingroup hmi_type_macro
#define HMI_TYPE_I64  3  ///< 資料型態編號 3，int64_t                     @ingroup hmi_type_macro
#define HMI_TYPE_UI8  4  ///< 資料型態編號 4，uint8_t、unsigned char      @ingroup hmi_type_macro
#define HMI_TYPE_UI16 5  ///< 資料型態編號 5，uint16_t、unsigned int      @ingroup hmi_type_macro
#define HMI_TYPE_UI32 6  ///< 資料型態編號 6，uint32_t、unsigned long int @ingroup hmi_type_macro
#define HMI_TYPE_UI64 7  ///< 資料型態編號 7，uint64_t                    @ingroup hmi_type_macro
#define HMI_TYPE_F32  8  ///< 資料型態編號 8，float、double               @ingroup hmi_type_macro
#define HMI_TYPE_F64  9  ///< 資料型態編號 9，AVR不支援64位元浮點數       @ingroup hmi_type_macro

// HMI declaration
char HMI_put_array(char Type, char Num, void *Data_p);
char HMI_get_array(char Type, char Num, void *Data_p);

char HMI_put_matrix(char Type, char Dim1, char Dim2, void *Data_p);
char HMI_get_matrix(char Type, char Dim1, char Dim2, void *Data_p);

char HMI_put_struct(char *FormatString, int Bytes, void *Data_p);
char HMI_get_struct(char *FormatString, int Bytes, void *Data_p);

char HMI_snput_array(char Type, char Num, void *Data_p);
char HMI_snget_array(char Type, char Num, void *Data_p);

char HMI_snput_matrix(char Type, char Dim1, char Dim2, void *Data_p);
char HMI_snget_matrix(char Type, char Dim1, char Dim2, void *Data_p);

char HMI_snput_struct(char *FormatString, int Bytes, void *Data_p);
char HMI_snget_struct(char *FormatString, int Bytes, void *Data_p);
/*-- asahmi section end ------------------------------------------------------*/

/*-- asatwi section start ----------------------------------------------------*/
/**
 * @brief ASA TWI 送訊函式
 *
 * @param mode      TWI通訊模式:    目前支援:1, 2, 3, 4, 5
 * @param SLA       TWI僕ID:        目標裝置的TWI ID
 * @param RegAdd    暫存器地址:      要送往的暫存器地址
 * @param Bytes     位元組數:     待送位元組數
 * @param Data_p    待送資料:     待送資料指標
 * @return  0:  通訊成功
 *          1:  Timeout
 *          4:  SLA錯誤
 */
char ASA_TWIM_trm(char mode, char SLA, char RegAdd, char Bytes,
                  uint8_t *Data_p);
/**
 * @brief ASA TWI 收訊函式
 *
 * @param mode      TWI通訊模式:    目前支援:1, 2, 3, 4, 5
 * @param SLA       TWI僕ID:        目標裝置的TWI ID
 * @param RegAdd    暫存器地址:      要送往的暫存器地址
 * @param Bytes     位元組數:       待送位元組數
 * @param Data_p    待讀資料:       待讀資料的地址指標
 * @return  0:  通訊成功
 *          1:  Timeout
 *          4:  SLA錯誤
 */
char ASA_TWIM_rec(char mode, char SLA, char RegAdd, char Bytes,
                  uint8_t *Data_p);
/**
 * @brief
 *
 * @param mode      TWI通訊模式:    目前支援:4
 * @param SLA       TWI僕ID:        目標裝置的TWI ID
 * @param RegAdd    暫存器地址:      要送往的暫存器地址
 * @param Mask      資料遮罩:       過濾出目標位元
 * @param Shift     資料位移:       位移指定位元
 * @param Data_p    待送資料:       待送資料指標
 * @return  0:  通訊成功
 *          1:  Timeout
 *          4:  SLA錯誤
 *          5:  mode選擇錯誤
 */
char ASA_TWIM_ftm(char mode, char SLA, char RegAdd, char Mask, char Shift,
                     uint8_t *Data_p);
/**
 * @brief
 *
 * @param mode      TWI通訊模式:    目前支援:4
 * @param SLA       TWI僕ID:        目標裝置的TWI ID
 * @param RegAdd    暫存器地址:      要送往的暫存器地址
 * @param Mask      資料遮罩:       過濾出目標位元
 * @param Shift     資料位移:       位移指定位元
 * @param Data_p    待讀資料:       待讀資料的地址指標
 * @return  0:  通訊成功
 *          1:  Timeout
 *          4:  SLA錯誤
 *          5:  mode選擇錯誤
 */
char ASA_TWIM_frc(char mode, char SLA, char RegAdd, char Mask, char Shift,
                     uint8_t *Data_p);

/**
 * @brief 串列埠中斷執行片段
 */
void *ASA_TWIS_txrx1(void);
void *ASA_TWIS_txrx2(void);
void *ASA_TWIS_txrx3(void);
void *ASA_TWIS_txrx4(void);
void *ASA_TWIS_txrx5(void);
/*-- asatwi section end ------------------------------------------------------*/

/*-- asaspi section start ----------------------------------------------------*/
char ASA_SPIM_trm(char mode, char ASAID, char RegAdd, char Bytes, void *Data_p);
char ASA_SPIM_rec(char mode, char ASAID, char RegAdd, char Bytes, void *Data_p);
char ASA_SPIM_frc(char mode, char ASAID, char RegAdd, char Mask, char Shift, char *Data_p);
char ASA_SPIM_ftm(char mode, char ASAID, char RegAdd, char Mask, char Shift, char *Data_p);

void SPIS_setMode(uint8_t _mode);
void SPIS0_cb(void);
void SPIS1_cb(void);
void SPIS2_cb(void);
void SPIS3_cb(void);
void SPIS4_cb(void);
void SPIS5_cb(void);
void SPIS6_cb(void);
void SPIS7_cb(void);
void SPIS8_cb(void);
/*-- asaspi section end ------------------------------------------------------*/

/*-- interrupt section start -------------------------------------------------*/
typedef struct {
    volatile uint8_t postSlot;  // POST是否有新中斷之公告欄
    volatile uint8_t enable;    // 禁致能控制決定本中斷中執行函式是否致能
    Func_t func_p;              // 中斷中執行函式
    void* funcPara_p;            // 中斷中執行函式之傳參
} TypeOfISRFunc;

typedef struct {
    const uint8_t EXTI_UID;                           // 紀錄本結構歸屬UID，用於init()函式判斷鏈接目標
    uint8_t total;                                    // 紀錄已有多少逾時中斷已註冊
    volatile TypeOfISRFunc task[MAX_EXTINT_FuncNum];  // 紀錄所有已註冊的外部中斷
} TypeOfExtInt;

// Initialize the TypeOfExtInt struct
void ExtInt_init(TypeOfExtInt* extInt_p);

// Register EXT Isr instance
uint8_t ExtInt_reg(TypeOfExtInt* extInt_p, Func_t isrFunc_p, void* isrFuncPara_p);

// Control EXT Isr
void ExtInt_en(TypeOfExtInt* extInt_p, uint8_t isr_id, uint8_t enable);

typedef struct {
    const uint8_t TIM_UID;                         // 紀錄本結構歸屬UID，用於init()函式判斷鏈接目標
    uint8_t total;                                 // 紀錄已註冊多少計時中斷
    volatile TypeOfISRFunc task[MAX_TIM_FuncNum];  // 紀錄所有已註冊的計時中斷
} TypeOfTimInt;

// Initialize the TypeOfTimInt struct
void TimInt_init(TypeOfTimInt* timInt_p);

// Register TIM Isr instance
uint8_t TimInt_reg(TypeOfTimInt* timInt_p, Func_t isrFunc_p, void* isrFuncPara_p);

// Change the Enable/Disable configure for specific Isr task object
void TimInt_en(TypeOfTimInt* timInt_p, uint8_t isr_id, uint8_t enable);
/*-- interrupt section end ---------------------------------------------------*/

/*-- time section start ------------------------------------------------------*/
#define MAX_TIMEOUT_ISR 20

typedef void (*ISRFunc)(void);
typedef struct {
    volatile uint16_t time_limit;  // 時間限制        當計數器上數到該數值時觸發逾時中斷
    volatile uint16_t counter;     // 計數器          計數器固定頻率上數
    volatile uint8_t* p_postSlot;  // POST欄住址      一指標指向POST欄住址，為POST & SLOT機制的子元件
    volatile uint8_t enable;       // 禁致能控制      決定本逾時ISR是否致能
    ISRFunc p_ISRFunc;             // 逾時中斷函式    逾時中斷函式指標
} TimeoutISR_t;

typedef struct {
    uint8_t total;                                           // 紀錄已有多少逾時中斷已註冊
    volatile TimeoutISR_t timeoutISR_inst[MAX_TIMEOUT_ISR];  // 紀錄所有已註冊的逾時中斷資料結構
} TimerCntStrType;
volatile TimerCntStrType TimerCntStr_inst;
/*-- time section end --------------------------------------------------------*/


#endif // C4MLIB_H
