//#include "gpuacc.cuh"
#include "cuda.h"
#include <iostream>
#include <cufft.h>
#include "cublas_v2.h"
#include <stdio.h>
#include <stdlib.h>

inline void GPUassert(cudaError_t code, char * file, int line, bool Abort = true)
{
	if (code != 0) {
		fprintf(stderr, "GPUassert: %s %s %d\n", cudaGetErrorString(code), file, line);
		if (Abort) exit(code);
	}
}

#define GPUerrchk(ans) { GPUassert((ans), __FILE__, __LINE__); }

__host__ __device__ void swap(char *x, char *y)
{
	char temp;
	temp = *x;
	*x = *y;
	*y = temp;
}

__device__ void combi_device(int s, int n, int cnt, int* sum, int tid)
{
	if (cnt == 10) {
		sum[0] = sum[0] + 1;
		return;
	}
	for (int i = s; i < n; i++) {
		combi_device(i + 1, n, cnt + 1, sum, tid);
	}
}

__global__ void combi_kernel(int* d_A, int size) {

	int tid = threadIdx.x + blockIdx.x * blockDim.x;
	int sum[1]; sum[0] = 0;

	int* local_array = new int[4 * 1000];
	int* visited = new int[4 * 10];

	for (int i = 0; i < 4 * 1000; i++) {
		local_array[i] = 0;
	}
	for (int i = 0; i < 4 * 10; i++) {
		visited[i] = 0;
	}

	combi_device(0, 30, 0, sum, tid);
	printf("Combination count %i, thread nr. %i\n", sum[0], tid);

	delete[] local_array;
	delete[] visited;

}

//void mygputest() {
//	int h_a[1000] = { 0 };
//	int* d_a;
//	cudaMalloc((void**)&d_a, sizeof(h_a));
//	GPUerrchk(cudaMemcpy(d_a, h_a, sizeof(h_a), cudaMemcpyHostToDevice));
//
//	printf("\n\n Combinations on GPU\n");
//	combi_kernel << <1, 1 >> > (d_a, 4);
//	GPUerrchk(cudaPeekAtLastError());
//	GPUerrchk(cudaDeviceSynchronize());
//
//}

const int N = 20;
const int K = 12;

const int SIZE = 70000;
const int CASE = 7000;

//__device__ int SUM[SIZE];
//__device__ int VAL[SIZE];
//__device__ int PRE[SIZE];
//__device__ int MAP[CASE*N*K];
//__device__ int CNT[10][N*K];
//__device__ int wp[10];


__device__ void combi(int tid, int n, int k, int* SUM, int* VAL, int*  PRE, int* MAP, int* CNT, int* wp) {
	wp[tid] = 0;
	for (int i = 0; i < N*K; i++)CNT[tid*N*K + i] = 0;
	int p;
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= k && j <= i; j++) {
			int cnt = 0;
			if (j == 0) {
				PRE[wp[tid]] = 0;
				VAL[wp[tid]] = -1;
				SUM[wp[tid]] = 0;
				p = (i*K + j)*CASE;
				MAP[p + cnt++] = wp[tid]++;
				CNT[tid*N*K + i*K + j]++;
			}
			else if (j == i) {
				p = ((i - 1)*K + j - 1)*CASE;
				PRE[wp[tid]] = PRE[p];
				VAL[wp[tid]] = i;
				SUM[wp[tid]] = SUM[p] + i;
				p = (i*K + j)*CASE;
				MAP[p + cnt++] = wp[tid]++;
				CNT[tid*N*K + i*K + j]++;
			}
			else {
				int cnt = 0;
				int rep = 0;
				while (rep < CNT[tid*N*K + (i-1)*K + j-1]) {
					p = ((i - 1)*K + j - 1)*CASE;
					PRE[wp[tid]] = PRE[p + rep];
					VAL[wp[tid]] = i;
					SUM[wp[tid]] = SUM[p + rep++] + i;
					p = (i*K + j)*CASE;
					MAP[p + cnt++] = wp[tid]++;
					CNT[tid*N*K + i*K + j]++;
				}
				rep = 0;
				while (rep < CNT[tid*N*K + (i - 1)*K + j]) {
					p = ((i - 1)*K + j)*CASE;
					PRE[wp[tid]] = PRE[p + rep];
					VAL[wp[tid]] = -1;
					SUM[wp[tid]] = SUM[p + rep++];
					p = (i*K + j)*CASE;
					MAP[p + cnt++] = wp[tid]++;
					CNT[tid*N*K + i*K + j]++;
				}
			}
		}
	}
	//return CNT[n*K + k];
}

//void print_combi(int n, int k) {
//	int cnt = 100;//ret[n][k].cnt
//	for (int i = 0; i < cnt; i++) {
//		int rp = ret[n][k].arr[i];
//		CM* p = &map[rp];
//		while (p->val != -1) {
//			if (p->val != -2) {
//				printf("%2d,", p->val);
//			}
//			p = &map[p->pre];
//		}
//		printf("\n");
//	}
//}

__global__ void kernel_combi2(int start) {
	int tid = threadIdx.x + blockIdx.x * blockDim.x;
	//int* SUM = new int[SIZE];
	//int* VAL = new int[SIZE];
	//int* PRE = new int[SIZE];
	//int* MAP = new int[CASE*N*K];
	//int* CNT = new int[10*N*K];
	//int* wp = new int[10];
	//int n = 15;
	//int k = 10;
	//for (int i = 0; i < 2; i++) {
	//	combi(tid, n, k, SUM, VAL, PRE, MAP, CNT, wp);
	//}
	//printf("Combination count %i, thread nr. %i\n", CNT[tid*N*K+n*K+k], tid);

	//delete[] SUM;
	//delete[] VAL;
	//delete[] PRE;
	//delete[] MAP;
	//delete[] CNT;
	//delete[] wp;

	for (int i = 0; i < 1000000; i++)
	{
		int a = 1;
	}
	printf("Combination count %i, thread nr. %i\n", tid, tid);
}

void mygputest() {
	//printf("%d_C_%d is %d\n", n, k, combi(n, k));
	//print_combi(n, k);

	for (int i = 0; i < 4000; i+=1000) {
		kernel_combi2 << <1, 10 >> > (i);
	}
}
