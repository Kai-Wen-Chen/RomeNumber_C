#include <stdio.h>
#include <stdlib.h>

int main(){
	char input_f[16], input_s[16];
	char output[16];
	int in_f, in_s, tmp;
	int out;
	int flag = 0;
	
	while ((scanf("%s %s", input_f, input_s)) != EOF) {
		in_f = 0;
		in_s = 0;
		tmp = 0;
		out = 0;
		flag = 0;
		output[0] = '\0';
		
		if (input_f[0] != 'Z') {
			for (int i=0; i<16; i++) {
				if (input_f[i] == 'M') { //1000
					if (flag == 3) { //CM
						in_f += 900;
						tmp = 0;
					} else { //MM
						in_f += 1000;
						tmp = 0;
					}
					flag = 1;
				} else if (input_f[i] == 'D') { //500
					if (flag == 3) { //CD
						in_f += 400;
						tmp = 0;
					} else { //MD
						in_f += 500;
						tmp = 0;
					}
					flag = 2;
				} else if (input_f[i] == 'C') { //100
					if (flag == 1) { //MCM or MCD or MCC
						tmp += 100;
					} else if (flag == 2 || flag == 3) { //CC, DC
						in_f += tmp;
						in_f += 100;
						tmp = 0;
					} else if (flag == 5){ //XC
						in_f += 90;
						tmp = 0;
					}
					flag = 3;
				} else if (input_f[i] == 'L') { //50
					if (flag == 5) { //XL
						in_f += 40;
						tmp = 0;
					} else { //ML, DL, CL
						in_f += tmp;
						in_f += 50;
						tmp = 0;
					}
					flag = 4;
				} else if (input_f[i] == 'X') { //10
					if (flag == 4 || flag == 5) { //LX, XX
						in_f += tmp;
						in_f += 10;
						tmp = 0;
					} else if (flag == 7){ //IX
						in_f += 9;
						tmp = 0;
					} else { //MXL, MXC, ...
						tmp += 10;
					}
					flag = 5;
				} else if (input_f[i] == 'V') { //5
					if (flag == 7) { //IV
						in_f += 4;
						tmp = 0;
					} else {
						in_f += tmp;
						in_f += 5;
						tmp = 0;
					}
					flag = 6;
				} else if (input_f[i] == 'I') { //1
					if (flag == 6 || flag == 7) { //VI, II
						in_f += tmp;
						in_f += 1;
						tmp = 0;
					} else {
						tmp += 1;
					}
					flag = 7;
				} else if (input_f[i] == '\0') {
					in_f += tmp;
					tmp = 0;
					flag = 0;
				} 
			}
		}
		
		
		if (input_s[0] != 'Z') { 
			for (int i=0; i<16; i++) {
				if (input_s[i] == 'M') { //1000
					if (flag == 3) { //CM
						in_s += 900;
						tmp = 0;
					} else { //MM
						in_s += 1000;
						tmp = 0;
					}
					flag = 1;
				} else if (input_s[i] == 'D') { //500
					if (flag == 3) { //CD
						in_s += 400;
						tmp = 0;
					} else { //MD
						in_s += 500;
						tmp = 0;
					}
					flag = 2;
				} else if (input_s[i] == 'C') { //100
					if (flag == 1) { //MCM or MCD or MCC
						tmp += 100;
					} else if (flag == 2 || flag == 3) { //CC, DC
						in_s += tmp;
						in_s += 100;
						tmp = 0;
					} else if (flag == 5){ //XC
						in_s += 90;
						tmp = 0;
					}
					flag = 3;
				} else if (input_s[i] == 'L') { //50
					if (flag == 5) { //XL
						in_s += 40;
						tmp = 0;
					} else { //ML, DL, CL
						in_s += tmp;
						in_s += 50;
						tmp = 0;
					}
					flag = 4;
				} else if (input_s[i] == 'X') { //10
					if (flag == 4 || flag == 5) { //LX, XX
						in_s += tmp;
						in_s += 10;
						tmp = 0;
					} else if (flag == 7){ //IX
						in_s += 9;
						tmp = 0;
					} else { //MXL, MXC, ...
						tmp += 10;
					}
					flag = 5;
				} else if (input_s[i] == 'V') { //5
					if (flag == 7) { //IV
						in_s += 4;
						tmp = 0;
					} else {
						in_s += tmp;
						in_s += 5;
						tmp = 0;
					}
					flag = 6;
				} else if (input_s[i] == 'I') { //1
					if (flag == 6 || flag == 7) { //XI, II
						in_s += tmp;
						in_s += 1;
						tmp = 0;
					} else {
						tmp += 1;
					}
					flag = 7;
				} else if (input_s[i] == '\0') {
					in_s += tmp;
					tmp = 0;
				} else if (input_s[i] == 'Z') {
					in_s = 0;
					break;
				}
			}
		} 
		
		//printf("%d %d\n", in_f, in_s);
		if (in_f >= in_s) out = in_f - in_s;
		else out = in_s - in_f;
		//printf("%d\n", out);
		
		if (out == 0) {
			output[0] = 'Z';
			output[1] = 'E';
			output[2] = 'R';
			output[3] = 'O';
			output[4] = '\0';
		} else {
			int j = 0;
			while (out > 0) {
				//printf("%d\n", out);
				if (out >= 1000) {
					switch (out/1000) {
						case 4:
							output[j++] = 'M';
							output[j++] = 'M';
							output[j++] = 'M';
							output[j++] = 'M';
							break;
						case 3:
							output[j++] = 'M';
							output[j++] = 'M';
							output[j++] = 'M';
							break;
						case 2:
							output[j++] = 'M';
							output[j++] = 'M';
							break;
						case 1:
							output[j++] = 'M';
							break;
						default:
							break;
					}
					
					out %= 1000;
				} else if(out >= 100) {
					switch (out/100) {
						case 9:
							output[j++] = 'C';
							output[j++] = 'M';
							break;
						case 8:
							output[j++] = 'D';
							output[j++] = 'C';
							output[j++] = 'C';
							output[j++] = 'C';
							break;
						case 7:
							output[j++] = 'D';
							output[j++] = 'C';
							output[j++] = 'C';
							break;
						case 6:
							output[j++] = 'D';
							output[j++] = 'C';
							break;
						case 5:
							output[j++] = 'D';
							break;
						case 4:
							output[j++] = 'C';
							output[j++] = 'D';
							break;
						default:
							for (j=j; j<j+out/100; j++) {
								output[j] = 'C';
							}
							break;
					}
					out %= 100;
				} else if (out >= 10) {
					switch (out/10) {
						case 9:
							output[j++] = 'X';
							output[j++] = 'C';
							break;
						case 8:
							output[j++] = 'L';
							output[j++] = 'X';
							output[j++] = 'X';
							output[j++] = 'X';
							break;
						case 7:
							output[j++] = 'L';
							output[j++] = 'X';
							output[j++] = 'X';
							break;
						case 6:
							output[j++] = 'L';
							output[j++] = 'X';
							break;
						case 5:
							output[j++] = 'L';
							break;
						case 4:
							output[j++] = 'X';
							output[j++] = 'L';
							break;
						default:
							for (j=j; j<j+out/10; j++) {
								output[j] = 'X';
							}
							break;
					}
					out %= 10;
				} else if (out >= 1) {
					//printf("111\n");
					switch (out) {
						case 9:
							output[j++] = 'I';
							output[j++] = 'X';
							break;
						case 8:
							output[j++] = 'V';
							output[j++] = 'I';
							output[j++] = 'I';
							output[j++] = 'I';
							break;
						case 7:
							output[j++] = 'V';
							output[j++] = 'I';
							output[j++] = 'I';
							break;
						case 6:
							output[j++] = 'V';
							output[j++] = 'I';
							break;
						case 5:
							output[j++] = 'V';
							break;
						case 4:
							output[j++] = 'I';
							output[j++] = 'V';
							break;
						default:
							for (j=j; j<j+out; j++) {
								output[j] = 'I';
							}
							break;
					}
					out = 0;
				}
			}
			output[j] = '\0';
		}
		
		
		printf("%s\n", output);
	}
} 
