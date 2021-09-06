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
	if (cnt ==10) {
		sum[0] = sum[0] + 1;
		return;
	}
	for (int i = s; i < n; i++)	{
		combi_device(i + 1, n, cnt+1, sum, tid);
	}
}

__global__ void combi_kernel(int* d_A, int size) {

	int tid = threadIdx.x + blockIdx.x * blockDim.x;
	int sum[1]; sum[0] = 0;

	int* local_array = new int[4*1000];
	int* visited = new int[4 * 10];

	for (int i = 0; i < 4 * 1000; i++) {
		local_array[i] = 0;
	}
	for (int i = 0; i < 4 * 10; i++) {
		visited[i] = 0;
	}

	combi_device(0, 10, 0, sum, tid);
	printf("Combination count %i, thread nr. %i\n", sum[0], tid);
	
	delete[] local_array;
	delete[] visited;

}

void mygputest() {
	int h_a[1000] = { 0 };
	int* d_a;
	cudaMalloc((void**)&d_a, sizeof(h_a));
	GPUerrchk(cudaMemcpy(d_a, h_a, sizeof(h_a), cudaMemcpyHostToDevice));

	printf("\n\n Combinations on GPU\n");
	combi_kernel << <1, 1 >> > (d_a, 4);
	GPUerrchk(cudaPeekAtLastError());
	GPUerrchk(cudaDeviceSynchronize());

}