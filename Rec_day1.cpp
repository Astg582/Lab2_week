#include <iostream>
int fib(int);
int u_fib(int);
int uniFib(int);
int fact(int);
int searc(int arr[], int, int, int );
void byn(int);
int art(int);
int leng(char*);
char chr(char*);
int min(int arr[], int);
int max(int arr[], int s);

int main(){
	int key = 0;
	const int s = 10;
	int arr[s];

	for(int i = 0; i < s; ++i){ 
		std::cin >> arr[i];
	}

//	std::cin >> key;
	std::cout << max(arr, s - 1) << std::endl;
	//std::cout << searc(arr, 0, s - 1, key) << std::endl;

}

int fib(int n){
	if( n == 0){
		return 0;
	}else if(n == 1){
		return 1;
	}
	return fib(n - 1) + fib(n - 2);
}

int u_fib(int n){
	int tmp = fib(n < 0 ? - n : n);
	if(n < 0 && n % 2 == 0){
		return -tmp;
	}
	return tmp;

}

int uniFib(int n){
	if((n > 0) || (n / 2 == abs(1))){
		 return fib(n); 
	}
	return -fib(abs(n)); 
}

int fact(int n){
	if(n == 0){
		return 1;
	}
	return n * fact(n - 1);
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
	if(s == 1){
		return arr[s];
	}
	return (arr[s] > arr[s-1] ? arr[s] : arr[s- 1]) > max(arr, s - 1); 
}

char chr(char* str){
	if(*(str) >= 'A' && *(str) <= 'Z'){
		return *(str);
	}
	return chr(str + 1);
}

int leng(char* str){
	if(*str == '\0'){
		return 0;
	}
	
	return 1 + leng(str + 1);
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
	}else if (i >= j){
		return - 1;
	}else if (arr[mid] < key){
		return searc(arr, mid + 1, j, key); 
	}
		return searc(arr, i, mid - 1, key);
}
