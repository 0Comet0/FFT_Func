#ifndef __MYDSP_H__
#define __MYDSP_H__

#include "math.h"
#include "stdint.h"
#include "stdio.h"

#define DATA_TYPE				float			////你的数据类型(必须是浮点数float或double)

#define PI						3.14159265358979f

typedef struct {
	DATA_TYPE real;
	DATA_TYPE imag;
}ComplexNumTypeDef;

typedef struct {
	uint16_t DATA_LENTH;			//数据长度
	uint16_t DATA_POWER;			//数据是2的几次幂
}FFTInitTypeDef;

ComplexNumTypeDef set_complex_num_ri(DATA_TYPE RealNum, DATA_TYPE ImagNum);

void FFT_init(FFTInitTypeDef* FFTstruct, uint16_t Lenth);
void base_2_FFT(FFTInitTypeDef FFTstruct, ComplexNumTypeDef* FFTbuf);
void get_fft_modular(uint16_t lenth, ComplexNumTypeDef* FFTbuf, DATA_TYPE* pOutputArr);
float get_fftpoint_frequency(uint16_t lenth, uint16_t index, float fs);
void base_2_iFFT(FFTInitTypeDef FFTstruct, ComplexNumTypeDef* iFFTbuf);

typedef struct {
	uint16_t L_long;	//L = 2^m >= M + N - 1
	uint16_t N_long;	//输入数据长度
	uint16_t M_long;	//输出的数据长度
	float Fs;			//采样频率
	float F1;			//扫频左区间
	float F2;			//扫频右区间
}CZTInitTypeDef;

#define FFT_CONFIG			FFTInitTypeDef			//变量类型

#define FFT_Init(config,lenth)				FFT_init(config, lenth)//对应用户自定义的FFT初始化函数
#define FFT_Tranform(config,FFTbuf)			base_2_FFT(*config, FFTbuf)	//对应用户自定义FFT实现函数
#define iFFT_Init(config,lenth)				FFT_init(config, lenth)
#define iFFT_Tranform(config,iFFTbuf)		base_2_iFFT(*config, iFFTbuf)

#define CZT_cos(x)			cos(x)		//cos函数
#define CZT_sin(x)			sin(x)		//sin函数
#define CZT_pow(x,y)		pow(x,y)	//pow函数
#define CZT_log(x)			log(x)		//log函数

void CZT_Init(CZTInitTypeDef* CZTStruct, uint16_t L, uint16_t M, uint16_t N, float fs, float f1, float f2);
void base_FFT_CZT(CZTInitTypeDef CZTStruct, FFT_CONFIG* FFTconig, ComplexNumTypeDef* outputbuf, ComplexNumTypeDef* inputbuf);
float get_cztpoint_frequency(CZTInitTypeDef CZTStruct, uint16_t index);

#endif // !__MYDSP_H__

