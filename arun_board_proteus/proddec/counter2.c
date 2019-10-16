#include<reg51.h>
sbit h=P1^6;//up counter
sbit g=P1^7;//down conter

void main()
{
	P1=0xff;
  P2=0x00;
while(1)
	
{
if(h==0)
{
P2=0xff;

}
if(g==0)
{
P2=0x00;

}

}


}