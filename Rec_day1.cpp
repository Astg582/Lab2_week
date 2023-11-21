#include <iostream>
int searc(int arr[], int, int, int );
void byn(int);
int art(int);
int leng(char*);
char chr(char* str);
int min(int arr[], int);
int max(int arr[], int);

int main(){
	int key = 0;
	const int s = 10;
	int arr[s];
	for(int i = 0; i < s; ++i){ 
		std::cin >> arr[i];
	}
	std::cout << max(arr, s) << std::endl;
	//std::cout << searc(arr, 0, s - 1, key) << std::endl;

}

int min(int arr[], int s){
	static int min1 = INT_MAX;
	if(arr == arr + s){
		return min1;
	}
	if(*arr < min1){
		min1 = *arr;
	}
	return min(arr + 1, s - 1);
}

int max(int arr[], int s){
	static int max1 = INT_MIN;
	if(arr == arr + s){
		return max1;
	}
	if(*arr > max1){
		max1 = *arr;
	}
	return max(arr + 1, s - 1);
}

char chr(char* str){
	if(*(str) >= 'A' && *(str) <= 'Z'){
		return *(str);
	}
	return chr(str + 1);
}

int leng(char* str){
	static int l = 0;
	if(*(str) == '\0'){
		return l;
	}
	++l;
	return leng(str + 1);
}

int art(int n){
	if(0 == n){
		return 1;
	}
	return (n % 10) * art(n / 10);
}

void byn( int n){
	if(0 == n || 1 == n){
		std::cout << n << ' ';
		return;
	}
	byn(n / 2);
	std::cout << n % 2 << ' ';
}


int searc(int arr[], int i,int j, int key){
	int mid = (i + j) / 2;
	if (arr[mid] == key){
		return mid;
	}else if (i > j){
		return -1;
	}else if (arr[mid] < key){
		mid += 1;
		return searc(arr, mid, j, key); 
	}
		mid -= 1;
		return searc(arr, i, mid, key);
}
