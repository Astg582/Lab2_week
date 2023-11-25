#include <iostream>

const int s = 10;
void m_circul(int arr[][s], int);
void print(int arr[][s], int);

int main(){
	int arr[s][s];
	for(int i = 0; i < s; ++i){
		for(int j = 0; j < s; ++j){
			arr[i][j] = 1;
		}
	}
	m_circul(arr, s);
	print(arr, s);
}

void m_circul(int arr[][s], int s){
	for(int i = 0; i < s; ++i){
		for(int j = i; j < s - i; ++j){
			if(i <= s/2 && !(i & 1)){
				arr[i][j] = 0;
				arr[j][i] = 0;
			}
		}
		for(int j = s - i - 1; j < s; ++j){
			if(i >= s - j - 1 && j >= i){
				if((s & 1) && !(j & 1)){
					arr[i][j] = 0;
					arr[j][i] = 0;
				}else if(!(s & 1) && (j & 1)){
					arr[i][j] = 0;
					arr[j][i] = 0;
				}
			}
			
		}	
	}
}

void print(int arr[][s], int s){
	for(int i = 0; i < s; ++i){
		std::cout << std::endl;
		for(int j = 0; j < s; ++j){
		std::cout << arr[i][j] << ' ';
		}
	}
	std::cout << std::endl;
}
