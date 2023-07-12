#include <stdio.h>
#include <math.h>

int main(void)
{
    float standard[48] = {1, 1.1, 1.2, 1.3, 1.5, 1.6, 1.8,
    2, 2.2, 2.4, 2.7, 3, 3.3, 3.6, 3.9, 4.3, 4.7, 5.1, 5.6, 6.2,
    6.8, 7.5, 8.2, 9.1,10,11,12,13,15,18,20,22,48,27,30,33,36,39,43,47,51,56,62,68,75,82,91};
    float Vref, Vout, Vouttmp, R1, R2, err;
    int i, j, k, l, fnum, snum, tnum;
    typedef struct value
    {
        float Ra;
        float Rb;
        float Rc;
        float Rd;
        float error;
    }value;
    value first[576];
    value second[576];
    value third[576];
    value tmp;
    while (1)
    {
    printf("pleas input Vref, Vout:");
    scanf("%f, %f", &Vref, &Vout);
    fnum = 0;
    snum = 0;
    tnum = 0;
    for(i = 0; i < 48; i++)
    {
        for(j = 0; j<48; j++)
        {
            Vouttmp = Vref*(standard[i] + standard[j])/standard[i];
            Vouttmp = Vout - Vouttmp;
            if (fabs(Vouttmp) < 0.001)
            {
                first[fnum].Ra = standard[i];
                first[fnum].Rb = standard[j];
                first[fnum].error = fabs(Vouttmp); 
                fnum++;
            }
            
            
        }
    }
    
        for(i = 0; i < 48; i++)
         {
            for(j = 0; j<48; j++)
            {
                for(k = 0; k < 48; k++)
                {
                    R1 = standard[i]*standard[j]/(standard[i]+standard[j]);
                    Vouttmp = Vref*(R1 + standard[k])/R1;
                    Vouttmp = Vout - Vouttmp;
                    if (fabs(Vouttmp) < 0.001)
                    {
                        second[snum].Ra = standard[i];
                        second[snum].Rb = standard[j];
                        second[snum].Rc = standard[k];
                        second[snum].error = fabs(Vouttmp);
                        snum++;
                    }
                    
                }
            }     
        }
        
        for(i = 0; i < 48; i++)
         {
            for(j = 0; j<48; j++)
            {
                for(k = 0; k < 48; k++)
                {
                    for(l = 0; l < 48; l++)
                    {
                        R1 = standard[i]*standard[j]/(standard[i]+standard[j]);
                        R2 = standard[k]*standard[l]/(standard[k]+standard[l]);
                        Vouttmp = Vref*(R1 + R2)/R1;
                        Vouttmp = Vout - Vouttmp;
                        if (fabs(Vouttmp) < 0.001)
                        {
                            third[tnum].Ra = standard[i];
                            third[tnum].Rb = standard[j];
                            third[tnum].Rc = standard[k];
                            third[tnum].Rd = standard[l];
                            third[tnum].error = fabs(Vouttmp); 
                            tnum++;
                        }
                        
                    }
                }
            }     
        }
        for (i = 0; i < fnum - 1; i++)
        {
            for (j = 0; j < fnum - 1 - i; j++)
            {
                if (first[j].error < first[j+1].error)
                 {
                    tmp = first[j];
                    first[j] = first[j+1];
                    first[j+1]=tmp;
                 } 
            }
            
        }
        for (i = 0; i < snum - 1; i++)
        {
            for (j = 0; j < snum - 1 - i; j++)
            {
                if (second[j].error > second[j+1].error)
                {
                    tmp = second[j];
                    second[j] = second[j+1];
                    second[j+1]=tmp;
                } 
            } 
        }
        for (i = 0; i < tnum - 1; i++)
        {
            for (j = 0; j < tnum - 1 - i; j++)
            {
                if (third[j].error > third[j+1].error)
                {
                    tmp = third[j];
                    third[j] = third[j+1];
                    third[j+1]=tmp;
                } 
            }
            
        }
        
        printf("The first method: connect R1 in series with R2 where R1 is grounded\n");
        for ( i = 0; i < fnum; i++)
        {
            printf("R1 = %.1f, R2 = %.1f, error = %.6f\n", first[i].Ra, first[i].Rb, first[i].error);
        }
        printf("The second method: R1 is connected in parallel with R2 and then in series with R3 where the equivalent resistance of R1 and R2 is grounded\n");
        for ( i = 0; i < snum; i++)
        {
            printf("R1 = %.1f, R2 = %.1f, R3 = %.1f, error = %.6f\n", second[i].Ra, second[i].Rb, second[i].Rc, second[i].error);
        }
        printf("The fourth method: connect R1 in parallel with R2, and connect R3 in series with R4 after paralleling the two equivalent resistors where the equivalent resistance of R1 and R2 is grounded\n");
        for ( i = 0; i < tnum; i++)
        {
            printf("R1 = %.1f , R2 = %.1f, R3 = %.1f, R4 = %.1f, error = %.6f\n", third[i].Ra, third[i].Rb, third[i].Rc, third[i].Rd, third[i].error);
        }
    }
    
}