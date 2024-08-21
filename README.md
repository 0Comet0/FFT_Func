# 简介

此算法是本人大二下学习数字信号处理心血来潮写的，还有诸多可改进的地方。

这个算法是基-2的快速傅里叶算法，输入为顺序输入，输出也为顺序输出。包含的功能有：

+ FFT
+ iFFT
+ CZT扫频(不是完全的CZT)

算法都已经在Matlab和单片机上进行过了验证，如有细小误差，是精度的问题。

**此套代码兼容STM32的官方DSP库，可以使用里面的FFT算法计算CZT扫频。**

# 使用方法

### 一、FFT

初始化函数：

```C
/**
 * @brief     给FFTInitTypeDef初始化
 * @param[in] FFTInitTypeDef* FFTstruct    要配置的结构体
 * @param[in] uint16_t Lenth               输入数据的长度
 * @return    无
 * @note      注意：Lenth必须是2的幂
 */
void FFT_init(FFTInitTypeDef* FFTstruct, uint16_t Lenth);
```

启动函数：

```c
/**
 * @brief      基-2 按时间抽选FFT，返回的是复数
 * @param[in]  FFTInitTypeDef FFTstruct     配置好的结构体
 * @param[out] ComplexNumTypeDef* FFTbuf    输出数据的存放位置(长度与输入数据的长度一样)
 * @return     无
 */
void base_2_FFT(FFTInitTypeDef FFTstruct, ComplexNumTypeDef* FFTbuf);
```

### 二、iFFT

初始化函数(与FFT一样)：

```c
/**
 * @brief     给FFTInitTypeDef初始化
 * @param[in] FFTInitTypeDef* FFTstruct    要配置的结构体
 * @param[in] uint16_t Lenth               输入数据的长度
 * @return    无
 * @note      注意：Lenth必须是2的幂
 */
void FFT_init(FFTInitTypeDef* FFTstruct, uint16_t Lenth);
```

启动函数：

```c
/**
 * @brief 基-2 按时间抽选iFFT，返回的是复数
 * @param[in] FFTInitTypeDef FFTstruct       配置好的结构体
 * @param[out] ComplexNumTypeDef* iFFTbuf    输出数据的存放位置(长度与输入数据的长度一样)
 * @return 无
 */
void base_2_iFFT(FFTInitTypeDef FFTstruct, ComplexNumTypeDef* iFFTbuf)；
```

### 三、CZT扫频

初始化函数：

```c
/**
 * @brief CZT初始化
 * @param[in] CZTInitTypeDef* CZTStruct
 * @param[in] uint16_t L	总长度
 * @param[in] uint16_t M	输出长度
 * @param[in] uint16_t N	输入长度
 * @param[in] float fs		采样频率
 * @param[in] float f1		左截止频率
 * @param[in] float f2		右截止频率
 * @return 无
 * @note                     f2必须大于f1，且L必须是2的幂
 */
void CZT_Init(CZTInitTypeDef* CZTStruct, uint16_t L, uint16_t M, uint16_t N, float fs, float f1, float f2)；
```

启动函数：

```c
/**
 * @brief 基-2 FFT/iFFT 的CZT扫频细化
 * @param[in]	CZTInitTypeDef* CZTStruct
 * @param[out]	ComplexNumTypeDef *outputbuf
 * @param[in]	ComplexNumTypeDef* inputbuf
 * @return	无
 * @date	2024/7/26
 * @note	此处输入输出都得是长度为L，取数据时，只从outputbuf取前M个点即可
 */
void base_FFT_CZT(CZTInitTypeDef CZTStruct, FFT_CONFIG *FFTconig, ComplexNumTypeDef *outputbuf, ComplexNumTypeDef* inputbuf)
```

