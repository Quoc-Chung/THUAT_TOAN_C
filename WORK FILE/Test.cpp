#include<stdio.h>
#include<math.h>
int  main(){
	FILE *f;
	char s[]="Lap Trinh Co Ban";
	f=fopen("C:\\Users\\Admin\\Documents\\LAP TRINH\\DEV C++\\THUATTOANC\\WORK FILE\\LUU TRU\\tep.txt","w");
	fprintf(f,"%s",s);
	fclose(f);
}