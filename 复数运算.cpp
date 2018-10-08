#include <stdio.h>
#include<math.h>
#include<stdlib.h>
float R,I,M,J;		//ʵ�����鲿��ģֵ������

#define PI 3.1415926

void zhijiao(void);				//ֱ������ϵ������
void zhijiao_to_ji(void);		//ֱ������ϵת������
void ji(void);					//������ϵ������
void ji_to_zhijiao(void);		//������ϵתֱ��

main()
{   
	int mode;	//ģʽ
	while(1)	//��ѭ��һֱ����
	{
		R=0,I=0,M=0,J=0;	//����
		printf("\n����:1ֱ����������,2������,3ֱ������ת������,4������תֱ��,5����  ");
		scanf("%d",&mode);	//����ѡ���ģʽ
		switch(mode)
		{
			case 1:zhijiao();		break;
			case 2:ji();			break;
			case 3:zhijiao_to_ji();	break;
			case 4:ji_to_zhijiao();	break;
			case 5:system("cls");	break;
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
	//�����鲿���������,ͬʱʵ��(���鲿)Ϊ0���ʡ��ʵ��(���鲿)
	if(fabs(R-0)<1e-6&&!(fabs(I-0)<1e-6))
		printf("(%f%+fi) %c (%f%+fi)=%fi\n",R1,I1,suan,R2,I2,I);
	if(fabs(I-0)<1e-6&&!(fabs(R-0)<1e-6))
		printf("(%f%+fi) %c (%f%+fi)=%f\n",R1,I1,suan,R2,I2,R);
	if(fabs(R-0)<1e-6&&(fabs(I-0)<1e-6))
		printf("(%f%+fi) %c (%f%+fi)=0\n",R1,I1,suan,R2,I2);
	if(!(fabs(R-0)<1e-6)&&!(fabs(I-0)<1e-6))
		printf("(%f%+fi) %c (%f%+fi)=%f%+fi\n",R1,I1,suan,R2,I2,R,I);
}


void zhijiao_to_ji()     //ֱ������ϵ����ת��Ϊ������
{
	printf("������ʵ�����鲿��(�Կո�ָ�)\n");
	scanf("%f%f",&R,&I);
	M=sqrt(R*R+I*I);		//ģֵ
	J=180/PI*atan2(I,R);	//���Ǽ���ѡ��atan2()����,��֤����ֲ���4������
	printf("\n %f%+fi=%f(%f)\n",R,I,M,J);

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

	//������Ӽ������������Ҷ���
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

void ji_to_zhijiao()
{   
	float t;
	printf("������ģ�ͽǶȣ�(�Կո�ָ�)\n");
	scanf("%f%f",&M,&J);

	t=J*PI/180;	//תΪ����
	R=M*cos(t);
	I=M*sin(t);

	if(fabs(R-0)<1e-6&&!(fabs(I-0)<1e-6))
		printf(" %f(%f)=%fi\n",M,J,I);
	if(fabs(I-0)<1e-6&&!(fabs(R-0)<1e-6))
		printf(" %f(%f)=%f\n",M,J,R);
	if(fabs(R-0)<1e-6&&(fabs(I-0)<1e-6))
		printf(" %f(%f)=0\n",M,J);
	if(!(fabs(R-0)<1e-6)&&!(fabs(I-0)<1e-6))
		printf(" %f(%f)=%f%+fi\n",M,J,R,I);
}


