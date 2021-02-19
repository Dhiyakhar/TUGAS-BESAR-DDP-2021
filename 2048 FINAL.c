//Permainan 2048
//Anggota : Dhiya Fakhar Nafi
//			M Nabil Harits Away
//Versi : 1.3 (13 Februari 2021)

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
#include <process.h>

#define UP 72
#define DOWN 80
#define LEFT 75
#define RIGHT 77

#define SIZE 4
#define BORDER 219
#define ESC 57
#define PR 2

//inisialisasi nilai
int matriks[SIZE+1][SIZE+1]={0};
int skor=0,batas=0;

//modul program
void mulai();
void wait();
void waitL();
void judul();
void layar();
void print_ever();
void NilaiAcak();
int Temp_counter();
void ending();
void hasil();
void Down();
void Up();
void Left();
void Right();
void pilihan();

			//sumber belajar : https://www.programmingsimplified.com/c/dos.h/delay
void wait()	//Membuat permainan terjeda selama 25 milidetik
{
    int i;
    for(i=0;i<4500000;i++);
}
				//sumber belajar : https://www.programmingsimplified.com/c/dos.h/delay
void waitL()	//Membuat permainan terjeda 1 detik
{
    int i;
    for(i=0;i<25;i++)
    {
        wait();
    }
}

void starting()	//Menampilkan judul permainan
{
    int i;
    char s1[]="Selamat Datang";
    char s2[]="POLBAN 2021";
    char s3[]="AYO BERMAIN 2048";

    char t[]="D4 TI-1A";
    char t1[]="Anggota :";
    char t2[]="Dhiya Fakhar Nafi";
    char t3[]="Muhammad Nabil Harits Away";


    waitL();
    waitL();

    printf("\n\n\n\t\t\t\t\t\t");
    printer(s1);
    waitL();
    waitL();
    waitL();
    waitL();
    waitL();
    waitL();
    waitL();
    waitL();
    waitL();
    waitL();
    waitL();


    judul();
	system("cls");

    printf("\n\n\n\t\t\t\t\t\t");
    printer(s3);
    waitL();
    waitL();
    waitL();
    waitL();
    waitL();
    printf("\n\n\n\t\t\t\t\t\t");
    waitL();
    printer(s2);
    waitL();
    waitL();
    waitL();
    waitL();
    waitL();
    waitL();
    system("cls");

    printf("\n\n\n\t\t\t\t\t\t");
    printer(t);
    waitL();
    printf("\n\n\t");
    printer(t1);
    printf("\n\n\t");
    printer(t2);
    printf("\n\n\t");
    printer(t3);
    printf("\n\n\t");
	waitL();
    waitL();
    waitL();
    waitL();
    waitL();
    waitL();	
    system("cls");
    printf("\n\n\n\t\t\tCara Bermain\n\n\n");
    printf(" 1. Gunakan panah Atas-Bawah-Kanan-Kiri pada Keyboard untuk menggeser ubin \n\n");
    printf(" 2. Temukan ubin dengan nilai 2048\n\n");
    waitL();
    waitL();
    waitL();
    waitL();
	waitL();
    waitL();
    waitL();
    waitL();
    waitL();
    waitL();
    waitL();
    waitL();
}

void starting2()	//Penampung modul pilihan
{
    pilihan();
}

void judul()	//Menampilkan jeda antarjudul permainan
{
    int i=1;
    system("cls");
    system("color F");waitL();
    printf("\n\n\n\n\n\n\t\t\t\t\t\tTunggu Sebentar ");
    while(i<2)
    {
        system("color 9");
        waitL();
        waitL();
        waitL();
        waitL();
        system("color F");
        waitL();
        waitL();
        waitL();
        waitL();
        system("color 9");
        waitL();
        waitL();
        waitL();
        waitL();
        system("color F");
        i++;
    }
}
					//Dengan pengubahan sesuai program
					//Sumber : https://www.tutorialgateway.org/c-program-to-print-characters-in-a-string/
printer(char s[])	//Mencetak huruf satu persatu
{
    int i=0;
    while(s[i]!='\0')
    {
        printf("%c",s[i]);
        wait();
        wait();
        wait();
        wait();
        wait();
        wait();
        i++;
    }
}
						//Dengan pengubahan sesuai program
						//Sumber : https://enthusiaststudent.blogspot.com/2018/05/fibonacci-2048-game-program-in-c.html
void Random_creater()	//Menjumlahkan nilai matriks
{
    int temp1,temp2,add,i,j;
    srand(time(NULL));
    temp1=rand()%SIZE;  // i

    srand(time(NULL));
    temp2=rand()%SIZE;  // j

    if((temp1+temp2)%2==0)
        add=2;
    else
        add=4;

    for(i=0;i<temp1;i++)
    {
        for(j=temp2;j<SIZE;j++)
        {
            if(matriks[i][j]==0)
            {
                matriks[i][j]=add;
                return;
            }
        }
    }
}

						//Dengan pengubahan sesuai program
						//Sumber : https://enthusiaststudent.blogspot.com/2018/05/fibonacci-2048-game-program-in-c.html
void Action(int Arrow)	//mengkonversi gerakan keyboard pada permainan
{

    switch(Arrow)
    {
        case UP:
            {
                Up();
                break;
            }
        case DOWN:
            {
                Down();
                break;
            }
        case LEFT:
            {
                Left();
                break;
            }
        case RIGHT:
            {
                Right();
                break;
            }
        default:
            {
                return;
            }
    }
    skor++;
    Random_creater();
    layar();
}
				//Dengan pengubahan sesuai program
				//Sumber : https://enthusiaststudent.blogspot.com/2018/05/fibonacci-2048-game-program-in-c.html
void layar()	//Menampilkan batas permainan pada saat permainan berjalan
{
    int i,j;
    system("cls");
    print_ever();
    for(i=0;i<SIZE;i++)
    {
        printf("\t\t\t %c",BORDER);
        for(j=0;j<SIZE;j++)
        {
            if(matriks[i][j]==0)
            {
                printf("      ");
            }
            else
                printf(" %4d ",matriks[i][j]);
        }
        printf("%c\n\t\t\t %c                        %c\n",BORDER,BORDER,BORDER);
    }
    printf("\t\t\t %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n\n",BORDER,BORDER,BORDER,BORDER,BORDER,BORDER,BORDER,BORDER,BORDER,BORDER,BORDER,BORDER,BORDER,BORDER,BORDER,BORDER,BORDER,BORDER,BORDER,BORDER,BORDER,BORDER,BORDER,BORDER,BORDER,BORDER);
}

					//Dengan pengubahan sesuai program
					//Sumber : https://enthusiaststudent.blogspot.com/2018/05/fibonacci-2048-game-program-in-c.html
void print_ever()	//Menampilkan layar permainan pada saat permainan berjalan
{
    printf("\n\n\n\t\t\t2048\n");
    printf("\t\t\t\t\t\t\t\t SKOR  : %d\n\n\n\n",skor);
    printf("\t\t\t %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",BORDER,BORDER,BORDER,BORDER,BORDER,BORDER,BORDER,BORDER,BORDER,BORDER,BORDER,BORDER,BORDER,BORDER,BORDER,BORDER,BORDER,BORDER,BORDER,BORDER,BORDER,BORDER,BORDER,BORDER,BORDER,BORDER);

}

void NilaiAcak()	//Nilai awal matriks dengan tingkat kesulitan mudah
{
    matriks[3][1]=16;
    matriks[3][2]=32;
    matriks[1][2]=64;
    matriks[2][3]=64;

    layar();
}

void NilaiAcak2()	//Nilai awal matriks dengan tingkat kesulitan menengah
{
    matriks[1][1]=8;
    matriks[3][2]=8;
    matriks[2][3]=16;
    matriks[1][2]=4;

    layar();
}

void NilaiAcak3()	//Nilai awal matriks dengan tingkat kesulitan sulit
{
    matriks[3][1]=4;
    matriks[3][2]=4;
    matriks[2][3]=2;

    layar();
}
					//https://enthusiaststudent.blogspot.com/2018/05/fibonacci-2048-game-program-in-c.html
					//Dengan pengubahan sesuai program
int Temp_counter()	//Untuk menentukan permainan berakhir dengan kemenangan atau kekalahan
{
    
    int temp=0,i,j;

    for(i=0;i<SIZE;i++)
    {
        for(j=0;j<SIZE;j++)
        {
            if(matriks[i][j]==2048)
                return(1);
            if(matriks[i][j]==0)
                temp=1;
        }
    }
    if(temp==1)
    {
        batas=0;
        return(-99);
    }
    else
    {
        if(batas==1)
        {
            return(0);
        }
        batas=1;
        return(-99);
    }
}
			//Sumber : https://enthusiaststudent.blogspot.com/2018/05/fibonacci-2048-game-program-in-c.html
			//Dengan pengubahan sesuai program
void Down()	//Untuk menggeser nilai matriks yang telah dijumlahkan ke kiri
{
    int i,j;
    for(j=0;j<SIZE;j++)
    {
        i=2;
        while(1)
        {
            while(matriks[i][j]==0)
            {
                if(i==-1)
                    break;
                i--;
            }
            if(i==-1)
                break;
            while(i<SIZE-1 && (matriks[i+1][j]==0 || matriks[i][j]==matriks[i+1][j]))
            {
                matriks[i+1][j]+=matriks[i][j];
                matriks[i][j]=0;
                i++;
            }
            i--;
        }
    }
}

			//Sumber : https://enthusiaststudent.blogspot.com/2018/05/fibonacci-2048-game-program-in-c.html
			//Dengan pengubahan sesuai program
void Up()	//Untuk menggeser nilai matriks yang telah dijumlahkan ke atas
{
    int i,j;
    for(j=0;j<SIZE;j++)
    {
        i=1;
        while(1)
        {
            while(matriks[i][j]==0)
            {
                if(i==SIZE)
                    break;
                i++;
            }
            if(i==SIZE)
                break;
            while(i>0 && (matriks[i-1][j]==0 || matriks[i][j]==matriks[i-1][j]))
            {
                matriks[i-1][j]+=matriks[i][j];
                matriks[i][j]=0;
                i--;
            }
            i++;
        }
    }
}

				//Sumber : https://enthusiaststudent.blogspot.com/2018/05/fibonacci-2048-game-program-in-c.html
				//Dengan pengubahan sesuai program
void Right()	//Untuk menggeser nilai matriks yang telah dijumlahkan ke kanan
{
    int i,j;
    for(i=0;i<SIZE;i++)
    {
        j=2;
        while(1)
        {
            while(matriks[i][j]==0)
            {
                if(j==-1)
                    break;
                j--;
            }
            if(j==-1)
                break;
            while(j<SIZE-1 && (matriks[i][j+1]==0 || matriks[i][j]==matriks[i][j+1]))
            {
                matriks[i][j+1]+=matriks[i][j];
                matriks[i][j]=0;
                j++;
            }
            j--;
        }
    }
}

				//Sumber : https://enthusiaststudent.blogspot.com/2018/05/fibonacci-2048-game-program-in-c.html
				//Dengan pengubahan sesuai program
void Left()		//Untuk menggeser nilai matriks yang telah dijumlahkan ke kiri
{
    int i,j;
    for(i=0;i<SIZE;i++)
    {
        j=1;
        while(1)
        {
            while(matriks[i][j]==0)
            {
                if(j==SIZE)
                    break;
                j++;
            }
            if(j==SIZE)
                break;
            while(j>0 && (matriks[i][j-1]==0 || matriks[i][j]==matriks[i][j-1]))
            {
                matriks[i][j-1]+=matriks[i][j];
                matriks[i][j]=0;
                j--;
            }
            j++;
        }
    }
}

void pilihan()	//Untuk membagi tingkat kesulitan permainan
{
char nilai;

printf("\t\t\t PILIH LEVEL\n");
printf("\t\t\t M = Mudah\n");
printf("\t\t\t T = Menengah\n");
printf("\t\t\t S = Sulit\n");
scanf("%c",&nilai);
 
  if (nilai == 'M' ) {
    NilaiAcak();
  }
  else if (nilai == 'T' ) {
    NilaiAcak2();
  }
  else if (nilai == 'S' ) {
    NilaiAcak3();
  }
}

main()
{
    int aro;
    char Arrow;
    char s[]="Terima kasih telah bermain permainan 2048 buatan kami ";
    int temp;
    char nilai2;
    
    starting();
    starting2();
    Arrow=DOWN;
    while(Arrow!=ESC) 
    {
        Arrow=getch();
        aro=Arrow;
        Action(Arrow);
        temp=Temp_counter();
        if(temp==1)
        {
        	printf("\n\t\t\tHORE KAMU MENANG!!");
        	printf("\n\n\t\t\t\t SKORMU ADALAH  : %d",skor);
        	waitL();
    		waitL();
    		waitL();
    		waitL();
    		waitL();
    		waitL();
    		waitL();
    		waitL();
    		waitL();
    		waitL();
        
            break;
        }
        if(temp==0)
        {
            printf("\n\t\t\t Maaf Kamu Kalah. \n");
            waitL();
    		waitL();
    		waitL();
    		waitL();
    		waitL();
    		waitL();
    		waitL();
    		waitL();
    		waitL();
    		waitL();
    		waitL();
    		waitL();
    		waitL();
    		waitL();
    		waitL();
            break;
        }
    }

    system("cls");
    waitL();
    waitL();
    waitL();
    printer(s);
    waitL();
    waitL();
    waitL();
}
