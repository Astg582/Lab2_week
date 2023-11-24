#include<iostream>
const int S = 5;
void print(int arr[][S]);
int g_sum(int arr[][S]);
int o_sum(int arr[][S]);
void o_swap(int arr[][S]);
void max_min(int arr[][S]);
void zig_zag(int arr[][S]);
void zig_zag2(int arr[][S]);

int main(){
	int arr[S][S];
	
	for(int i  = 0; i < S; ++i){
		for(int j = 0; j < S; ++j){
			arr[i][j] = 0 + rand() % 10;
		} 
	}
	print(arr);
	zig_zag2(arr);
	print(arr);
}

void zig_zag2(int arr[][S]){
	int a = 10;
	for(int i  = 0; i < S; ++i){
		if(i & 1){
			for(int j = S - 1; j >= 0; --j){
				arr[i][j] = a++;
			} 
		}else{
			for(int j = 0; j < S; ++j){
				arr[i][j] = a++;
			}
		}
	}
}

void zig_zag(int arr[][S]){
	for(int i  = 0; i < S; ++i){
		for(int j = 0; j < S; ++j){
			if(i & 1){
				arr[i][j] = S - 1 - j;
			}else {
				arr[i][j] = j;
			}
		} 
	}
}

void max_min(int arr[][S]){
	int max = INT_MIN;
	int min = INT_MAX;
	for(int i  = 0; i < S; ++i){
		for(int j = 0; j < S; ++j){
			if(arr[i][j] > max){
				max = arr[i][j];
			}else if(arr[i][j] < min){
				min = arr[i][j];
			}
		} 
	}
	std::cout << "this is a max value in matrix " << max << '\n' << "this is a min value matrix " << min << std::endl; 
}

void o_swap(int arr[][S]){
	for(int i  = 0; i < S; ++i){
		std::swap(arr[i][i], arr[i][S - 1 - i]);
	}
}

int o_sum(int arr[][S]){
	int sum = 0;
	for(int i  = 0; i < S; ++i){
		for(int j = S - 1 - i; j < S; ++j){
			if((j + i) == S - 1){
				sum += arr[i][j];
			}
		} 
	}
	return sum;
}

int g_sum(int arr[][S]){
	int sum = 0;
	for(int i  = 0; i < S; ++i){
		for(int j = 0; j < S; ++j){
			if(j >= i){
				sum += arr[i][j]; 
			}	
		} 
	}
	return sum;
}

void print(int arr[][S]){
	for(int i  = 0; i < S; ++i){
		std::cout << std::endl;
		for(int j = 0; j < S; ++j){
			std::cout << arr[i][j] << ' ';
		} 
	}
	std::cout << std::endl;
}
