#include <iostream>
#include<fstream>
#include<string.h>
#include<string> 
using namespace std;
//run this program using the console pauser or add your own getch, system("pause") or input loop 
	
	#define namesize  50000000
	string duowanstr[namesize];

int main(int argc, char** argv) {	
	ofstream fout("E://TDDOWNLOAD//fugailv//20140919//name_pinyin_with_duowan100w_deleted.txt");	//name////////////////
	ifstream fin0("E://TDDOWNLOAD//fugailv//20140919//duowan_100w_alpha_sorted.txt");  //test	/////////////////////
	if(!fin0){
		cerr << "open failed" << endl;
		return -1;
	}
	int i=0;
	int namenum=0;
	
	while(fin0>>duowanstr[i]){
		i++;		
	}
	namenum=i--;

	string ps;
	ifstream fin2("E://TDDOWNLOAD//fugailv//覆盖率测试包含全部长度的字母组件//alpha_with_all_length_sorted//name_pinyin_nocount_sorted.txt");  //test	/////////////////////
	if(!fin2){
		cerr << "open failed" << endl;
		return -1;
	}
	while(fin2>>ps){
		bool ismatched = false;
		int head=0;
		int tail=namenum-1;
		while(1){
			if(head==tail){
				if(ps == duowanstr[head]){
					ismatched = true;
						break;
				}
				break;			
			}
			else if(head == tail-1){
				if(ps==duowanstr[head]){
						ismatched = true;
						break;
				}
				else if(ps==duowanstr[tail]){
						ismatched = true;
						break;
				}
				break;
			}
			else{
				if(ps==duowanstr[head]){
						ismatched = true;
						break;
				}
				else if(ps==duowanstr[tail]){
						ismatched = true;
						break;
				}
				else{
					int mid=(head+tail)/2;
					if(ps<=duowanstr[mid]){
						tail=mid;
						continue;
					}
					else{
						head=mid;
						continue;
					}
				} 
			}
		}
		if(! ismatched){
			fout<<ps<<endl;	
		}
	}

	return 0;
}

