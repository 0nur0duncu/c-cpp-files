#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>

void yaprak()
{
  char dosya_isim[20];
  sprintf(dosya_isim, "%d.txt", getpid()); // şu anki çalışan processin process id'sini yazdırır.
  FILE *fp = fopen(dosya_isim, "w");
  // srand(time(NULL)); // bilgisayarda rastgelelik yoktur bu yüzden bilgisayarın saatine göre rastgele sayı çeker.
  srand(getpid()); // her processin pid sine göre sayı çeker.
  fprintf(fp, "%d", (rand()%100));
  fclose(fp);
}

int parent(int pid1,int pid2)
{
  wait(NULL);
  char dosya_isim1[20];
  sprintf(dosya_isim1, "%d.txt", pid1);
  char dosya_isim2[20];
  sprintf(dosya_isim2, "%d.txt", pid2);
  char dosya_isim3[20];
  sprintf(dosya_isim3, "%d.txt", getpid());
  FILE *fp1, *fp2, *fp3;
  fp1 = fopen(dosya_isim1, "r");
  fp2 = fopen(dosya_isim2, "r");
  int sol, sag;
  fscanf(fp1, "%d", &sol);
  fscanf(fp2, "%d", &sag);
  fclose(fp1);
  fclose(fp2);
  fp3 = fopen(dosya_isim3, "w");
  fprintf(fp3, "%d", sol + sag );
  fclose(fp3);
}

void agac_olustur(int yukseklik)
{
  if(yukseklik == 0)
  {
    // leaf node
    yaprak();
    return;
  }
  
  int pid1 = fork();
  if(pid1 > 0)
  {
    int pid2 = fork();
    if(pid2 > 0)
    {
      // parent işlem
      wait(NULL); // çocukların bitmesini bekler.
      printf("parent : %d, c1:%d,c2:%d\n",getpid(), pid1, pid2);
      fflush(stdout);
      // parent(pid1, pid2);
    }
    else if(pid2 == 0)
    {
      // sol çocuk
      agac_olustur(--yukseklik);
    }
  }
  else if(pid1 == 0)
  {
    // sağ cocuk
    agac_olustur(--yukseklik);
  }
}

int main()
{
  agac_olustur(3);
  return 0;
}

// ls *.txt
