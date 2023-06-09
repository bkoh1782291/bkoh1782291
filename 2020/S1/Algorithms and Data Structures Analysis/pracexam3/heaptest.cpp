#include <iostream> 

using namespace std; 

// To heapify a subtree rooted with node i which is 
// an index in arr[]. N is size of heap 
void siftDown(int arr[], int n, int i) 
{ 
	int largest = i; // Initialize largest as root 
	int l = 2 * i + 1; // left = 2*i + 1 
	int r = 2 * i + 2; // right = 2*i + 2 

	// If left child is larger than root 
	if (l < n && arr[l] > arr[largest]) 
		largest = l; 

	// If right child is larger than largest so far 
	if (r < n && arr[r] > arr[largest]) 
		largest = r; 

	// If largest is not root 
	if (largest != i) { 
		swap(arr[i], arr[largest]); 

		// Recursively heapify the affected sub-tree 
		siftDown(arr, n, largest); 
	} 
} 

void buildHeap(int arr[], int n){
	// Build heap (rearrange array) 
    for (int i = n / 2 - 1; i >= 0; i--){
        siftDown(arr, n, i); 
    }

}

// swaps the elements and then prints them out
void deleteMin(int arr[], int n) 
{ 
    // One by one extract an element from heap 
    for (int i=n-1; i>0; i--) 
    { 
        // Move current root to end 
        swap(arr[0], arr[i]); 
  
        // call max heapify on the reduced heap 
        siftDown(arr, i, 0); 
    } 

    //cout << " Heap : \n"; 

	for (int i = 0; i < n; ++i) 
		cout << arr[i] << " "; 
	cout << "\n"; 
} 



// Driver Code 
int main() 
{ 
	//int arr[] = { 1, 3, 5, 4, 6, 13, 10, 9, 8, 15, 17 }; 
	int arr[] = {20, 5, 3, 12, 2, 5, 6, 7, 23, 5};

	int n = sizeof(arr) / sizeof(arr[0]); 

	buildHeap(arr, n);

	deleteMin(arr, n); 

	return 0; 
} 
