#include <stdio.h>
#include <stdlib.h>
//ham nhap mang
void nhap_mang(int a[100],int n) {
    printf("\nnhap phan tu mang:\n");
    for (int i=0; i<n; i++) {
        printf("a[%d] = ",i);
        scanf("%d",&a[i]);
    }
}
//ham xuat mang
void xuat_mang(int a[100],int n) {
    printf("\ncac phan tu cua mang la: \n");
    for (int i=0; i<n; i++) {
        printf("%d\t",a[i]);
    }
}
//ham xuat mang 2
void xuat(int a[100],int n) {
    for (int i=0; i<n; i++) {
        printf("%d\t",a[i]);
    }
}
//ham dem phan tu am
int dem_am(int a[100],int n) {
    int dem=0;
    for (int i=0; i<n; i++)
        if (a[i]<0)
            dem++;
    return dem;
}
void dem_ptu_am(int a[100],int n) {
    printf("\nco %d phan tu am trong mang",dem_am(a,n)); //dem phan tu am
}
//ham dem phan tu duong
int dem_duong(int a[100],int n) {
    int dem=0;
    for (int i=0; i<n; i++)
        if (a[i]>0)
            dem++;
    return dem;
}
//ham tim max,min cua mang
void max_min(int a[100],int n) {
    int max=a[0];
    int min=a[0];
    for (int i=1; i<n; i++) {
        if (max<a[i])
            max=a[i];
        if (min>a[i])
            min=a[i];
    }
    printf("\nMax = %d,Min = %d",max,min);
}
//ham tim phan tu am lon nhat, duong be nhat
void tim_so(int a[100],int n) {
    int i,k;
    //tim am lon nhat
    if (dem_am(a,n)!=0) {
        for (i=0; i<n; i++)
            if (a[i]<0)
                break;
        int am=a[i];
        for (int j=0; j<n; j++) {
            if (a[j]<0)
                if (a[j]>am)
                    am=a[j];
        }
        printf("\nso am lon nhat trong mang la: %d",am);
    } else
        printf("\nkhong co phan tu am");
    //tim duong be nhat
    if (dem_duong(a,n)!=0) {
        for (k=0; k<n; k++)
            if (a[k]>0)
                break;
        int duong=a[k];
        for (int j=0; j<n; j++) {
            if (a[j]>0)
                if (a[j]<duong)
                    duong=a[j];
        }
        printf("\nso duong be nhat trong mang la: %d",duong);
    } else
        printf("\nkhong co phan tu duong");

}
//ham kiem tra so nguyen to
int ktsonguyento(int n) {
    if (n>0) {
        int dem = 0;
        for(int i = 2; i <= sqrt(n); i++) {
            if (n%i==0) {
                return 0;
                dem++;
                break;
            }
        }
        if (dem==0||n==2||n==3)
            return 1;
    } else
        return 0;
}
//ham liet ke so nguyen to
void tim_nguyen_to (int a[100],int n) {
    int dem=0;
    printf("\nso nguyen to la: ");
    for (int i=0; i<n; i++) {
        if (ktsonguyento(a[i])) {
            printf("%d\t",a[i]);
            dem++;
        } else
            continue;
    }
    if (dem==0)
        printf(" khong co ");
}
int dem_nt (int a[100],int n) {
    int dem=0;
    for (int i=0; i<n; i++) {
        if (ktsonguyento(a[i]))
            dem++;
    }
    return dem;
}
//ham liet ke so chinh phuong
void so_chinh_phuong (int a[100], int n) {
    int dem=0;
    printf("\nso chinh phuong la: ");
    for (int i=0; i<n; i++) {
        if (sqrt(a[i])==((float)sqrt(a[i]))) {
            printf("%d\t",a[i]);
            dem++;
        }
    }
    if (dem==0)
        printf(" khong co");
}
//sap xep mang tang dan
void sx_tang(int a[100], int n) {
    for (int i=0; i<n-1; i++)
        for (int j=i+1; j<n; j++) {
            if (a[i]>a[j]) {
                int tg=a[i];
                a[i]=a[j];
                a[j]=tg;
            }
        }
    printf("\nmang tang dan: ");
    xuat(a,n);
}
//sap xep mang giam dan
void sx_giam(int a[100], int n) {
    for (int i=0; i<n-1; i++)
        for (int j=i+1; j<n; j++) {
            if (a[i]<a[j]) {
                int tg=a[i];
                a[i]=a[j];
                a[j]=tg;
            }
        }
    printf("\nmang giam dan: ");
    xuat(a,n);
}
//ham them phan tu vao mang
void them_phan_tu(int a[100],int n) {
    int x,k;
    printf("\nphan tu can them: ");
    scanf("%d",&x);
    do {
        printf("\nvi tri them: ");
        scanf("%d",&k);
        if (k<0||k>n)
            printf("\nvi tri them khong hop le, nhap lai.");
    } while (k<0||k>n);
    int b[n];
    int *p_a;
    int *p_b;
    p_a = &a[0];
    p_b = &b[0];
    memcpy( p_b, p_a, sizeof(int)*n );
    for (int i=k-1; i<n; i++) {
        a[i+1]=b[i];
    }
    a[k-1]=x;
    printf("\nmang sau khi them: ");
    xuat(a,n+1);
}
//ham xoa phan tu trong mang theo gia tri
void xoa_phan_tu_gt(int a[100],int n) {
    int x;
    printf("\nphan tu can xoa: ");
    scanf("%d",&x);
    int b[n];
    int *p_a;
    int *p_b;
    p_a = &a[0];
    p_b = &b[0];
    memcpy( p_b, p_a, sizeof(int)*n );
    for (int i=0; i<n; i++) {
        if (a[i]==x) {
            if (i==(n-1)) {
                n--;
                break;
            } else {
                for (int j=i; j<n-1; j++)
                    a[j]=b[j+1];
                n--;
                memcpy( p_b, p_a, sizeof(int)*n );
                i--;
            }
        }
    }
    printf("\nmang sau khi xoa: ");
    xuat(a,n);
}
//ham xoa phan tu mang theo vi tri
void xoa_phan_tu_vt(int a[100],int n) {
    int k;
    do {
        printf("\nvi tri xoa: ");
        scanf("%d",&k);
        if (k<0||k>n)
            printf("\nvi tri xoa khong hop le, nhap lai.");
    } while (k<0||k>n);
    int b[n];
    int *p_a;
    int *p_b;
    p_a = &a[0];
    p_b = &b[0];
    memcpy( p_b, p_a, sizeof(int)*n );
    for (int i=k-1; i<n; i++) {
        a[i]=b[i+1];
    }
    printf("\nmang sau khi xoa: ");
    xuat(a,n-1);
}
//ham sua phan tu theo gia tri
void sua_gt (int a[100],int n) {
    int x,y;
    printf("\nnhap phan tu can sua: ");
    scanf("%d",&x);
    printf("\nnhap gia tri can thay doi: ");
    scanf("%d",&y);
    for (int i=0; i<n; i++) {
        if (a[i]==x)
            a[i]=y;
    }
    printf("\nmang sau khi thay doi la: ");
    xuat(a,n);
}
//ham sua phan tu theo vi tri
void sua_vt (int a[100],int n) {
    int x,y;
    do {
        printf("\nnhap vi tri can sua: ");
        scanf("%d",&x);
        if (x<0||x>n)
            printf("\nvi tri sua khong hop le, nhap lai.");
    } while (x<0||x>n);
    printf("\nnhap gia tri can thay doi: ");
    scanf("%d",&y);
    a[x]=y;
    printf("\nmang sau khi thay doi la: ");
    xuat(a,n);
}
void tach (int a[100],int n) {
    int *b= (int*)malloc(dem_nt(a,n)*sizeof(b));
    int *c= (int*)malloc((n-dem_nt(a,n))*sizeof(c));
    int m=0,k=0;
    for (int i=0; i<n; i++) {
        if (ktsonguyento(a[i]))
            b[m++]=a[i];
    }
    printf("\nMang b: ");
    for (int i=0; i<m; i++) {
        printf("%d\t",b[i]);
    }
    for (int j=0; j<n; j++) {
        if (ktsonguyento(a[j])==0)
            c[k++]=a[j];
    }
    printf("\nMang c: ");
    for (int j=0; j<k; j++) {
        printf("%d\t",c[j]);
    }
}
main() {
    int a[100],n;
    printf("nhap mang:");
    do {
        printf("\nnhap n = ");
        scanf("%d",&n);
        if (n>=100)
            printf("\nso phan tu nho hon 100\n");
    } while (n>=100);
    nhap_mang(a,n); //nhap mang
    int h=n;
    int bb[n];
    int *p_aa;
    int *p_bb;
    p_aa = &a[0];
    p_bb = &bb[0];
    memcpy( p_bb, p_aa, sizeof(int)*n );
tiep:
    printf("\nMenu");
    printf("\n1. Xuat Mang");
    printf("\n2. Tim So Am Lon Nhat, So Duong Nho Nhat");
    printf("\n3. Dem Phan Tu Am");
    printf("\n4. Tim Phan Tu Max, Min");
    printf("\n5. Liet Ke So Nguyen To");
    printf("\n6. Liet Ke So Chinh Phuong");
    printf("\n7. Sap Xep Mang Tang Dan");
    printf("\n8. Sap Xep Mang Giam Dan");
    printf("\n9. Them, Xoa, Sua Phan Tu");
    printf("\n10. Tach Mang So Nguyen To");
    printf("\n0. Thoat");
    int lua_chon;
    printf("\nLua Chon: ");
    scanf("%d",&lua_chon);
    switch (lua_chon) {
    case 1:
        xuat_mang(bb,h); //xuat mang
        break;
    case 2:
        tim_so(bb,h); //tim so am lon nhat, so duong be nhat
        break;
    case 3:
        dem_ptu_am(bb,h); //dem phan tu am
        break;
    case 4:
        max_min(bb,h); //tim phan tu max, min
        break;
    case 5:
        tim_nguyen_to(bb,h); //liet ke so nguyen to trong mang
        break;
    case 6:
        so_chinh_phuong(bb,h); //liet ke so chinh phuong
        break;
    case 7:
        sx_tang(bb,h); //sap xem mang tang dan
        break;
    case 8:
        sx_giam(bb,h); //sap xem mang giam dan
        break;
    case 9:
        printf("\nMenu: Them, Sua, Xoa");
        printf("\n1. Them");
        printf("\n2. Xoa");
        printf("\n3. Sua");
        printf("\n0. Thoat");
        int lc;
        printf("\nLua Chon: ");
        scanf("%d",&lc);
        switch (lc) {
        case 1:
            them_phan_tu(bb,h); //them phan tu
            break;
        case 2:
            printf("\n1. Xoa Phan Tu Theo Gia Tri");
            printf("\n2. Xoa Phan Tu Theo Vi Tri");
            printf("\nLua Chon: ");
            int xoa;
            scanf("%d",&xoa);
            switch (xoa) {
            case 1:
                xoa_phan_tu_gt(bb,h); //Xoa Phan Tu Theo Gia Tri
                break;
            case 2:
                xoa_phan_tu_vt(bb,h); //Xoa Phan Tu Theo Vi Tri
                break;
            default:
                break;
            }
            break;
        case 3:
            printf("\n1. Sua Phan Tu Theo Gia Tri");
            printf("\n2. Sua Phan Tu Theo Vi Tri");
            printf("\nLua Chon: ");
            int sua;
            scanf("%d",&sua);
            switch (sua) {
            case 1:
                sua_gt(bb,h); //Sua Phan Tu Theo Gia Tri
                break;
            case 2:
                sua_vt(bb,h); //Sua Phan Tu Theo Vi Tri
                break;
            default:
                break;
            }
        default:
            break;
        }
    case 10:
        tach(a,n);
        break;
    default:
        break;
    }
    printf("\nBan Co Muon Thuc Hien Tiep: ");
    printf("\n1. Co");
    printf("\n2. Khong");
    printf("\nLua Chon: ");
    int lc_tiep;
    scanf("%d",&lc_tiep);
    if (lc_tiep==1)
        goto tiep;
    getch();
}
