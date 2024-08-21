#ifndef __MYDSP_H__
#define __MYDSP_H__

#include "math.h"
#include "stdint.h"
#include "stdio.h"

#define DATA_TYPE				float			////�����������(�����Ǹ�����float��double)

#define PI						3.14159265358979f

typedef struct {
	DATA_TYPE real;
	DATA_TYPE imag;
}ComplexNumTypeDef;

typedef struct {
	uint16_t DATA_LENTH;			//���ݳ���
	uint16_t DATA_POWER;			//������2�ļ�����
}FFTInitTypeDef;

ComplexNumTypeDef set_complex_num_ri(DATA_TYPE RealNum, DATA_TYPE ImagNum);

void FFT_init(FFTInitTypeDef* FFTstruct, uint16_t Lenth);
void base_2_FFT(FFTInitTypeDef FFTstruct, ComplexNumTypeDef* FFTbuf);
void get_fft_modular(uint16_t lenth, ComplexNumTypeDef* FFTbuf, DATA_TYPE* pOutputArr);
float get_fftpoint_frequency(uint16_t lenth, uint16_t index, float fs);
void base_2_iFFT(FFTInitTypeDef FFTstruct, ComplexNumTypeDef* iFFTbuf);

typedef struct {
	uint16_t L_long;	//L = 2^m >= M + N - 1
	uint16_t N_long;	//�������ݳ���
	uint16_t M_long;	//��������ݳ���
	float Fs;			//����Ƶ��
	float F1;			//ɨƵ������
	float F2;			//ɨƵ������
}CZTInitTypeDef;

#define FFT_CONFIG			FFTInitTypeDef			//��������

#define FFT_Init(config,lenth)				FFT_init(config, lenth)//��Ӧ�û��Զ����FFT��ʼ������
#define FFT_Tranform(config,FFTbuf)			base_2_FFT(*config, FFTbuf)	//��Ӧ�û��Զ���FFTʵ�ֺ���
#define iFFT_Init(config,lenth)				FFT_init(config, lenth)
#define iFFT_Tranform(config,iFFTbuf)		base_2_iFFT(*config, iFFTbuf)

#define CZT_cos(x)			cos(x)		//cos����
#define CZT_sin(x)			sin(x)		//sin����
#define CZT_pow(x,y)		pow(x,y)	//pow����
#define CZT_log(x)			log(x)		//log����

void CZT_Init(CZTInitTypeDef* CZTStruct, uint16_t L, uint16_t M, uint16_t N, float fs, float f1, float f2);
void base_FFT_CZT(CZTInitTypeDef CZTStruct, FFT_CONFIG* FFTconig, ComplexNumTypeDef* outputbuf, ComplexNumTypeDef* inputbuf);
float get_cztpoint_frequency(CZTInitTypeDef CZTStruct, uint16_t index);

#endif // !__MYDSP_H__

