#include <stdio.h>
struct student    //����ṹ��
{
    int a;
    int b;
    int c;
};
int main()
{
    int n;
    struct student stu[1000];  //�����㹻��Ŀռ�
    scanf("%d",&n);
    for(int i=0; i<n; i++)      //��������
    {
        scanf("%d %d %d",&stu[i].a,&stu[i].b,&stu[i].c);
    }
    for(int i=0; i<n; i++)
    {
        if(stu[i].b+stu[i].c>140&&stu[i].b*7+stu[i].c*3>=800)    //�ж�����
        {
            printf("Excellent\n");
        }
        else printf("Not excellent\n");
    }
    return 0;

}
