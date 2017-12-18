#include "Watermark_Manager.h"

int main(){

	Watermark_Manager vm("E:/Watermark images/autumn.png","E:/Facultate/Practica Dyve/opencv/sources/samples/data/baboon.jpg");
	vm.Watermark_start();
	vm.Watermark_decrypt();
	return 0;
}