#include<stdio.h>
#include<windows.h>


void ilktahta(int tahta[7][7]){  //Tahtamýzý tanýtýyoruz bellege.

	int i,j;
	
	for(i=0;i<7;i++){
		for(j=0;j<7;j++){
			if(i==3&&j==3){
				continue;
			}
			else if((i==0||i==1||i==5||i==6)&&(j==0||j==1||j==5||j==6)){
				tahta[i][j]=2;
			}
			else{
				tahta[i][j]=1;
			}
		}
		
	}
	
}

int hamlevarmi(int tahta[][7]){ //oyunun sonlanýp sonlanmadýgýný anlayacagýmýz kod yapýlabilecek hamlemizi sayýyor.
	int hamlemiktari=0;
	int i,j;
	for(i=0;i<7;i++){
		for(j=0;j<7;j++){
			if(tahta[i][j]==1&&tahta[i][j+1]==1&&tahta[i][j+2]==0){
				hamlemiktari++;
			}
			if(tahta[i][j]==1&&tahta[i][j-1]==1&&tahta[i][j-2]==0){
				hamlemiktari++;
			}
			if(tahta[i][j]==1&&tahta[i+1][j]==1&&tahta[i+2][j]==0){
				hamlemiktari++;
			}
			if(tahta[i][j]==1&&tahta[i-1][j]==1&&tahta[i-2][j]==0){
				hamlemiktari++;
			}
		}
	}
	return hamlemiktari;
}

int kalantas(int tahta[7][7]){ //Tahtayý gezerek taþlarý sayýyor.
	int i,j;
	int a=0;
	for(i=0;i<7;i++){
		for(j=0;j<7;j++){
			if(tahta[i][j]==1){
				a++;
			}
		}
	}
	return a;
}

void tahtabasma(int tahta[7][7]){ //Her seferinde tahtamýzý bastýgýmýz kod.
	int i,j;
	printf("  0 1 2 3 4 5 6\n");
	for(i=0;i<7;i++){
		printf("%d ",i);
		for(j=0;j<7;j++){
			if(tahta[i][j]==2){
				printf("  ");
			}
			else if(tahta[i][j]==0){
				printf(". ");
			}
			else{
				printf("X ");
			}
			
		}
		printf("\n");
	}
	printf("\nKalan Tas Sayisi: %d\n",kalantas(tahta));
	
	
}


int main() {
	system("color E");
	printf("                                       Solo Test Oyununa Hosgeldiniz\n\n");
	printf("Solo Test Nasil Oynanir? ----->\n**Solo test piyonu baska bir piyon uzerinden atlatilarak sonraki bos delige girer ve uzerinden atlanan piyon yerinden   cikartilarak alinir.\n");
	printf("**Oyun bu sekilde uzerinden atlanarak alinabilecek piyon kalmayincaya kadar devam eder.\n");
	printf("**Kalan piyon adedi oyun sonucunu gosterir.\n\n");
	int tahta[7][7]={0};
	ilktahta(tahta);
	tahtabasma(tahta);

	int i,j;
	int sx,sy,hx,hy;
	while(hamlevarmi(tahta)!=0){
		printf("Lutfen sectiginiz tas'in y degerini giriniz:");
	    scanf("%d",&sx);
	    printf("Lutfen sectiginiz tas'in x degerini giriniz:");
	    scanf("%d",&sy);
	    printf("Lutfen hedef tas'in y degerini giriniz:");
	    scanf("%d",&hx);
	    printf("Lutfen hedef tas'in x degerini giriniz:");
	    scanf("%d",&hy);
	    
	
			if((tahta[sx][sy]==1)&&(tahta[hx][hy]==0)&&((hy-sy)==2)){//Soldan saða hareket kosulu.sy,hy j temsil eder
				tahta[sx][sy]=0;
				tahta[hx][hy]=1;
				tahta[sx][sy+1]=0;
				system("cls");
				tahtabasma(tahta);
				
					
			}
			
			else if((tahta[sx][sy]==1)&&(tahta[hx][hy]==0)&&((sy-hy)==2)){//Saðdan sola hareket kosulu.sy,hy j temsil eder.
				tahta[sx][sy]=0;
				tahta[hx][hy]=1;
				tahta[sx][sy-1]=0;
				system("cls");
				tahtabasma(tahta);
			}
			else if((tahta[sx][sy]==1)&&(tahta[hx][hy]==0)&&((hx-sx)==2)){//Yukarýdan asagýya hareket kosulu.sx,hx i temsil eder.
				tahta[sx][sy]=0;
				tahta[hx][hy]=1;
				tahta[sx+1][sy]=0;
				system("cls");
				tahtabasma(tahta);
			}
			else if((tahta[sx][sy]==1)&&(tahta[hx][hy]==0)&&((sx-hx)==2)){//Asagýdan yukarýya hareket kosulu.sx,hx i temsil eder.
				tahta[sx][sy]=0;
				tahta[hx][hy]=1;
				tahta[sx-1][sy]=0;
				system("cls");
				tahtabasma(tahta);
			}
			else{
				printf("Gecersiz Hamle\n");
			}
	}
	
	if(kalantas(tahta)>=9){
		printf("Oyun Bitti.\n");
		printf("Test Sonucunuz:Daha Cok Yolun Var...\n");
	}
	else if(kalantas(tahta)==8){
		printf("Oyun Bitti.\n");
		printf("Test Sonucunuz:Kendini Gelistirmelisin...\n");
	}
	else if(kalantas(tahta)==7){
		printf("Oyun Bitti.\n");
		printf("Test Sonucunuz:Bu Seferlik Olmadi...\n");
	}
	else if(kalantas(tahta)==6){
		printf("Oyun Bitti.\n");
		printf("Test Sonucunuz:Tecrubesiz...\n");
	}
	else if(kalantas(tahta)==5){
		printf("Oyun Bitti.\n");
		printf("Test Sonucunuz:Normal...\n");
	}
	else if(kalantas(tahta)==4){
		printf("Oyun Bitti.\n");
		printf("Test Sonucunuz:Basarili...\n");
	}
	else if(kalantas(tahta)==3){
		printf("Oyun Bitti.\n");
		printf("Test Sonucunuz:Kurnaz...\n");
	}
	else if(kalantas(tahta)==2){
		printf("Oyun Bitti.\n");
		printf("Test Sonucunuz:Zeki...\n");
	}
	else if(kalantas(tahta)==1){
		printf("Oyun Bitti.\n");
		printf("Test Sonucunuz:Bilgin...\n");
	}
	

				

		
	
	
	

	return 0;
}
