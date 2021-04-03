//FINAL_PROJECT_MERGE_SORT_ALGORITHM
#include"Review.cpp"

class Merge_Sort{

	Review* data;
	int start;
	int end;
	bool is_max;

	Merge_Sort(Review* reviews, bool is_max){
		this -> data = reviews;
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

	Review* sort(Review* reviews, int left = this -> start, int right = this -> end){
		if (left < right){
			int middle = left + (right - left)/2;
			sort(reviews,left,middle);
			sort(reviews,middle+1,right);
			merge(reviews, left, middle, right);
		}
	}

	void merge(Review* reviews, int left, int mid, int right){
		int n1 = mid - left + 1;
		int n2 = right - mid;
		Review x[n1], y[n2];
		
		for(int i = 0; i < n1; i++){
			x[i] = reviews[left + i];
		}

		for(int j = 0; j< n2; j++){
			y[j] = reviews[mid+1+j];
		}

		int i = 0, j = 0, k = left;

		while(i < n1 && j < n2){
			if(x[i] <= y[j]){//TODO:will need to overide this in Reviews!!!
				reviews[k] = x[i];
				i++;
			}else{
				reviews[k] = y[j];
				j++;
			}
			k++;
		}

		while(i < n1){
			reviews[k] = x[i];
			i++;
			k++;
		}

		while(j < n2){
			reviews[k] = y[j];
			j++;
			k++;
		}
	}
};