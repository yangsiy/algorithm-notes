class Solution {
public:
    int ans1, ans2;

    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        ans1=(m+n+1)/2;
        ans2=(m+n+1)/2;
        if ((m+n)%2==0)
        {
            ans2++;
        }
        double res=sol(A, 0, m-1, B, 0, n-1);
        return res;
    }
    
    double sol(int a[], int sta, int eta, int b[], int stb, int etb)
    {
        if (sta>eta) return (b[stb+ans1-1]+b[stb+ans2-1])/2.0;
        if (stb>etb) return (a[sta+ans1-1]+a[sta+ans2-1])/2.0;
        if (eta-sta+1+etb-stb+1<=4)
        {
            int tmp[5],k=0;
            for (int i=sta; i<=eta; i++)
            {
                tmp[++k]=a[i];
            }
            for (int i=stb; i<=etb; i++)
            {
                tmp[++k]=b[i];
            }
            sort(tmp+1,tmp+k+1);
            return (tmp[ans1]+tmp[ans2])/2.0;
        }
        int mida=(sta+eta)/2;
        int midb=(stb+etb)/2;
        int posa=bisearch(a, sta, eta, b[midb]);
        int posb=bisearch(b, stb, etb, a[mida]);
        if (mida>posa) swap(mida, posa);
        if (midb>posb) swap(midb, posb);
        
        int num=mida-sta+midb-stb;
        if (ans1<=num&&ans2<=num)
        {
            return sol(a, sta, mida-1, b, stb, midb-1);
        }
        if (ans1<=num&&ans2>num)
        {
            int t1=getMax(a, mida-1, sta, b, midb-1, stb);
            int t2=getMin(a, mida, eta, b, midb, etb);
            return (t1+t2)/2.0;
        }
        
        num+=posa-mida+1+posb-midb+1;
        if (ans1<=num&&ans2<=num)
        {
            ans1-=mida-sta+midb-stb;
            ans2-=mida-sta+midb-stb;
            return sol(a, mida, posa, b, midb, posb);
        }
        if (ans1<=num&&ans2>num)
        {
            int t1=getMax(a, posa, sta, b, posb, stb);
            int t2=getMin(a, posa+1, eta, b, posb+1, etb);
            return (t1+t2)/2.0;
        }
        
        ans1-=posa-sta+1+posb-stb+1;
        ans2-=posa-sta+1+posb-stb+1;
        return sol(a, posa+1, eta, b, posb+1, etb);
    }
    
    int getMax(int a[], int ia, int sta, int b[], int ib, int stb)
    {
        if (ia<sta) return b[ib];
        if (ib<stb) return a[ia];
        if (a[ia]>b[ib]) return a[ia];
        else return b[ib];
    }
    
    int getMin(int a[], int ia, int eta, int b[], int ib, int etb)
    {
        if (ia>eta) return b[ib];
        if (ib>etb) return a[ia];
        if (a[ia]<b[ib]) return a[ia];
        else return b[ib];
    }
    
    int bisearch(int a[], int st, int et, int x)
    {
        int i=st, j=et, mid;
        while (i<=j)
        {
            mid=(i+j)/2;
            if (a[mid]==x) return mid;
            if (x<a[mid]) j=mid-1;
            else i=mid+1;
        }
        if (j<(st+et)/2) return i;
        return j;
    }
};