//�ļ���:exp12_1.cpp
#include <stdio.h>
#include <string.h>
#include <malloc.h>
#define MaxRec 100  		//���ļ�¼����
typedef struct Index 		//���������ļ��ṹ
{
	char num[8];			//ѧ��
	long offset;			//���ļ��еļ�¼��
} Index;
typedef struct sdata     	//�������ļ��ṹ
{
    char num[8];			//ѧ��
	char name[10];			//����
	int sex;				//�Ա�
	int age;				//����
	char addr[30];			//��ַ
	char dep[20];			//ϵ��
	char spec[20];			//רҵ
} Student;
void DelAll()	//������ļ��������ļ�ȫ����¼
{
	FILE *mfile,*idxfile;
	if ((mfile=fopen("main.dat","wb"))==NULL) 
	{
	    printf("  >>���ܴ����ļ�\n");
		return;
	}
	if ((idxfile=fopen("index.dat","wb"))==NULL) 
	{
	    printf("  >>���ܽ��������ļ�\n");
		return;
	}
	fclose(mfile);
	fclose(idxfile);
}
void InsertSort(Index R[],int n) //��R[0..n-1]�������������ֱ�Ӳ�������
{
	int i,j;
	Index temp;
	for (i=1;i<n;i++) 
	{
		temp=R[i];
		j=i-1; 
		while (j>=0 && strcmp(temp.num,R[j].num)<0) 
		{ 	
			R[j+1]=R[j];	//���ؼ��ִ���R[i].key�ļ�¼����
			j--;
		}
		R[j+1]=temp;		//��j+1������R[i]
	}
}
void CreatIdxFile()	//���������ļ�
{
	FILE *mfile,*idxfile;
	Index idx[MaxRec];
	Student st;
	int n=0,i;
	if ((mfile=fopen("main.dat","rb"))==NULL) 
	{
	    printf("  >>���ܴ����ļ�\n");
		return;
	}
	if ((idxfile=fopen("index.dat","wb"))==NULL) 
	{
	    printf("  >>���ܽ��������ļ�\n");
		return;
	}
	i=0;
   	while ((fread(&st,sizeof(Student),1,mfile))!=NULL)
	{
		strcpy(idx[i].num,st.num);
		idx[i].offset=++n;
		i++;
	}
	InsertSort(idx,n);	//��idx���鰴no��ֵ����
	rewind(idxfile);
	for (i=0;i<n;i++)
		fwrite(&idx[i],sizeof(Index),1,idxfile);
	fclose(mfile);
	fclose(idxfile);
}
void InputMainFile()	//���һ�����ļ���¼
{
	FILE *mfile;
	Student st;
	mfile=fopen("main.dat","ab+");
	if (mfile==NULL)
	{
		printf("  >>���ܽ������ļ�\n");
		return;
	}
	printf("  >>ѧ��,����,�Ա�,����,��ַ,ϵ��,רҵ:");
	scanf("%s%s%d%d%s%s%s",st.num,st.name,&st.sex,&st.age,st.addr,st.dep,st.spec);
	if (fwrite(&st,sizeof(Student),1,mfile)!=1)
	{
		printf("  >>д���ļ�����\n");
		return;
	}
	fclose(mfile);
}
void OutputMainFile()	//������ļ�ȫ����¼
{
 	FILE *mfile;
	Student st;
	int i=0;
	mfile=fopen("main.dat","rb");
	if (mfile==NULL)
	{
		printf("  >>���ܶ����ļ�\n");
		return;
	}
   	while ((fread(&st,sizeof(Student),1,mfile))!=NULL)
	{
		printf("  >>��¼��%d:",++i);
		printf("%s %s %d %d %s %s %s\n",st.num,st.name,st.sex,st.age,st.addr,st.dep,st.spec);
	}
	fclose(mfile);
}
void OutputIdxFile()	//��������ļ�ȫ����¼
{
 	FILE *idxfile;
	Index irec;
	int i=0;
	idxfile=fopen("index.dat","rb");
	if (idxfile==NULL)
	{
		printf("  >>���ܶ������ļ�\n");
		return;
	}
   	while ((fread(&irec,sizeof(Index),1,idxfile))!=NULL)
		printf("  >>(ѧ��:��¼��) %s:%d\n",irec.num,irec.offset);
	fclose(idxfile);
}
void ReadIndexFile(Index idx[MaxRec],int &len)	//�������ļ����ݴ���idx������
{
	int j;
	FILE *idxfile;
	if ((idxfile=fopen("index.dat","rb"))==NULL) 
	{
	    printf("  >>�����ļ����ܴ�\n");
		return;
	}
	fseek(idxfile,0,2); 
	j=ftell(idxfile);    	//j����ļ�����
	rewind(idxfile);
	len=j/sizeof(Index); 	//len����ļ��еļ�¼����
	fread(idx,sizeof(Index),len,idxfile);
	fclose(idxfile);
}
int SearchNum(Index idx[],int len,char no[])	//�������ļ��в���no��Ӧ�ļ�¼��
{
	int mid,low,high,comp;
	low=0;high=len-1;
	while (low<=high)    	//���ֲ���
	{
		mid=(low+high)/2;
		comp=strcmp(idx[mid].num,no);
		if (comp>0) 
			high=mid-1;
		else if (comp<0) 
			low=mid+1;
		else				//comp=0�����
			return idx[mid].offset;
	}
	return -1;
}
void FindStudent() //���ָ��ѧ�ŵļ�¼
{
	char no[8];
	FILE *mfile;
	Index idx[MaxRec];
	Student st;
	int i,len;
	mfile=fopen("main.dat","rb+");
	if (mfile==NULL)
	{
		printf("  >>���ļ���û���κμ�¼\n");
		return;
	}
	ReadIndexFile(idx,len);		//��ȡ��������idx
	printf("����ѧ��:");	
	scanf("%s",no);		
	i=SearchNum(idx,len,no);	//��idx�в���
	if (i==-1)
		printf("  >>ѧ��%s������\n",no);
	else 
	{
		fseek(mfile,(i-1)*sizeof(Student),SEEK_SET); //�����ֱ���������ļ��������¼
		fread(&st,sizeof(Student),1,mfile);
		printf("  >>%s %s %d %d %s %s %s\n",st.num,st.name,st.sex,st.age,st.addr,st.dep,st.spec);
	}
	fclose(mfile);
}
void main()
{
	int sel;
	do
	{
		printf("1:���� 2:������ļ� 3:��������ļ� 4:��ѧ�Ų��� 9:ȫ�� 0:�˳�:");
		scanf("%d",&sel);
		switch(sel)
		{
		case 9:
			DelAll();
			break;
		case 1:
			InputMainFile();
			CreatIdxFile();	//ͬ���޸������ļ�
			break;
		case 2:
			OutputMainFile();
			break;
		case 3:
			OutputIdxFile();
			break;
		case 4:
			FindStudent();
			break;
		}
	} while (sel!=0);
}
