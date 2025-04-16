#include <iostream>
#include <vector>
using namespace std;

// Heapify function for Max Heap
void maxHeapify(vector<int>& arr, int n, int i) {
    int largest = i;         // Initialize largest as root
    int left = 2 * i + 1;    // Left child index
    int right = 2 * i + 2;   // Right child index

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        swap(arr[i], arr[largest]);
        maxHeapify(arr, n, largest);
    }
}

// Heapify function for Min Heap
void minHeapify(vector<int>& arr, int n, int i) {
    int smallest = i;         // Initialize smallest as root
    int left = 2 * i + 1;     // Left child index
    int right = 2 * i + 2;    // Right child index

    if (left < n && arr[left] < arr[smallest])
        smallest = left;

    if (right < n && arr[right] < arr[smallest])
        smallest = right;

    if (smallest != i) {
        swap(arr[i], arr[smallest]);
        minHeapify(arr, n, smallest);
    }
}

// Build Max Heap
void buildMaxHeap(vector<int>& arr) {
    int n = arr.size();
    for (int i = n / 2 - 1; i >= 0; i--) {
        maxHeapify(arr, n, i);
    }
}

// Build Min Heap
void buildMinHeap(vector<int>& arr) {
    int n = arr.size();
    for (int i = n / 2 - 1; i >= 0; i--) {
        minHeapify(arr, n, i);
    }
}

int main() {
    vector<int> marks = {75, 88, 92, 67, 81, 94, 73};

    vector<int> maxHeap = marks; // copy of original array
    vector<int> minHeap = marks;

    buildMaxHeap(maxHeap);
    buildMinHeap(minHeap);

    int maxMark = maxHeap[0]; // Root of max heap
    int minMark = minHeap[0]; // Root of min heap

    cout << "Maximum Marks: " << maxMark << endl;
    cout << "Minimum Marks: " << minMark << endl;

    return 0;
}
