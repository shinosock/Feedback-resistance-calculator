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
        
        printf("                               72711111111111111111111111111111111111112\n"                                                                              
"                               27                                      6     \n"                                                                       
"                               17                                      9     \n"                                                                      
"                               17                                      6      \n"                                                                      
"                               17                                      9     \n"                                                                       
"                   39271337111767                                      61711132911117777777777777777777777777777\n"                                      
"                               17                                      9                                      71\n"                                      
"                               17                                      6                                       1\n"                                      
"                               17                                      9                                      72\n"                                      
"                               17                                      6                                      72\n"                                      
"                               17                                      6                                      72\n"                                      
"                               17                                      6                                      72\n"                                      
"                               17                                      6                                      79\n"                                      
"                               17                                      6                                   13777719      69696969697      966661\n"      
"                               17                                      9                                   17     9      96   7  7663   1967  796\n"     
"                               17                                      6                                   17     9      69        69   96      92\n"    
"                               17                                      6                                   17     9      96        66          767\n"    
"                               17                                      6                                   17     9      69239321696          769\n"     
"                               17                                      9                                   17     9      661239663           661\n"      
"                               17                                      6                                   17     9      69     162        996\n"        
"                               17                                      9                                   17     9      96      169     769\n"         
"                               17                                      6                                   17     3      69       766   661\n"           
"                               27                                      9                                   11     6      66        166 76969696969\n"    
"                               71171111111111171777317711111111111111111                                   71726717   \n"                                
"                                                   2                                                          71\n"                             
"                                                   9                                                          72\n"                          
"                                                   3                                                          72\n"                       
"                                                   9                                                          72\n"                    
"                                                   9                                                          71                     \n"                 
"                                                   9                                                           1                        \n"              
"                                                   3                                                          71                           \n"           
"                                                   1                                                           1                              \n"        
"                                                  762                                                         71     \n"                                 
"                                                  96997777777777777777777777777777777777777777777777777777777717       \n"                               
"                                                  797                                                                    \n"                             
"                                                   1                                                                       \n"                           
"                                                   3                                                                         \n"                         
"                                                   9                                                                           \n"                       
"                                                   3                                                                             \n"
"                                                   3                                      \n"                                                            
"                                                 779777                                      \n"                                                         
"                                                97 77 97     16696969696         797           \n"                                                       
"                                                9     17     167      7967      3967              \n"                                                    
"                                                9     17     19         96    963197                 \n"                                                 
"                                                6     17     16        261   73  76                     \n"                                              
"                                                9     17     196969699967        797                       \n"                                           
"                                                6     27     1627713697          767                          \n"                                        
"                                                9     17     19      697         797                             \n"                                     
"                                                6     17     167      692        767        \n"                                                          
"                                                9     17     297       663       197          \n"                                                        
"                                                67    67     167        691      767             \n"                                                     
"                                                7776777                                             \n"                                                  
"                                                   3                                                   \n"                                               
"                                                   9                                                      \n"                                            
"                                                   3                                                         \n"                                         
"                                                   9                                                            \n"                                      
"                                                   2                                                               \n"                                   
"                                                   1                                                                  \n"                                
"                                                   2                                                                     \n"                             
"                                                   9                                                                        \n"                          
"                                                   3                                                                           \n"                       
"                                                   9                                                                              \n"                    
"                                                   3                                                                                 \n"                 
"                                           71777777977777771                                                                            \n"              
"                                              7 7       7                                                                                  \n"           
"                                              77777777777                                                                                     \n"        
"                                                7777777                                                                                          \n"     
"                                                   7                                                                                                \n"  );
        for ( i = 0; i < fnum; i++)
        {
            printf("R1 = %.1f, R2 = %.1f, error = %.6f\n", first[i].Ra, first[i].Rb, first[i].error);
        }
        printf("The second method: R1 is connected in parallel with R2 and then in series with R3 where the equivalent resistance of R1 and R2 is grounded\n");
        printf("                               72711111111111111111111111111111111111112\n"                                                                              
"                               27                                      6     \n"                                                                       
"                               17                                      9     \n"                                                                      
"                               17                                      6      \n"                                                                      
"                               17                                      9     \n"                                                                       
"                   39271337111767                                      61711132911117777777777777777777777777777\n"                                      
"                               17                                      9                                      71\n"                                      
"                               17                                      6                                       1\n"                                      
"                               17                                      9                                      72\n"                                      
"                               17                                      6                                      72\n"                                      
"                               17                                      6                                      72\n"                                      
"                               17                                      6                                      72\n"                                      
"                               17                                      6                                      79\n"                                      
"                               17                                      6                                   13777719      69696969697        77    \n"      
"                               17                                      9                                   17     9      96   7  7663     8880807 \n"     
"                               17                                      6                                   17     9      69        69    80    187  \n"    
"                               17                                      6                                   17     9      96        66          787\n"    
"                               17                                      6                                   17     9      69239321696        76087    \n"     
"                               17                                      9                                   17     9      661239663          771887   \n"      
"                               17                                      6                                   17     9      69     162             08    \n"        
"                               17                                      9                                   17     9      96      169    707     80  \n"         
"                               17                                      6                                   17     3      69       766    880777887 \n"           
"                               27                                      9                                   11     6      66        166     28807    \n"    
"                               71171111111111171777317711111111111111111                                   71726717   \n"                                
"                                                   2                                                          71\n"                             
"                                                   9                                                          72\n"                          
"                                                   3                                                          72\n"                       
"                                                   9                                                          72\n"                    
"                                                   9                                                          71                     \n"                 
"                                                   9                                                           1                        \n"              
"                                                   3                                                          71                           \n"           
"                                                   1                                                           1                              \n"        
"                                                  762                                                         71     \n"                                 
"                                                  96997777777777777777777777777777777777777777777777777777777717                                     \n"
"                                                37                                                             27                                     \n"
"                                                1                                                              1                                      \n"
"                                                6                                                              37                                     \n"
"                                                9                                                              37                                     \n"
"                                                6                                                              37                                     \n"
"                                                9                                                              3                                      \n"
"                                                6                                                              67                                     \n"
"                                             67717797      69696969691          76                          97717722      36666696961       769662    \n"
"                                            73     71      9677777716667       769                          6      3      6917771713697    962771967  \n"
"                                             9     71      69         96     19696                          6     73      96         66   66      66  \n"
"                                             3     71      96         69    697 39                          6     72      69         96   77      397 \n"
"                                             3     71      66       7697        96                          9     73      967      7961          796  \n"
"                                            73     71      96969696997          69                          6     72      69696966697           969   \n"
"                                             9     71      69     261           96                          9     73      66     162          1697    \n"
"                                             3     71      96      769          69                          6     72      66      7667      7667      \n"
"                                             9     71      66       769         66                          6     73      96       7967    697        \n"
"                                             3     71      96        7667       66                          6      3      69         967  6967771111  \n"
"                                             67777731      69         766       26                          67777713      36         796 796966696667 \n"
"                                             7776777                                                        7776177                                   \n"
"                                                3                                                              2                                      \n"
"                                                9                                                              37                                     \n"
"                                                3                                                              37                                     \n"
"                                               163                                                             97                                     \n"
"                                              766667777777777777777777777777777777777777777777777777777777777772                                      \n"
"                                               767                                                                                                    \n"
"                                                1                                                                                                     \n"
"                                                9                                                                                                     \n"
"                                                9                                                                                                     \n"
"                                                6                                                                                                     \n"
"                                                9                                                                                                     \n"
"                                                6                                                                                                     \n"
"                                        117777771777777117                                                                                            \n"
"                                           77       77                                                                                                \n"
"                                           777     7777                                                                                               \n"
"                                             7777777                                                                                                  \n"
"                                                7                                                                                                     \n");
        for ( i = 0; i < snum; i++)
        {
            printf("R1 = %.1f, R2 = %.1f, R3 = %.1f, error = %.6f\n", second[i].Ra, second[i].Rb, second[i].Rc, second[i].error);
        }
        printf("The fourth method: connect R1 in parallel with R2, and connect R3 in series with R4 after paralleling the two equivalent resistors where the equivalent resistance of R1 and R2 is grounded\n");
        printf("                        777777777777777777777777777777777777777                                                                                       \n"
"                        8                                     8     7                                                                                 \n"
"                778     5                                     9    7774                                                                               \n"
"                  17    4  7 7  7              777     7 777  9      7                                                                                \n"
"            77  1117   75  8 85 5             0  7127  6 78   6    1827     1887                                                                      \n"
"            1177777 77779  8 5 18             8  7271 71  0   877777 777777 8081 777777777777777777777777777777777777                                 \n"
"                        5  7 7  7              777  777   7   9              77                                     7                                 \n"
"                        4                                     0              7                                     71                                 \n"
"                        4                                     6              27                                    71                                 \n"
"                        9                                     0              17                                    71                                 \n"
"                        4                                     6              1                                     71                                 \n"
"                        4                                     0            776177        777777          77      771077        777777             7   \n"
"                        4               77                    6           97    57     88888088808     8880807  75    76     208088888087        807  \n"
"                        4               7  07                 6           5     77     88        08   80    187 77     5     78        08       8087  \n"
"                        4                  7                  6           5     77     80        80         787 77    75     78        907    78  07  \n"
"                        4              17  7                  6           5     17     087777777807      76087  77    75     781777777881    18   87  \n"
"                        4              8   17                 6           57    17     809468808         771887 77    75     7885608087     98    8   \n"
"                        4                 75                  0           4     17     08     706            08 77    75     78      88    8851114865 \n"
"                        4              7176                   6           5     17     80      788   707     80 77    75     707      087  7711174861 \n"
"                        9               7 1                   0           4     77     08        087  880777887 77     4     287       885        8   \n"
"                        677777777777777777747777777777777777776           11777747     72         55    28807   79777711     72         16        5   \n"
"                                           0                                 47                                    74                                 \n"
"                                           0                                 17                                    71                                 \n"
"                                           0                                 17                                    71                                 \n"
"                                           8                                 27                                    71                                 \n"
"                                    70777  0                                 77                                    77                                 \n"
"                                           8                                 7                                     77                                 \n"
"                                           1                                 7                                     77                                 \n"
"                                           9                                 57                     77             77                                 \n"
"                                         7808777777777777777777777777777777780887777777777777777777880077777777777717                                 \n"
"                                          787                               751                    762                                                \n"
"                                           1                                                        7                                                 \n"
"                                           8                                                        27                                                \n"
"                                           8                                                        5                                                 \n"
"                                           0                                                        1                                                 \n"
"                                           0                                                        07                                                \n"
"                                        0777776      8088808081         78                       21777767     4888880809      788804                  \n"
"                                        6     8      08     7788      7880                       9     17     807   7 7881   081  7887                \n"
"                                        9     0      82        80   780788                       9     17     08        88  787     08                \n"
"                                        6     8      85       887   77  80                       4     17     88       780          80                \n"
"                                        6     0      8080888085         08                       9     17     88080808007         180                 \n"
"                                        6     8      09    281          80                       4     17     80    788         7087                  \n"
"                                        9     0      85      80         88                       4     17     08      887     7807                    \n"
"                                        6     8      00       807       88                       4     17     80       089   087                      \n"
"                                        8     8      80        887      08                       07    97     88        980 6808080808                \n"
"                                        7770777                                                   778777                                              \n"
"                                           6                                                        1                                                 \n"
"                                           4                                                        5                                                 \n"
"                                           8                                                        57                                                \n"
"                                         780877777777777777777777777777777777777777777777777777777770                                                 \n"
"                                          187                                                                                                         \n"
"                                           1                                                                                                          \n"
"                                           0                                                                                                          \n"
"                                           0                                                                                                          \n"
"                                           0                                                                                                          \n"
"                                           0                                                                                                          \n"
"                                   7777777777777777                                                                                                   \n"
"                                      777     777                                                                                                     \n"
"                                        7777777                                                                                                       \n"
"                                          777                                                                                                         \n"
"                                           7                                                                                                          \n");
        for ( i = 0; i < tnum; i++)
        {
            printf("R1 = %.1f , R2 = %.1f, R3 = %.1f, R4 = %.1f, error = %.6f\n", third[i].Ra, third[i].Rb, third[i].Rc, third[i].Rd, third[i].error);
        }
    }
    
}