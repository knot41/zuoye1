#include <stdio.h>
int a[5000000];
int dg(int l,int r,int k)   //���ο��ǵݹ�
{
    int i=l;         //��Ϊð�ݣ�ѡ������ɶ�ĸ��Ӷ�Ϊn��ƽ��������������������
    int j=r;
    int pivot=a[l];       //ѧϰ��һ��Ч�ʸ��ߵĿ�������ȷ��pivot��λ��
    while(i<j)
    {
        while(i<j&&a[j]>pivot)
        {
            j--;
        }
        if(i<j)
        {
            a[i++]=a[j];      //��pivotС���������
        }
        while(i<j&&a[i]<pivot)
        {
            i++;
        }
        if(i<j)
        {
            a[j--]=a[i];    //��pivot��������ұ�
        }

    }
    a[i]=pivot;                  //���ȷ��pivot��λ�ã����±�Ϊi��λ��
    if(k==i) printf("%d",a[k]);    //�����ȫ����ȫ�����ţ��ύ����������һ�����ݳ�ʱ�������Ż������жϵ�ʱpivot�Ƿ�Ϊ��kλ
    else if(k<i)dg(l,i-1,k);    //kС�Ļ�����ֻ��Ҫ��pivot����߽��п���
    else  dg(i+1,r,k);      //k��Ļ���ֻ��Ҫ��pivot���ұ߽��п���
    return 0;
}
int main()
{
    int n;
    int k;
    scanf("%d%d",&n,&k);
    for(int i=0; i<n; i++)
    {
        scanf("%d",&a[i]);
    }
    dg(0,n-1,k);
    return 0;
}
