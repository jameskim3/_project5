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

__device__ void combi_device2(int *cnt, int tid) {
	printf("Debug2\n"); 
	if (*cnt == 5)return;
//	*sum = *sum + idx;
	*cnt += 1;
	combi_device2(cnt, tid);
}

__device__ void combi_device(int *a, int *visited, int idx, int cnt, int *sum, int *rp, int tid)
{
	printf("Debug2\n");
	if (cnt == 5) {
		a[*rp] = *sum + tid;
		*rp += 1;
		printf("Combi nr. %i is %d\n", tid, *rp);
		return;
	}
	else
	{
		for (int i = idx; i < 10; i++)
		{
			if (visited[i] != 0) {
				visited[i] = 1;
				*sum += i;
				combi_device(a, visited, i+1, cnt+1, sum, rp, tid);
				visited[i] = 0;
			}
		}
	}
}

__global__ void permute_kernel(int* d_A, int size) {

	int tid = threadIdx.x + blockIdx.x * blockDim.x;
	int count[1]; count[0] = 0;

	int local_visited[4][250] = { 0 };
	int local_sum[4] = { 0 };
	int rp[4] = { 0 };
	int local_array[4*1000];

	int cnt[1] = { 0 };

	printf("Debug\n");
	//combi_device(&local_array[tid * 1000], local_visited[tid], 0, 0, &local_sum[tid], &rp[tid], tid);
	combi_device2(cnt, tid);
	printf("Combi nr. %i is %d\n", tid, rp[tid]);
}

int h_a[4*1000] = { 0 };
void mygputest() {
	int* d_a;
	cudaMalloc((void**)&d_a, sizeof(h_a));
	GPUerrchk(cudaMemcpy(d_a, h_a, sizeof(h_a), cudaMemcpyHostToDevice));

	printf("\n\n Combination on GPU\n");
	permute_kernel << <1, 4 >> > (d_a, 4);
	GPUerrchk(cudaPeekAtLastError());
	GPUerrchk(cudaDeviceSynchronize());


}