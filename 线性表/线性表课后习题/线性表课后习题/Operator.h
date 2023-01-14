#ifndef _OPERATOR_H_
#define _OPERATOR_H_
typedef struct Listz
{
	int i;
	struct Listz*next;
}Listz;
//˫������
typedef struct Dlistz
{
	int i;
	struct Dlistz*next;
	struct Dlistz*prior;
}Dlistz;
Listz*Listz_Init();//��ʼ��
Dlistz*Dlistz_Init();//˫�������ʼ��
void Listz_Create(Listz*list);//�ǵݼ���������
void Listz_NosortCreate(Listz*list);//�����򴴽�����
void DListz_NosortCreate(Dlistz*dlist);//�����򴴽�����
void Listz_Show(Listz*list);//չʾ���
void Dlistz_Show(Dlistz*dlist);//˫��չʾ���
void Listz_Integrate(Listz*LA, Listz*LB);//�ϲ�
Listz*Listz_Inverted(Listz*LA);//��Ϊ�ǵ���
void Listz_Intersection(Listz*LA, Listz*LB);//�󽻼�
int Listz_DifSet(Listz*LA, Listz*LB);//��
void Listz_Division(Listz*LA, Listz*LB, Listz*LC);//��������
Listz*Listz_FindMax(Listz*LA);//�������
Listz* Listz_revolve(Listz*LA);//��㷴��
void Listz_Secdel(Listz*LA,int mink,int maxk);//����ɾ��
void Dlistz_change(Dlistz*dlist);//����˫����
void Listz_SingleDel(Listz*list, int item);//ɾ����������ֵΪitem�Ľ��
#endif