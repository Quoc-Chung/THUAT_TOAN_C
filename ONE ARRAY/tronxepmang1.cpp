#include <stdio.h>
#include <math.h>
int main(){
	int m,n;
	scanf("%d%d",&m,&n);
	int a[m],b[n],c[m+n];
	printf("Nhap chi so mang A:\n");
	for (int i=0;i<m;i++){
		scanf("%d",&a[i]);
		}
		printf("Nhap chi so mang B:\n");
    for (int i=0;i<n;i++){
    	scanf("%d",&b[i]);
    	}
    	int i=0,j=0,k=0;
    	while(i<m && j<n){// dieu kien xay ra khi hai vong for khi và chi khi chi so mang bi duyet het va tien hanh dung vong lap
    		if(a[i]<b[j]){
    			c[k]=a[i];
    			k++;
    			i++;
    			}
    		else {
    			c[k]=b[j];
    			k++;
    			j++;
    			}
    			}
    	while (i<m){
    		c[k]=a[i];
    		k++;
    		i++;
    		}
    	while (i<n){
    		c[k]=b[j];
    		k++;
    		j++;
    		}
    		// ta cu cho k++ hoac i++ hoac j++ de khi duyet het chi so nay se den chi so sau
    		printf("Nhap chi so mang C:\n");
    	for (int i=0;i<m+n;i++){
		printf("%d ",c[i]);
		}
		}	
