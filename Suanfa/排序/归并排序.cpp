class MergeSort {
public:
	int* mergeSort(int* A, int n)//刚开始的函数 
	{
		int *p = new int[n];  //申请一个和A一样大小的p暂时存放在mergeArray中会用到
		if (!p) return NULL;
		mergeSort(A, 0, n - 1, p);  //拆分
		delete[] p;
		return A;

	}
private:
	void mergeSort(int *A, int begin, int end, int *temp)    //把数组分成两份
	{
		if (begin<end)
		{
			int middle = (begin + end) / 2; //求出中间的位置
			mergeSort(A, begin, middle, temp);
			mergeSort(A, middle + 1, end, temp);  //分别对两个分开的数组再分
			mergeArray(A, begin, end, middle, temp);//合并两个数组
		}

	}
	void mergeArray(int *A, int begin, int end, int mid, int *temp)
	{
		int i = begin;  //把数组a[0,10]中的a[0,4]和a[5,9]合并，把两个第一个元素下标给i,j
		int j = mid + 1;
		int end1 = mid;  //把最后一个元素赋值给end1,end2
		int end2 = end;
		int k = 0;
		while (i <= end1 && j <= end2)   //两个数组元素进行比较，并赋值到temp中
		{
			if (A[i]<A[j])
				temp[k++] = A[i++];
			else
				temp[k++] = A[j++];
		}
		while (i <= end1) temp[k++] = A[i++];   //如果其中一个元素有剩余，则说明剩下的都是大的了，直接赋值给temp中
		while (j <= end2) temp[k++] = A[j++];
		for (i = 0; i<k; i++) A[begin + i] = temp[i];//把temp中的内容给A
	}
};
