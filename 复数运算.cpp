#include <stdio.h>
#include<math.h>
#include<stdlib.h>
float R,I,M,J;

#define PI 3.1415926

void zhijiao(void);
void zhijiao_to_ji_main(void);
void zhijiao_to_ji(void);
void ji(void);
void ji_to_zhijiao_main(void);
void ji_to_zhijiao(void);

main()
{   int t;
	while(1)
	{
    R=0,I=0,M=0,J=0;
	printf("\n����:1ֱ����������,2������,3ֱ������ת������,4������תֱ��,5����  ");
	scanf("%d",&t);
	switch(t)
	{
	case 1:zhijiao();break;
	case 2:ji();break;
	case 3:zhijiao_to_ji_main();break;
	case 4:ji_to_zhijiao_main();break;
	case 5:system("cls");break;
	}
	}
}
void zhijiao()										//����ֱ������ϵ�¸�������
{
    float R1,I1,R2,I2;
	char suan;
    printf("�����룺(���ֻ������֮���Կո�ָ�)\n");
	scanf("%f%f %c%f%f",&R1,&I1,&suan,&R2,&I2);		//%cǰ�ӿո��ֹ�ո�ֵ��suan
    
	switch(suan)									
	{
	case '+':
	R=R1+R2;
	I=I1+I2;
	break;

	case '-':
	R=R1-R2;
	I=I1-I2;
	break;

	case '*':
	R=R1*R2-I1*I2;
	I=R1*I2+R2*I1;
	break;

	case '/':
	R=(R1*R2+I1*I2)/(R2*R2+I2*I2);
	I=(R2*I1-R1*I2)/(R2*R2+I2*I2);
	break;
	}

	if(fabs(R-0)<1e-6&&!(fabs(I-0)<1e-6))
		printf("(%f%+fi) %c (%f%+fi)=%fi\n",R1,I1,suan,R2,I2,I);
	if(fabs(I-0)<1e-6&&!(fabs(R-0)<1e-6))
		printf("(%f%+fi) %c (%f%+fi)=%f\n",R1,I1,suan,R2,I2,R);
	if(fabs(R-0)<1e-6&&(fabs(I-0)<1e-6))
		printf("(%f%+fi) %c (%f%+fi)=0\n",R1,I1,suan,R2,I2);
	if(!(fabs(R-0)<1e-6)&&!(fabs(I-0)<1e-6))
		printf("(%f%+fi) %c (%f%+fi)=%f%+fi\n",R1,I1,suan,R2,I2,R,I);
	zhijiao_to_ji();
	printf("=%f(%f)\n",M,J);

}


void zhijiao_to_ji_main()     //ֱ������ϵ����ת��Ϊ������
{
	printf("������ʵ�����鲿��(�Կո�ָ�)\n");
	scanf("%f%f",&R,&I);
    zhijiao_to_ji();
	
		printf("\n %f%+fi=%f(%f)\n",R,I,M,J);

}


void zhijiao_to_ji()			//ֱ������ϵ����ת��Ϊ����������
{	
	M=sqrt(R*R+I*I);
	J=180/PI*atan2(I,R);
}




	
void ji()
{

	float M1,M2,J1,J2,t1,t2;
	char suan;
    printf("�����룺(ģ��ǶȻ������֮���Կո�ָ�)\n");
	scanf("%f%f %c%f%f",&M1,&J1,&suan,&M2,&J2);
	t1=J1,t2=J2;
	J1=J1*PI/180;
	J2=J2*PI/180;

	switch(suan)
	{
	case '+':
    M=sqrt(M1*M1+M2*M2+2*M1*M2*cos(J1-J2));
	J=atan2((M1*sin(J1)+M2*sin(J2)),(M1*cos(J1)+M2*cos(J2)));
	break;

	case '-':
	M=sqrt(M1*M1+M2*M2-2*M1*M2*cos(J1-J2));
	J=atan2((M1*sin(J1)-M2*sin(J2)),(M1*cos(J1)-M2*cos(J2)));
	break;

	case '*':
	M=M1*M2;
	J=J1+J2;
	break;

	case '/':
	M=M1/M2;
	J=J1-J2;
	break;
	}
	J=180/PI*J;
	J1=t1,J2=t2;     //J,J1,J2�Զ������

	printf("%f(%f) %c %f(%f)=%f(%f)\n",M1,J1,suan,M2,J2,M,J);

	J=J*PI/180;
	ji_to_zhijiao();
	if(fabs(R-0)<1e-6&&!(fabs(I-0)<1e-6))
		printf(" =%fi\n",I);
	if(fabs(I-0)<1e-6&&!(fabs(R-0)<1e-6))
		printf(" =%f\n",R);
	if(fabs(R-0)<1e-6&&(fabs(I-0)<1e-6))
		printf(" =0\n");
	if(!(fabs(R-0)<1e-6)&&!(fabs(I-0)<1e-6))
		printf(" =%f%+fi\n",R,I);

}

void ji_to_zhijiao_main()
{   
	float t;
	printf("������ģ�ͽǶȣ�(�Կո�ָ�)\n");
	scanf("%f%f",&M,&J);
    t=J;
	J=J*PI/180;
	ji_to_zhijiao();
	J=t;		//���Զ������

	if(fabs(R-0)<1e-6&&!(fabs(I-0)<1e-6))
		printf(" %f(%f)=%fi\n",M,J,I);
	if(fabs(I-0)<1e-6&&!(fabs(R-0)<1e-6))
		printf(" %f(%f)=%f\n",M,J,R);
	if(fabs(R-0)<1e-6&&(fabs(I-0)<1e-6))
		printf(" %f(%f)=0\n",M,J);
	if(!(fabs(R-0)<1e-6)&&!(fabs(I-0)<1e-6))
		printf(" %f(%f)=%f%+fi\n",M,J,R,I);
}


void ji_to_zhijiao()
{
	R=M*cos(J);
	I=M*sin(J);
}

