#include<iostream>
const int s = 4;
void g_swap(int matr[][s], int);
void o_swap(int matr[][s], int);
void print(int matr[][s], int);
void rotate(int matr[][s], int);
void zuig(int matr[][s], int);
void rev(int matr[][s], int);
void rev_s(int matr[][s]);

int main(){
  
	int arr[s][s];
	int a = 10;
	for(int i = 0; i < s; ++i){
		for(int j = 0; j < s; ++j){
			arr[i][j] = 3;
			++a;
		}
	}

	print(arr, s);
	zuig(arr, s);
	//rev_s(arr);
	std::cout << std::endl; 
	print(arr, s);
}

void rev_s(int matr[][s]){
	for(int i = 0; i < s / 2; ++i){
		for(int j = 0; j < s; ++j){
			std::swap(matr[i][j], matr[s - 1 - i][j]);
		}
	}
}

void rev(int matr[][s], int s){
	for(int i = 0; i < s; ++i){
		for(int j = 0; j < s / 2; ++j){
			std::swap(matr[i][j], matr[i][s-1-j]);
		}
	}
}

void zuig(int matr[][s], int s){
	for(int i = 0; i < s; ++i){
		for(int j = 0; j < s; ++j){
			if( !(i & 1)){
				matr[i][j] = 0;
			}
			if(!(j & 1)){
				matr[i][j] = 0;
			}
		}
	}
}

void g_swap(int matr[][s], int s){
	for(int i = 0; i < s; ++i){
		for(int j = i + 1; j < s; ++j){
			std::swap(matr[i][j], matr[j][i]);
		}
	}

}

void o_swap(int matr[][s], int s){
	for(int i = 0; i < s / 2; ++i){
		for(int j = 0; j < s; ++j){
				std::swap(matr[i][j], matr[s-1-i][s-j-1]);
		}
	}

	if(s & 1){
		for(int i = 0; i < s / 2; ++i){
			std::swap(matr[s / 2][i], matr[s / 2][s - 1 - i]);
		}
	}
}

void rotate(int matr[][s], int s){
	g_swap(matr, s);
	for(int i = 0; i < s; ++i){
		for(int j = 0; j < s / 2; ++j){
		std::swap(matr[i][j], matr[i][s-1-j]);		
		}
	}
}

void print(int matr[][s], int s){
	for(int i = 0; i < s; ++i){
		for(int j = 0; j < s; ++j){
			std::cout << matr[i][j] << ' ';
		}
		std::cout << std::endl;
	}
}
