#include "Watermark_Manager.h"
#include "Watermark_Mask.h"
int main(){

	//Watermark_Manager vm("E:/Watermark images/autumn.png","E:/Watermark images/baboon.jpg");
	//vm.Watermark_start();
	//vm.Watermark_decrypt();
	Watermark_Mask vs("E:/Watermark images/autumn.png","E:/Watermark images/Watermark2.png");
	vs.Watermark_start1();
	return 0;
}