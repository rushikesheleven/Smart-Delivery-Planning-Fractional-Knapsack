#include<stdio.h>

int main()
{
    float p[100], w[100], pw[100], total;
    float selected[100], sw[100];
    int i, n, j, temp, cap, c = 0;
    int choice, id[100];

    do
    {
        printf("\n\n");
        printf("1. Enter Package Details\n");
        printf("2. Display Package Details\n");
        printf("3. Calculate Value/Weight Ratio\n");
        printf("4. Sort Packages by Ratio\n");
        printf("5. Find Maximum Value\n");
        printf("6. Display Selected Packages\n");
        printf("7. Exit\n");

        printf("\nEnter choice : ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:

                printf("enter number of objects ");
                scanf("%d", &n);

                for(i=0;i<n;i++)
                {
                    id[i] = i+1;

                    printf("enter weight of object %d ",i+1);
                    scanf("%f",&w[i]);

                    printf("enter profit of object %d ",i+1);
                    scanf("%f",&p[i]);

                    pw[i] = 0;
                }

                printf("enter capacity ");
                scanf("%d",&cap);

                printf("\nvalues entered\n");

                for(i=0;i<n;i++)
                {
                    printf("object %d , profit = %f , weight = %f\n",
                           id[i],p[i],w[i]);
                }

                break;


            case 2:

                printf("\nPackage Details\n");

                for(i=0;i<n;i++)
                {
                    printf("object %d , profit = %f , weight = %f , p/w = %f\n",
                           id[i],p[i],w[i],pw[i]);
                }

                break;


            case 3:

                for(j=0;j<n;j++)
                {
                    pw[j] = p[j]/w[j];

                    printf("p/w of object %d = %f\n",
                           id[j],pw[j]);
                }

                break;


            case 4:

                /*
                   Sorting packages according to decreasing
                   value/weight ratio
                */

                for(i=0;i<n;i++)
                {
                    for(j=0;j<n;j++)
                    {
                        if(pw[i]>pw[j])
                        {
                            /* swap ratio */
                            {
                                float tempf;

                                tempf = pw[i];
                                pw[i] = pw[j];
                                pw[j] = tempf;

                                /* swap profit */
                                tempf = p[i];
                                p[i] = p[j];
                                p[j] = tempf;

                                /* swap weight */
                                tempf = w[i];
                                w[i] = w[j];
                                w[j] = tempf;

                                /* swap object number */
                                temp = id[i];
                                id[i] = id[j];
                                id[j] = temp;
                            }
                        }
                    }
                }

                printf("\n sorted table \n");

                for(i=0;i<n;i++)
                {
                    printf("object %d , p/w = %f , profit = %f , weight = %f\n",
                           id[i],pw[i],p[i],w[i]);
                }

                break;


            case 5:

                /*
                   Calculate ratio and sort first.
                   This makes option 5 work even if the
                   user does not select options 3 and 4.
                */

                for(i=0;i<n;i++)
                {
                    pw[i] = p[i]/w[i];
                }

                for(i=0;i<n;i++)
                {
                    for(j=0;j<n;j++)
                    {
                        if(pw[i]>pw[j])
                        {
                            float tempf;

                            tempf = pw[i];
                            pw[i] = pw[j];
                            pw[j] = tempf;

                            tempf = p[i];
                            p[i] = p[j];
                            p[j] = tempf;

                            tempf = w[i];
                            w[i] = w[j];
                            w[j] = tempf;

                            temp = id[i];
                            id[i] = id[j];
                            id[j] = temp;
                        }
                    }
                }

                total = 0;
                c = 0;

                for(i=0;i<n;i++)
                {
                    selected[i] = 0;
                    sw[i] = 0;
                }

                /*
                   Fractional Knapsack
                */

                for(i=0;i<n;i++)
                {
                    if(w[i] <= cap)
                    {
                        /*
                           Complete package
                        */

                        cap = cap - w[i];

                        total = total + p[i];

                        selected[i] = 1;
                        sw[i] = w[i];
                    }
                    else
                    {
                        /*
                           Fraction of package
                        */

                        selected[i] = (float)cap/w[i];

                        sw[i] = cap;

                        total = total + (pw[i] * cap);

                        cap = 0;

                        break;
                    }
                }

                printf("\nMaximum value = %f\n",total);

                break;


            case 6:

                printf("\nSelected Packages\n");

                printf("\nObject\tP/W\tFraction\tWeight\tProfit\n");

                for(i=0;i<n;i++)
                {
                    if(selected[i] > 0)
                    {
                        printf("%d\t%f\t%f\t%f\t%f\n",
                               id[i],
                               pw[i],
                               selected[i],
                               sw[i],
                               pw[i]*sw[i]);
                    }
                }

                break;


            case 7:

                printf("\nProgram ended.\n");

                break;


            default:

                printf("\nInvalid choice\n");
        }

    }while(choice != 7);

    return 0;
}