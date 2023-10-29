#include <stdio.h>
struct student    //定义结构体
{
    int a;
    int b;
    int c;
};
int main()
{
    int n;
    struct student stu[1000];  //定义足够大的空间
    scanf("%d",&n);
    for(int i=0; i<n; i++)      //输入数据
    {
        scanf("%d %d %d",&stu[i].a,&stu[i].b,&stu[i].c);
    }
    for(int i=0; i<n; i++)
    {
        if(stu[i].b+stu[i].c>140&&stu[i].b*7+stu[i].c*3>=800)    //判断条件
        {
            printf("Excellent\n");
        }
        else printf("Not excellent\n");
    }
    return 0;

}
