//�ļ���:excise1.cpp
#include <stdio.h>
#define MaxSize 100
typedef struct node
{
	int no;            	//ְ����
	char name[10];    	//����
	int depno;         	//���ź�
	float salary;       //������
	int pno;           	//ְ����ָ��
	int pdepno;         //���ź�ָ��
	int psalary;        //������ָ��
} EmpType;				//ְ������
void DelAll(EmpType emp[],int &n)	//���ְ���ļ�ȫ����¼
{
	FILE *fp;
	if ((fp=fopen("emp.dat","wb"))==NULL) 
	{	
		printf("���ܴ�ְ���ļ�\n");
		return;
	}
	emp[0].pno=emp[0].pdepno=emp[0].psalary=-1;	//��ʼ��
	n=0;
	fclose(fp);
}
void ReadFile(EmpType emp[],int &n) //�������ļ�����emp������
{
	FILE *fp;
	long len;
	int i;
	if ((fp=fopen("emp.dat","rb"))==NULL) 
	{	
		n=0;
		return;
	}
	fseek(fp,0,2);				//�ļ�λ��ָ���Ƶ��ļ�β
	len=ftell(fp);    			//len����ļ�����
	rewind(fp);					//�ļ�λ��ָ���Ƶ��ļ���
	n=len/sizeof(EmpType); 		//n����ļ��еļ�¼����
	if (n!=0)
		n--;					//n������Ԫ��
	else	//n=0ʱ
		emp[0].pno=emp[0].pdepno=emp[0].psalary=-1;	//��ʼ��
	for (i=0;i<=n;i++)
		fread(&emp[i],sizeof(EmpType),1,fp);//���ļ��е����ݶ���emp��
	fclose(fp);
}
void SaveFile(EmpType emp[],int n) //��emp������������ļ�
{
	int i;
	FILE *fp;
	if ((fp=fopen("emp.dat","wb"))==NULL) 
	{	
		printf("  >>�����ļ����ܴ�\n");
		return;
	}
	if (n>1)
		for (i=0;i<=n;i++)
			fwrite(&emp[i],sizeof(EmpType),1,fp);
	fclose(fp);
}
void InputEmp(EmpType emp[],int &n)	//���һ��ְ����¼
{
	printf("  >>����ְ����,����,���ź�,����:");
	n++;
	scanf("%d%s%d%f",&emp[n].no,emp[n].name,&emp[n].depno,&emp[n].salary);
	emp[n].pno=emp[n].pdepno=emp[n].psalary=0;
}
void OutputFile(EmpType emp[],int n)	//���ְ���ļ�ȫ����¼
{
	int i;
	if (n<1)
	{
		printf("  >>û���κμ�¼\n");
		return;
	}
	for (i=1;i<=n;i++)
		printf("  >>%3d %7s %2d %g\n",emp[i].no,emp[i].name,emp[i].depno,emp[i].salary);
}
void Sortno(EmpType emp[],int n) //����ֱ�Ӳ��뷨��emp[1..n]��no������������
{
	int i=2,j;
	if (n<1)	//û�����ݼ�¼ʱ����
	{
		printf("  >>û��ְ����¼,���ܰ�ְ��������\n");
		return;
	}
	emp[0].pno=1;emp[1].pno=-1;	//����ֻ��һ����¼�������
	while (i<=n)
	{
		j=0;
		while (emp[j].pno!=-1 && emp[emp[j].pno].no<emp[i].no)
			j=emp[j].pno;		//�ҵ�һ��λ��j,��������emp[i]
		emp[i].pno=emp[j].pno;	//��emp[i]���뵽emp[j]֮��
		emp[j].pno=i;
		i++;					//������һ����¼
	}
}
void Dispno(EmpType emp[],int n)	//��pnoָ�������
{
	int i=emp[0].pno;
	if (i==-1)
		printf("  >>��δ��no����\n");
	while (i!=-1)		//��δ�����һ�����ʱ���
	{
		printf("  >>%3d %7s %2d %g\n",emp[i].no,emp[i].name,emp[i].depno,emp[i].salary);
		i=emp[i].pno;	//��pno���ݽ�
	}
}
void Sortdepno(EmpType emp[],int n) //����ֱ�Ӳ��뷨��emp[1..n]��depno������������
{
	int i=2,j;
	if (n<1)	//û�����ݼ�¼ʱ����
	{
		printf("  >>û��ְ����¼,���ܰ�ְ��������\n");
		return;
	}
	emp[0].pdepno=1;emp[1].pdepno=-1;	//����ֻ��һ����¼�������
	while (i<=n)
	{
		j=0;
		while (emp[j].pdepno!=-1 && emp[emp[j].pdepno].depno<emp[i].depno)
			j=emp[j].pdepno;			//�ҵ�һ��λ��j,��������emp[i]
		emp[i].pdepno=emp[j].pdepno;	//��emp[i]���뵽emp[j]֮��
		emp[j].pdepno=i;
		i++;							//������һ����¼
	}
}
void Dispdepno(EmpType emp[],int n)	//��pdepnoָ�������
{
	int i=emp[0].pdepno;
	if (i==-1)
		printf("  >>��δ��depno����\n");
	while (i!=-1)		//��δ�����һ�����ʱ���
	{
		printf("  >>%3d %7s %2d %g\n",emp[i].no,emp[i].name,emp[i].depno,emp[i].salary);
		i=emp[i].pdepno;	//��pdepno���ݽ�
	}
}
void Sortsalary(EmpType emp[],int n) //����ֱ�Ӳ��뷨��emp[1..n]��salary������������
{
	int i=2,j;
	if (n<1)	//û�����ݼ�¼ʱ����
	{
		printf("  >>û��ְ����¼,���ܰ�ְ��������\n");
		return;
	}
	emp[0].psalary=1;emp[1].psalary=-1;	//����ֻ��һ����¼�������
	while (i<=n)
	{
		j=0;
		while (emp[j].psalary!=-1 && emp[emp[j].psalary].salary<emp[i].salary)
			j=emp[j].psalary;	//�ҵ�һ��λ��j,��������emp[i]
		emp[i].psalary=emp[j].psalary;	//��emp[i]���뵽emp[j]֮��
		emp[j].psalary=i;
		i++;					//������һ����¼
	}
}
void Dispsalary(EmpType emp[],int n)	//��psalaryָ�������
{
	int i=emp[0].psalary;
	if (i==-1)
		printf("  >>��δ��salary����\n");
	while (i!=-1)		//��δ�����һ�����ʱ���
	{
		printf("  >>%3d %7s %2d %g\n",emp[i].no,emp[i].name,emp[i].depno,emp[i].salary);
		i=emp[i].psalary;	//��pno���ݽ�
	}
}
void main()
{
	EmpType emp[MaxSize];
	int sel,n;
	ReadFile(emp,n);
	do
	{	
		printf("1:���� 2:��� 3:��no���� 4:��no��� 5:��depno���� 6:��depno���\n");
		printf("7:��salary���� 8.��salary��� 9:ȫ�� 0:�洢�˳�  ��ѡ��:");
		scanf("%d",&sel);
		switch(sel)
		{
		case 9:
			DelAll(emp,n);
			break;
		case 1:
			InputEmp(emp,n);
			break;
		case 2:
			OutputFile(emp,n);
			break;
		case 3:
			Sortno(emp,n);
			break;
		case 4:
			Dispno(emp,n);
			break;
		case 5:
			Sortdepno(emp,n);
			break;
		case 6:
			Dispdepno(emp,n);
			break;
		case 7:
			Sortsalary(emp,n);
			break;
		case 8:
			Dispsalary(emp,n);
			break;
		case 0:
			SaveFile(emp,n);
			break;
		}
	} while (sel!=0);
}
