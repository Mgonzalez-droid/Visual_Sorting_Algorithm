//FINAL_PROJECT_MERGE_SORT_ALGORITHM
#include"Review.cpp"

template<class t>
class Merge_Sort{

	t* data;
	int start;
	int end;
	bool is_max;

	Merge_Sort(t* data, bool is_max){
		this -> data = data;
		this -> start = 0;
		this -> end = 100000;
		this -> is_max = is_max;
	}

	/*
	 *	Merge Algorithm
	 *	1. Access the first item from both sequences.
	 *	2. while not finished with either sequence
	 *	3.		Compare the current items from the two sequences, copy the smaller
	 *			current item to the output sequence and access the next item from the input sequence whose item was copied.
	 *	4. Copy any remaining items from the first sequence to the output sequence.
	 *	5. Copy any remaining items from the second sequence to the output sequence.
	 */

	t* sort(t* data, int left = 0, int right = 100000){
		if (left < right){
			int middle = left + (right - left)/2;
			sort(data,left,middle);
			sort(data,middle+1,right);
			merge(data, left, middle, right);
		}
	}

	void merge(t* data, int left, int mid, int right){
		int n1 = mid - left + 1;
		int n2 = right - mid;
		Review x[n1], y[n2];
		
		for(int i = 0; i < n1; i++){
			x[i] = data[left + i];
		}

		for(int j = 0; j< n2; j++){
			y[j] = data[mid+1+j];
		}

		int i = 0, j = 0, k = left;

		while(i < n1 && j < n2){
			if(x[i] <= y[j]){//TODO:will need to overide this in Reviews!!!
				data[k] = x[i];
				i++;
			}else{
				data[k] = y[j];
				j++;
			}
			k++;
		}

		while(i < n1){
			data[k] = x[i];
			i++;
			k++;
		}

		while(j < n2){
			data[k] = y[j];
			j++;
			k++;
		}
	}
};