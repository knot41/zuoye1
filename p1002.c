#include<stdio.h>
int main()
{
    int x,y,m,n;
    scanf("%d%d%d%d",&x,&y,&m,&n);
    int a[21][21];     //��ΪA�ڣ�0,0��,B���޿�ȡ��20��20����������С�ռ�Ϊ21*21
    for(int i=0; i<=x; i++)
    {
        for(int j=0; j<=y; j++)
        {
            a[i][j]=1;
        }
    }
    a[m][n]=0;            //a���������жϴ˵��Ƿ�ᱻ����ס��0��ʾ���м��ᱻ��ס��1��ʾ���ᱻ��ס
    int m1=m-2;
    int m2=m-1;
    int m3=m+1;
    int m4=m+2;
    int n1=n-2;
    int n2=n-1;
    int n3=n+1;
    int n4=n+2;
    if(m1>=0&&n2>=0) a[m1][n2]=0;   //�˸��ж�����ж������ߵĵط��ڲ��ڶ���ķ�Χ�ڣ�������Ҫ��0
    if(m1>=0&&n3<=y) a[m1][n3]=0;
    if(m2>=0&&n1>=0) a[m2][n1]=0;
    if(m2>=0&&n4<=y) a[m2][n4]=0;
    if(m3<=x&&n1>=0) a[m3][n1]=0;
    if(m3<=x&&n4<=y) a[m3][n4]=0;
    if(m4<=x&&n2>=0) a[m4][n2]=0;
    if(m4<=x&&n3<=y) a[m4][n3]=0;
    double b[21][21];     //�����߷����кܶ��֣��ᳬint��Χ�����Զ���double����
    for(int i=0; i<=x; i++)
    {
        for(int j=0; j<=y; j++)
        {
            b[i][j]=0;    //��ʼ��ÿһ����߷�Ϊ0��
        }
    }
    b[0][0]=1;     //��㵽�����߷�Ϊһ��
    for(int i=0; i<=x; i++)      //���Ƶݹ���߷���һ��һ����ֱ������B��
    {
        for(int j=0; j<=y; j++)
        {
            if(a[i][j]==0) b[i][j]=0;   //����õ�ᱻ��������õ��߷�Ϊ0��
            else
            {
                if(i>0) b[i][j]+=b[i-1][j];  //��û�ﵽ��߽磬�˵����ߵ��Ǹ�����������ߵ��õ㣬���Ըõ���߷�Ӧ��������ǵ���߷�
                if(j>0) b[i][j]+=b[i][j-1];  //��û�ﵽ�ϱ߽磬�˵���ϱߵ��Ǹ�����������ߵ��õ㣬���Ըõ���߷�Ӧ�����ϱ��ǵ���߷�
            }
        }
    }
    printf("%.0f",b[x][y]);   //�����ʽΪ����
}