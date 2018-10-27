#include <iostream>
#include <random>
#include <assert.h>
#include <string.h>

using namespace std;

#define MIN 100
#define MAX 500

mt19937 rng;

int generateRandomInt(int min, int max);
void printArray(int *array, size_t size);
void heapsort(int* array, size_t size);
bool validate(int* array, size_t size);
int getmayor(int x, int y, int z);
int getmin(int x, int y, int z);

int main(int argc, char *argv[]) {
    rng.seed(random_device()());
    cout << "===========================================================" << endl;
    cout << "\tHeapsort Practice" << endl;
    cout << "===========================================================" << endl << endl;

    const int numberOfElements = generateRandomInt(MIN, MAX);
    int *numbers = new int[numberOfElements];
    for (int i = 0; i < numberOfElements; i++) {
        numbers[i] = generateRandomInt(0, 100);
    }
    
    printArray(numbers, numberOfElements);
    heapsort(numbers, numberOfElements);
    cout<<endl;
    printArray(numbers, numberOfElements);
    assert(validate(numbers, numberOfElements) && "The sort is not ordering all the elements");
    //system("read");
    return EXIT_SUCCESS;
}

void swap(int n, int x, int* array){
  int temp=array[x];
  array[x]=array[n];
  array[n]=temp;
}
int getmayor(int x, int y, int z){
  if(x>=y && x>=z)
    return x;
  if(y>=z && y>=z)
  return y;
  if(z>=x && z>=y)
  return z;
}
int getmin(int x, int y, int z){
  if(x<=y && x<=z)
    return x;
  if(y<=z && y<=z)
  return y;
  if(z<=x && z<=y)
  return z;
}
int generateRandomInt(int min, int max) {
    uniform_int_distribution<mt19937::result_type> distribution(min, max);
    return distribution(rng);
}

void printArray(int *array, size_t size) {
    for (int i = 0; i < size; i++) {
        cout << array[i] << " ";
    }
    cout << endl;
}

void heapifymin(int* array, size_t size, int n) {
  int left=2*n+1;
  int right=2*n+2;
  int menor;
  if(size>left && size>right){
    menor=getmin(array[n],array[left],array[right]);
    if(array[n]==menor)
      return;
    else if(array[left]==menor){
      swap(n, left ,array);
      heapifymin(array,size,left);
    }
    else if(array[right]==menor){
      swap(n, right ,array);
      heapifymin(array,size,right);
    }
  }
  else if(size>left){
    menor=getmin(array[n],array[left],1000);
    if(array[n]==menor)
      return;
    else{
      swap(n, left ,array);
      heapifymin(array,size,left);
    }
  }
  else if(size>right){
    menor=getmin(array[n],array[right],1000);
    if(array[n]==menor)
      return;
    else{
      swap(n, right ,array);
      heapifymin(array,size,right);
    }
  }

}

void heapifymax(int* array, size_t size,int n) {
  int left=2*n+1;
  int right=2*n+2;
  int mayor;
  if(size>left && size>right){
    mayor=getmayor(array[n],array[left],array[right]);
    if(array[n]==mayor)
      return;
    else if(array[left]==mayor){
      swap(n, left ,array);
      heapifymax(array,size,left);
    }
    else if(array[right]==mayor){
      swap(n, right ,array);
      heapifymax(array,size,right);
    }
  }
  else if(size>left){
    mayor=getmayor(array[n],array[left],-1);
    if(array[n]==mayor)
      return;
    else{
      swap(n, left ,array);
      heapifymax(array,size,left);
    }
  }
  else if(size>right){
    mayor=getmayor(array[n],array[right],-1);
    if(array[n]==mayor)
      return;
    else{
      swap(n, right ,array);
      heapifymax(array,size,right);
    }
  }

}
void heapsort(int* array, size_t size) {
  int padre=size/2 -1;
  for(padre; padre>=0; padre-- ){
    heapifymax(array,size, padre);
  }
  for (int i=size-1; i>=0; i--)
    {
        swap(0, i,array);
        heapifymax(array, i, 0);
    }
}

bool validate(int* array, size_t size) {
    for (int i = 0; i < size - 1; i++) {
        if (array[i] > array[i + 1]) {
            return false;
        }
    }
    return true;
}
