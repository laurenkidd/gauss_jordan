#include<stdio.h>
#include<math.h>
int main()
{

	/* Program to solve matrix eqn using Gauus-Jordan. Pivoting assumed to be wanted by user.*/
    	int i, n, pivot; //size of matrix to be Gauss-Jordan'd
    	float x[3];
    	
    
    
    	printf("\nGlen - I commented out the part where the user can define the matrix with scanf; uncomment if you want to test it.");
	pivot = 1;
	float A[3][3] = {{2,1,2},{3,1,0},{-1,0,1}};
	float b[3] = {6,11,-2};
	n = 3;

	//////////////////////////////////////////////////////////////////
    	/* Uncomment this section to allow user to define matrix in terminal 
         float A[20][20], b[10], x[20]; //define matix of more indices than will likely ever be used in the problem
   	 printf("\nEnter size of matrix: ");
   	 scanf("%d",&n);
   	 printf("\nEnter elements of matrix A by row (one element at a time):\n");
   	 for(i=0; i<n; i++)
   	 {
      	    for(int j=0; j<n; j++)
       	    {
           	 printf(" A[%d][%d]:", i,j);
           	 scanf("%f",&A[i][j]);
            }	
   	 }
   	 printf("\nEnter elements of vector b (one element at a time):\n");
    	for(i=0; i<n; i++)
    	{
            printf(" b[%d]:", i);
            scanf("%f",&b[i]);
    	}
    	//see if user wants pivoting    	
    	 printf(" Do you want pivoting? (1 = yes, 0 = no)");
    	 scanf("%d",&pivot);
        */
	/////////////////////////////////////////////////////////////////
	

   
    //combine matrix A and vector b so all operations will be done to both
    float Ab[20][20];
    for (int i = 0; i<n; i++){
        for (int j = 0; j< n+1; j++){
            if (j<n){
	        Ab[i][j] = A[i][j];
	    }
	    if (j==n){
	        Ab[i][j] = b[i];
	    }
	}
    }

  //print the matrix prior to sorting
  for (int i=0; i<n; i++){
        for( int j = 0; j<n+1; j++){
	   printf("%f ", Ab[i][j]);
	}
	printf("\n");
    }
    printf("\n");
	
    //if pivot = yes, sort the rows so largest element is at the top
    float temp[n+1];
    if (pivot == 1){
        for (int i = 0; i<n-1; i++){
	    if( fabs(Ab[i][0]) < fabs(Ab[i+1][0])){
		for (int j=0; j<n+1; j++){
	            temp[j] = Ab[i][j];
		    Ab[i][j] = Ab[i+1][j];
		    Ab[i+1][j] = temp[j];
	 	}
            }
            if( fabs(Ab[0][0]) < fabs(Ab[i][0])){
		for (int j=0; j<n+1; j++){
	            temp[j] = Ab[0][j];
		    Ab[0][j] = Ab[i][j];
		    Ab[i][j] = temp[j];
	 	}
	    }
	}
    }
    //print the matrix after sorting
   for (int i=0; i<n; i++){
        for( int j = 0; j<n+1; j++){
	   printf("%f ", Ab[i][j]);
	}
	printf("\n");
    }
    printf("\n");

   
    //separate the matrix again
    for (int i = 0; i<n; i++){
        for (int j = 0; j< n+1; j++){
            if (j<n){
	        A[i][j] = Ab[i][j];
	    }
	    if (j==n){
	        b[i] = Ab[i][j];
	    }
	}
    }

    //do the Gauss-Jordan
    int  j, m;
    double temp2;
    for(i=0;i<(n-1);i++){
        for(j=(i+1);j<n;j++){
		//ratio term to make lowe diagonal elements zero
                double xmult = A[j][i] / A[i][i];
                for(m=i;m<n;m++) {
			//subtract the stuff off from A
                        A[j][m] = A[j][m] - (xmult * A[i][m]);
                }
		//subtract the stuff off from b
                b[j] = b[j]- (xmult * b[i]);
        }
    }
    for (i=0;i<=n-1;i++){
        for(j=0;j<n;j++){
                printf("%lf ",A[i][j]);
        }
	printf ("%f", b[i]);
        printf("\n");
    }

    // Do back substitution to solve for x
    x[n-1] = b[n-1] / A[n-1][n-1];
    for(i=(n-2);i>=0;i--){
        temp2 = b[i];
        for(j=(i+1);j<n;j++){
                temp2 = temp2 - (A[i][j] * x[j]);
        }
        x[i] = temp2 / A[i][i];
    }
    
    //print it
    printf("Answer:\n");
    for(i=0;i<n;i++){
        printf("x%d = %lf\n",i,x[i]);
    }

   
    /*printf("x1 = %f\n", x1);
    printf("x2 = %f\n", x2);
    printf("x3 = %f\n", x3);*/
   
    return(0);
}

