#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h> 
#include <math.h>

bool if_dec(char*);
bool if_hex(char*);
int calculator(int, int);
int bin_dec(char*);

void count(int dec);

int main(){
	int dec = 0;
	/*
	printf("Enter '2' -> binary, '10' -> decimal or '16' -> hexadecimal\n");
	do{
		printf("please enter '2' or '10' or '16'\n");
		scanf("%d", &dec);
		if(dec != 10 && dec != 2 && dec != 16){
		printf("Invalid number system. Please tray again\n");
		}
	}while(dec != 10 && dec != 2 && dec != 16);
	*/
	char arr[9];	
	printf("Enter to binar numbeer\n");
	scanf("%s", arr);
	printf(" if_dec output : %d\n", if_dec(arr));


	return 0;
}	

int calculator(int a, int b){
	int cal = 0;
	printf("1. AND, \n2. OR \n3. XOR \n4. NOR \n5. Left Shift \n6. Right shift \n7. Replay \n8. Exit");
	do{
		scanf("%d", &cal);
		if(cal < 1 || cal > 7){
			printf("Invalid number system. Please tray again\n");
		} 
	}while(cal < 1 || cal > 8);
	
	switch (cal){
		case 1:
		return a & b;
		case 2:
		return a | b;
		case 3:	
		return a ^ b;
		case 4:
		return ~(a | b);
		case 5:
		return a << b;
		case 6:
		return a >> b;
		case 7:
		return main();
                case 8:
		exit(0);
	}

	return 0;
}


void count(int dec){
	switch(dec){
		case 10:
		int a = 0;
		int b = 0;
		do{
		printf("enter  1 numbers in your chosen numeric system\n");
		scanf("%d", &a);
		}while(!(if_dec(a)));
		do{
		printf("enter  1 numbers in your chosen numeric system\n");
		scanf("%d", &b);
		}while(!(if_dec(a)));


			decimal(a, b);
			break;
		case 2:
			int a = 0;
			int b = 0;
			do{
			printf("enter  1 numbers in binary numeric system\n");
			scanf("%d", &a);
			}while(!(if_bin(a)));
			do{
			printf("enter  1 numbers in binary numeric system\n");
			scanf("%d", &b);
			}while(!(if_bin(a)));
		

			binary(a, b);
			break;
		case 16:
			char hex1[8];
			char hex2[8];
				do{
				printf("enter  1 numbers in hexadecimal numeric system\n");
				scanf("%s", &hex1);
				}while(!(if_hex(hex1)));
				do{
				printf("enter  1 numbers in hexadecimal numeric system\n");
				scanf("%s", &hex2);
				}while(!(if_hex(hex2)));
			
		
			hex(a, b);
			break;
		default:

			decimal(a, b);
	}
}



int bin_dec(char* bin1){
	int a = 0;
	bin1 += 2;
	int i = 1;
	int j = 0;
	while(bin1[j] != '\0'){
		++j;
	}
	while(*bin1 != '\0'){ 
			a += (int)(*bin1 - '0') * (1 << (j - i));
			bin1 += 1;
			++i;
	}
	return a;
}

bool if_bin(char* bin){
        if(*bin != '0' || *(bin +1) != 'b'){
                       return 0;
         }
	bin += 2;
	while(*bin != '\0'){
                       if(*bin < '0' || *bin > '1'){
                                       return 0;
		       }
                       bin += 1;
	}
	return 1;
}

bool if_hex(char* hex1){
	if(*hex1 != '0' || (*hex1 + 1) != 'x'){
		return 0;
	}
	hex1 += 2;
	while(*hex1 != '\0'){
		if(*hex1 < 0){
                       return 0;
                }
	        if(*hex1 > 9){
			if(*hex1 < 'A' || *hex1 > 'F'){
				return 0;
			}
	         }
	         hex1 += 1;
         }
return 1;
}

bool if_dec(char* a){
	if((*a != '0') || *(a + 1) != 'd'){
		return 0;
	}
	a += 2;
	while(*a != '\0'){
 		if(*a < '0' || *a  > '9'){
			return 0;
		} 
		a += 1;
	}
	return 1;
}

